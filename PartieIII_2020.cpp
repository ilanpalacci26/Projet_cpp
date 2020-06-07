#include <iostream>
#include <cmath>

#include "Projetcpp2020.h"
#include "functionTab2020.h"
#include "tenseur2_2020.h"
#include "PartieIII_2020.h"


void cppidcolgivens(float *x , float *z , float*c , float*s){
float to ;

if((*z)==0){ (*c) = 1 ; (*s) = 0; return ;}
else{
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

  if( (sigma==0) && (x[1]>=0) ) {
     *beta = 0 ;
  }
  else if( (sigma==0) && (x[1]<0) ){ *beta = 2 ; }
  else {
    float mu = sqrt(x[1]*x[1] + sigma)  ;
    if(x[1]<=0){
      v[1] = x[1]-mu ;
    }
    else{v[1] = -sigma/(x[1]+mu) ; }

    *beta = 2*(v[1]*v[1])/(sigma + v[1]*v[1]) ;
    v = v*(1/v[1]) ;
    }
  return v ;
}

Matrice reductridiag(Matrice *M) {
  Matrice D = *M ;
  int l = D.dims[0] ;
  float d  = 0.5*( D[l-1][l-1] - D[l][l] )   ;
  float mu ;
  if (d==0 ){ mu = D[l][l] - abs(D[l][l-1]) ; }
  else{ mu = D[l][l] - pow(D[l][l-1],2)/( d+ (d/abs(d))*sqrt(d*d +pow(D[l][l-1],2)) ) ;}
  float x  = D[1][1] - mu ;
  float z  = D[2][1] ;
  float to1 ;
  float to2 ;
  float s ;
  float c ;
  Matrice Z = Matrice::Identity(l) ;
//  std::cout<< 0.5*D[l-1][l-1] ;

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
  //ajustement numerique ;

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
  float verifDiag = 1 ;
//Initialisation diagonal
  (*Q) = Matrice::Identity(n) ;
//etape code donné en anexe
  for ( int k = 1 ; k<((n-2)+1) ; k++){
    a = ((*A).transpose()).submat(k,k,k+1,n)[1] ;
    v = householder(a,&beta ) ;
    p = ( (*A).submat(k+1,n,k+1,n) ).mvprod(v)*beta ;
    w = p - v*(p.dot(v))*(beta/2);

    (*A)[k+1][k] = ( (*A).submat(k+1,n,k,k) ).norm() ;
    (*A)[k][k+1] = (*A)[k+1][k] ;
    // TMPA = (*A).submat(k+1,n,k+1,n) ;
    // TMPQ = (*Q).submat(k+1,n,k+1,n) ;
    //
    TMPA = (*A).submat(k+1,n,k+1,n) - Matrice::outer(v,w) - Matrice::outer(w,v) ;
    TMPQ = (*Q).submat(k+1,n,k+1,n) - beta * Matrice::outer(v,v)*(*Q).submat(k+1,n,k+1,n) ;
    // //copie de la sous matrice
    (*A).copiesousmatricecarre(TMPA,k+1) ;
    (*Q).copiesousmatricecarre(TMPQ,k+1) ;

  }
 for (int j = n ; j>0 ; j-- ){
   T[j][j] = (*A)[j][j] ;

// (*A).affiche() ;
   if(j>1){
     T[j-1][j] = (*A)[j][j-1] ;
     T[j][j-1] = T[j-1][j] ;

   }

 }
 //diagonalisation de T et mise a jour de Q
verifDiag = 1 ;
 while(verifDiag!=0){
   for(int i = 1 ; i< ((n-1)+1) ; i++ ){
     //gestion des erreur numeriques ,
      if( (abs(T[i][i+1]) + abs(T[i+1][i]) )<= pow(10,-9)*(abs(T[i][i]) + abs(T[i+1][i+1])) ){
        T[i][i+1] = 0 ;
        T[i+1][i] = 0 ;
      }
   }

//erreur numerique
/*
   for( int i = 1 ; i<n ; i++){
     for( int j = 1 ; j<n ; j++){
       if(abs(T[i][j])<pow(10,-9)){
         T[i][j] = 0;
       }
       if(abs((*Q)[i][j])<pow(10,-9)){
         (*Q)[i][j] = 0;
       }
    }
   }
   */

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

    int t3n = p+1 ;
    int t3p = n-q ;
    // si p = 0 on ajuste les borne de T3 et on affiche pas T
    if(p!=0){
      // T1 = T.submat(1,p,1,p) ;

    }
    else{ t3n = 1 ; }
    //idem
    if(q!=(0)){
      // T3 = T.submat(n-q+1,n,n-q+1,n) ;
    }
    else{ t3p = n ;}

    if(t3n<t3p){
      T2 = T.submat(t3n,t3p,t3n,t3p) ;
    }
    else{T2 = Matrice(0) ; }


//erreur numeriques ;


    if((p+q)<n){

      Tchap = T ;
      Z = reductridiag(&T2) ;
      Tchap.copiesousmatricecarre(T2,t3n) ;

      T = (0.5)*(Tchap + Tchap.transpose()) ;

      IZI = Matrice::Identity(n) ;

      IZI.copiesousmatricecarre(Z,p+1) ;

      *Q = (*Q)*IZI ;


    }
    verifDiag = verifdiagonal(T) ;

    //ajustement numerique ;

 }
  return ;
}


Matrice qrpivot(Matrice *A , Matrice *Q){
  int m = A->dims[0] ;
  int n = A->dims[1] ;
  int r ;
  float to =0;
  int k ;
  float tmp ;
  Matrice TMP ;
  Vecteur v ;
  float beta ;
  Matrice PI = Matrice::Identity(n) ;
  Vecteur c(n) ;
  for(int j(1) ; j<(n+1) ; j++ ){
    c[j] = (A->submat(1,m,j,j).transpose()[1]).dot(A->submat(1,m,j,j).transpose()[1]) ;
  }

  r=0 ;
  to = vmax(c) ;
  while((to>0) && (r<n)){
    r++ ;
    k = vindicemax(c,r,to) ;

//permutation Mat
    for(int i = 1 ; i<(m+1) ; i++ ) {
    //  A->affiche() ;
      tmp     = (*A)[i][r] ;
      (*A)[i][r] = (*A)[i][k] ;
      (*A)[i][k] = tmp ;
  //    A->affiche() ;
    }
  //  c.affiche() ;
    tmp  = c[r] ;
    c[r] = c[k] ;
    c[k] = tmp ;
//permutation Mat
    for(int i = 1 ; i<(n+1) ; i++ ) {
      tmp     = PI[i][r] ;
      PI[i][r] = PI[i][k] ;
      PI[i][k] = tmp ;
    }
    v = householder((*A).submat(r,m,r,r).transpose()[1],&beta) ;
    TMP = (*A).submat(r,m,r,n) - beta*Matrice::outer(v,v)*(*A).submat(r,m,r,n) ;
    (*A).copiesousmatriceLibre(TMP,r,r) ;

    for(int i = (r+1) ; i<(m+1) ; i++ ) {
      (*A)[i][r] = v.subvec(2,(m-r+1))[i-r] ;
    }

    for (int i = (r+1) ;i<(n+1) ; i++ ){
      c[i] = c[i] - pow((*A)[r][i],2) ;
    }

    if(r<n) { to = vmax(c.subvec(r+1,n));  }
    else{ to = 0 ; }

  }

//calcul de Q

  (*Q) = Matrice::Identity(m) ;

  v = Vecteur(m) ;
  //cas ou j = n cf notation algo projet
   for( int j=n ; j>0 ; j-- ){

      v[j] = 1 ;
      if(j==m){
        beta = 2 ;
        (*Q)[m][m] = (*Q)[m][m] -  beta*v[m]*v[m]*((*Q)[m][m]) ;
      }
      else{
        for(int i = (j+1) ; i<(m+1) ; i++)
        {
          v[i] = (*A)[i][j] ;
        }
          beta = 2 / ( 1 + pow( (*A).submat(j+1,m,j,j).norm() , 2) )  ;
          TMP = (*Q).submat(j,m,j,m) - beta* Matrice::outer( (v.subvec(j,m)),(v.subvec(j,m)) )*( (*Q).submat(j,m,j,m) ) ;
          (*Q).copiesousmatriceLibre(TMP,j,j) ;
           // std::cout<<" TMP j puis m  "<< j << "  " << m ;
       // (TMP).affiche() ;

     }
   }
  return PI ;
}

void svd(Matrice *A,Matrice* DEC){

  int m = (*A).dims[0] ;
  int n = (*A).dims[1] ;

  if(m>=n){

    Matrice Q1 ;
    Matrice Q2 ;

    Matrice AtA = (*A).transpose()*(*A) ;
  //application a AtA pour obtenir Q1
    qrsym(&AtA,&Q1);
    Matrice AQ1 =  (*A)*Q1 ;
    //Q2 et PI
    Matrice PI = qrpivot(&AQ1,&Q2);
    Matrice R = Q2.transpose()*AQ1*PI ;

    for( int j = 1 ; j<(n+1) ; j++){

      if(R[j][j] < 0 ){

        for (int i = 1 ; i<(m+1) ; i++){

          Q2[i][j] = -Q2[i][j] ;

        }

      }

    }
    R = Q2.transpose()*AQ1*PI ;
    DEC[0] = Q1 ;
    DEC[1] = R ;
    DEC[2] = Q1*PI ;
  }
  else{
      Matrice Q1  ;
      Matrice Q2  ;

      Matrice AAt = (*A)*( (*A).transpose() ) ;
    //application a AtA pour obtenir Q1
      qrsym(&AAt,&Q1);
      Matrice AtQ1 =  ( (*A).transpose() )*Q1 ;
    // calcule de PI , Q2 ;
      Matrice PI = qrpivot(&AtQ1,&Q2);
      Matrice R = Q2.transpose()*( (*A).transpose() )*Q1*PI ;
    // Matrice R = Q2.transpose()*AtQ1*PI ;

      for( int i = 1 ; i<(m+1) ; i++){

        if(R[i][i] < 0 ){

          for (int j = 1 ; j<(n+1) ; j++){
            Q2[j][i] = -Q2[j][i] ;

          }

        }

      }

       R = Q2.transpose()*( (*A).transpose() )*Q1*PI ;
      // R = Q2.transpose()*AtQ1*PI ;

      DEC[0] = Q1*PI ;
      DEC[1] = R.transpose() ;
      DEC[2] = Q2 ;

    }


  ErreurNumeric(&DEC[0]) ;
  ErreurNumeric(&DEC[1]) ;
  ErreurNumeric(&DEC[2]) ;

  return ;
}
