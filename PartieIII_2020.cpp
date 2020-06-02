#include <iostream>
#include <cmath>

#include "Projetcpp2020.h"
#include "functionTab2020.h"
#include "tenseur2_2020.h"
#include "PartieIII_2020.h"


void cppidcolgivens(float *z , float *x , float*c , float*s){
if(*z==0){*c = 1 ; *s = 0; return ;}
  if( abs(*z)>=abs(*x) ){
    float to = -(*x)/(*z) ;
    *c = 1/( sqrt(1+to)*sqrt(1+to) ) ;
    *s = (*c)*to ;
 }
  else{
    float to = -(*z)/(*x) ;
    *s = 1/( sqrt(1+to)*sqrt(1+to) ) ;
    *c = (*s)*to ;
  }
  return;
}


Vecteur householder(Vecteur x , float* beta ) {
  Vecteur x2n = x.subvec(2,x.dim) ;

  float sigma = x2n.dot(x2n) ;
  Vecteur v = x ;
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
  float d  = 0.5*D[l-1][l-1];
  float mu = D[l][l] - pow(D[l][l],2)/( d+ (d/abs(d))*sqrt(d*d +pow(D[l][l-1],2)) ) ;
  float x  = D[1][1] - mu ;
  float z  = D[2][1] ;
  float to1 ;
  float to2 ;
  float s ;
  float c ;
  Matrice Z(l,l) ;

  std::cout<< 0.5*D[l-1][l-1] ;

  for( int i = 1 ; i<(l+1) ; i++){

    Z[i][i] = 1 ;
  }
  for( int k = 1 ; k<l ; k++ ){
    cppidcolgivens(&x,&z,&c,&s) ;
    for( int j = 1 ; j<(l+1) ; j++ ){

      to1 = D[j][k] ;
      to2 = D[j][k+1] ;
      D[j][k]   = c*to1 - s*to2 ;
      D[j][k+1] = s*to1 - c*to2 ;
      Z[j][k]    = c*to1 - s*to2 ;
      Z[j][k+1] = s*to1 - c*to2 ;

    }
    for( int j = 1; j<(l+1) ; j++ ){
      to1 = D[k][j] ;
      to2 = D[k+1][j] ;
      D[k][j] = c*to1 - s*to2 ,
      D[k+1][j] = s*to1 + c*to2 ;
    }

    if(k<(l-1)){
      x = D[k+1][k] ;
      z = D[k+2][k] ;
    }
  }
  *M = D ;
  D.affiche() ;
  Z.affiche() ;
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
    (*A)[k+1][k] = ( (*A).submat(k+1,n,k+1,n) ).norm() ;
    TMPA = (*A).submat(k+1,n,k+1,n) ;
    TMPQ = (*Q).submat(k+1,n,k+1,n) ;
    //
     TMPA = TMPA - Matrice::outer(v,w) - Matrice::outer(w,v) ;
     TMPQ = TMPQ - beta * beta * Matrice::outer(v,v)*TMPQ ;
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
   //
   // T[j][j] = (*A)[j][j] ;
   // if(j<n) { T[j+1][j] = (*A)[j][j+1] ; }
   // if(j>n) { T[j][j+1] = (*A)[j+1][j] ; }

 }

  return ;
}
