#include <iostream>
#include <cmath>

#include "Projetcpp2020.h"
#include "functionTab2020.h"
#include "tenseur2_2020.h"
#include "PartieIII_2020.h"


void cppidcolgivens(float *x , float *z , float*c , float*s){
float to ;
if((*z)==0){ (*c) = 1 ; (*s) = 0; return ;}
if( abs(*z)>abs(*x) ){
  to = -(*x)/(*z) ;
  *s = 1/sqrt(1+to*to);
  *c = (*s) * to ;
 }
else{
  to = -(*z)/(*x) ;
  *c = 1/sqrt(1+to*to) ;
  *s = (*c)*to ;
  }


  return;
}


Vecteur householder(Vecteur x , float* beta ) {
  Vecteur x2n = x.subvec(2,x.dim) ;
  //std::cout<<x.dim<<"Vecteur : " ;
//  (x.subvec(2,2)).affiche(); //pk egale a 0
  float sigma = x2n.dot(x2n) ;
  Vecteur v = x ;
//  x.affiche() ;
  v[1] = 1 ;

  if( sigma==0 && x[1]>=0 ) {
     *beta = 0 ;
  }
  else if(sigma==0 && x[1]<0){ *beta = 2 ; }
  else {
    float mu = sqrt(x[1]*x[1] + sigma)  ;
    if(x[1]<=0){
      v[1] = x[1]-mu ;
    }
    else{v[1] = -sigma/(x[1]+mu) ; }
    *beta = 2*(v[1]*v[1])/(sigma + v[1]*v[1]) ;
    v = v*(1/v[1]) ;
    return v ;
    }
  return v ;
}

Matrice reductridiag(Matrice *M) {
  Matrice D = *M ;
  int l = D.dims[0] ;
  float d  = 0.5*( D[l-1][l-1] - D[l][l] )   ;
  float mu ;
  if (d==0 ){ mu = D[l][l] - D[l][l-1] ; }
  else{ mu = D[l][l] - pow(D[l][l-1],2)/( d+ (d/abs(d))*sqrt(d*d +pow(D[l][l-1],2)) ) ;}
  float x  = D[1][1] - mu ;
  float z  = D[2][1] ;
  float to1 ;
  float to2 ;
  float s ;
  float c ;
  Matrice Z(l,l) ;
//  std::cout<< 0.5*D[l-1][l-1] ;
  for( int i = 1 ; i<(l+1) ; i++){
    Z[i][i] = 1 ;
  }

  for( int k = 1 ; k<l ; k++ ){
    cppidcolgivens(&x,&z,&c,&s) ;
    for( int j = 1 ; j<(l+1) ; j++ ){

      to1 = D[j][k] ;
      to2 = D[j][k+1] ;
      D[j][k]   = c*to1 - s*to2 ;
      D[j][k+1] = s*to1 + c*to2 ;
      to1 = Z[j][k] ;
      to2 = Z[j][k+1] ;
      Z[j][k]   = c*to1 - s*to2 ;
      Z[j][k+1] = s*to1 + c*to2 ;

    }
    //rotation gauche
    for( int j = 1; j<(l+1) ; j++ ){
      to1 = D[k][j] ;
      to2 = D[k+1][j] ;
      D[k][j]   = c*to1 - s*to2 ,
      D[k+1][j] = s*to1 + c*to2 ;
    }

    if(k<(l-1)){
      x = D[k+1][k] ;
      z = D[k+2][k] ;
    }
  }
  //copie de l'element avec lequel nous avons travaillé
  *M = D ;
  return Z ;
}


void qrsym(Matrice *A ,Matrice *Q){
  int n = (*A).dims[0] ;
  Vecteur v ;
  Vecteur a ;
  float beta ;
  Vecteur p ;
  Vecteur w ;

  Matrice TMPA ;
  Matrice TMPQ ;
  Matrice T(n,n) ;
  Matrice Z ;
  Matrice IZI = T  ;
  Matrice Tchap = T ;
  Matrice Ip,Iq ;
  Matrice T1,T2,T3 ;
  Matrice copie ;
  int verifDiag = 1 ;
//Initialisation diagonal
  for( int i = 1 ; i<(n+1) ; i++){
    for(int j = 1 ; j<(n+1) ; j++ ){
      (*Q)[i][j] = 0 ;
    }
    (*Q)[i][i] = 1 ;
  }
//etape code donné en anexe
  for ( int k = 1 ; k<(n-2)+1 ; k++){

    a = ((*A).transpose()).submat(k,k,k+1,n)[1] ;
    v = householder(a,&beta ) ;
    p = ( (*A).submat(k+1,n,k+1,n) ).mvprod(v)*beta ;
    w = p - v*p.dot(v)*(beta/2);
    (*A)[k+1][k] = ( (*A).submat(k+1,n,k,k)[1] ).norm() ;
    (*A)[k][k+1] = (*A)[k+1][k] ;
    TMPA = (*A).submat(k+1,n,k+1,n) ;
    TMPQ = (*Q).submat(k+1,n,k+1,n) ;
    //
    TMPA = TMPA - Matrice::outer(v,w) - Matrice::outer(w,v) ;
    TMPQ = TMPQ - beta * Matrice::outer(v,v)*TMPQ ;
    // //copie de la sous matrice
     for(int i1 = 1 ; i1<(TMPA.dims[0]+1) ; i1++) {
       for(int j1 = 1 ; j1<(TMPA.dims[0]+1);j1++) {
    //
         (*A)[i1+k][j1+k] = TMPA[i1][j1] ;
         (*Q)[i1+k][j1+k] = TMPQ[i1][j1] ;
       }
    }


  }
 for (int j = n ; j>0 ; j-- ){

   T[j][j] = (*A)[j][j] ;

// (*A).affiche() ;
   if(j>1){
     T[j-1][j] = (*A)[j][j-1] ;
     T[j][j-1] = (T)[j-1][j] ;

   }

 }
 //diagonalisation de T et mise a jour de Q
verifDiag = 1 ;
 while(verifDiag!=0){
  std::cout<<"Q ICI " ;
  Q->affiche() ;

   for(int i = (n-1) ; i>0 ; i-- ){
     //gestion des erreur numeriques ,
      if( (abs(T[i][i+1]) + abs(T[i+1][i]) )<= pow(10,-9)*(abs(T[i][i]) + abs(T[i+1][i+1])) ){
        T[i][i+1] = 0 ;
        T[i+1][i] = 0 ;
      }
   }

//   std::cout<<" T " ;
//   T.affiche() ;
   int p = 0 ;
   int q = 0 ;
   //calcule p et q
   for(int i = 1 ; i<n ; i++){
      if((T[i+1][i] != 0 ) || (T[i][i+1]!=0) ) {
       break ;
     }
     p++ ;
    }
   for(int i = (n) ; i>1 ; i--){
      if((T[i][i-1] != 0 ) || (T[i-1][i]!=0) ) {
       break ;
     }
//      std::cout<<"ICI" ;
     q++ ;
   }

   if( (p+q)>= n ) {
     std::cout<<" Voici Q : " ;
     Q->affiche() ;
     return ;  }
    //borne de la matrice T3
    int t3n = p+1 ;
    int t3p = n-q ;

    // si p = 0 on ajuste les borne de T3 et on affiche pas T1
    if(p!=0){
    T1 = T.submat(1,p,1,p) ;

//  (T.submat(1,p,1,p)).affiche() ;
    }
    else{ t3n = 1 ; }
    //idem
    if(q!=(0)){
//    std::cout<<" T3 " ;
//    (T.submat(n-q+1,n,n-q+1,n)).affiche() ;
    }
    else{ t3p = n ;}

//    std::cout<<"\ndim de T2   "<<t3n<<"-"<<t3p ;
    T2 = T.submat(t3n,t3p,t3n,t3p) ;
//    std::cout<<" T " ;
//    T.affiche() ;
//    std::cout<<" T2 " ;
//    T2.affiche() ;

    if((p+q)<n){

      Tchap = T ;
      Z = reductridiag(&T2) ;
      Tchap.copiesousmatricecarre(T2,t3n) ;
      T = (0.5)*(Tchap + Tchap.transpose()) ;

      Ip = Matrice::Identity(p) ;
      Iq = Matrice::Identity(q) ;
      IZI.copiesousmatricecarre(Ip,p) ;
      IZI.copiesousmatricecarre(Iq,n-q+1) ;
      IZI.copiesousmatricecarre(Z,p+1) ;
      *Q = (*Q)*IZI ;

    }
    else{
      std::cout<<" Voici Q : " ;
      (*Q).affiche() ;
      break ;
    }







 }
  return ;
}
