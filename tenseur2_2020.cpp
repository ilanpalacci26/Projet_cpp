#include <iostream>
#include <cmath>

#include "Projetcpp2020.h"
#include "functionTab2020.h"
#include "tenseur2_2020.h"
#include "PartieIII_2020.h"


Matrice::Matrice(){
  dims[0] = 1 ;
  dims[1] = 1 ;
  mat = new Vecteur[dims[1]] ;
}
Matrice::Matrice(int l,int c) {
  dims[0] = l ;
  dims[1] = c ;
  mat = new Vecteur[l] ;
  for(int i = 0; i<l ; i++){
    mat[i] = Vecteur(c) ;
  }
}

Matrice::Matrice(Vecteur v) {
  dims[0] = v.dim ;
  dims[1] =  dims[0] ;
  mat = new Vecteur[dims[0]] ;
  for(int i = 0; i<dims[0] ; i++){
    mat[i] = Vecteur(3) ;
    mat[i][i+1] = v[i+1] ;
  }
}

/*Matrice::Matrice(Vecteur* v , int dim){
  dims[0] = v.dim ;
  dims[1] =  dims[0] ;
  mat = new Vecteur[dims[0]] ;
  Vecteur * p = v ;
  for(int i = 0; i<dims[0] ; i++){
    mat[i] = p ;
    p = p->suiv ;
  }
}*/

Matrice::Matrice(Vecteur *v , int dim){
  dims[0] = v[0].dim ;
  dims[1] = dim ;

  mat = new Vecteur[dims[0]] ;
  for( int i=0 ; i<v[0].dim ; i++){
    mat[i] = Vecteur(dim) ;
    for(int j=0 ; j<dim ; j++){
      mat[i][j+1] = v[j][i+1] ; // rappel v[j] est un vecteur , mat[i] aussi : voir surdef de [] pour .+1
    }
  }
}


void Matrice::affiche(){
  std::cout << "\n\nC'est une matrice de R^" <<dims[0]<<"xR^"<<dims[1]<<std::endl ;
  for( int i = 0; i<dims[0] ; i++){
      (mat[i]).affiche() ;
   }
}

Matrice::~Matrice(){
  dims[0] = 0 ;
  dims[1] = 0 ;
  delete [] mat;
}

Matrice::Matrice(const Matrice &m) {
  dims[0] = m.dims[0] ;
  dims[1] = m.dims[1] ;
  mat = new Vecteur[dims[0]] ;
  for(int i = 0; i<dims[0] ; i++){
    mat[i] = m.mat[i] ;
  }
}

//------------------ Surdefinition friend--------------


Matrice &  Matrice::operator=(const Matrice &m){ //affectation
    dims[0] = m.dims[0] ;
    dims[1] = m.dims[1] ;
    delete[] mat ;
    mat = new Vecteur[dims[0]] ;
    for(int i = 0; i<dims[0] ; i++){
      mat[i] = m.mat[i] ;
    }
    return *this ;
  }

Vecteur& Matrice::operator[](int i){
  i = i-1 ;
  return mat[i] ;
}

Matrice Matrice::operator+(const Matrice &m1){
  if( (m1.dims[0]!=dims[0]) || (m1.dims[1]!=dims[1]) ){ std::cout<<"ERREUR taille differente, fonction :  "<<__func__ ; return Matrice() ;  }
  int newdims0 = m1.dims[0] ;
  int newdims1 = m1.dims[1] ;
  Matrice mnew(m1.dims[0],m1.dims[1]) ;
  for(int i = 0; i<m1.dims[0] ; i++){
    mnew.mat[i] = (m1.mat[i]+ mat[i] )  ;
  }
  return mnew ;
}

Matrice Matrice::operator-(const Matrice &m1){
  if( (m1.dims[0]!=dims[0]) || (m1.dims[1]!=dims[1]) ){ std::cout<<"ERREUR taille differente, fonction :  "<<__func__ ; return Matrice() ;  }
  int newdims0 = m1.dims[0] ;
  int newdims1 = m1.dims[1] ;
  Matrice mnew(m1.dims[0],m1.dims[1]) ;
  for(int i = 0; i<m1.dims[0] ; i++){
    mnew.mat[i] = (mat[i] - m1.mat[i] )  ;
  }
  return mnew ;
}

Matrice Matrice::operator*(const Matrice &m1){
  if( (m1.dims[0]!=dims[1]) ){ std::cout<<"ERREUR taille differente, fonction :  "<<__func__ ; return Matrice() ;  }
  int newdims0 = dims[0] ;
  int newdims1 = m1.dims[1] ;
  Matrice mnew(dims[0],m1.dims[1]) ;
  for(int i = 0; i<dims[0] ; i++){
    for(int j=0 ; j<m1.dims[1] ; j++)
    mnew[i+1][j+1] = mat[i].dot(m1.mat[j])  ; // indice decalé
  }
  return mnew ;
}
Matrice operator*(float scal, Matrice M){
  Matrice newm(M.dims[0],M.dims[1]) ;
  for(int i = 0; i<M.dims[0] ; i++){
    newm[i+1] = M[i+1]*scal ;
  }
  return newm ;
}

Vecteur Matrice::mvprod(Vecteur v){
  if(v.dim != dims[1]){ std::cout<<"ERREUR taille differente, fonction :  "<<__func__ ; return Vecteur() ;  }
  Vecteur vnew = Vecteur(v.dim) ;
  for(int i = 0; i<v.dim ; i++){
  vnew[i+1] = mat[i].dot(v) ;
}
  return vnew ;
}


Matrice Matrice::transpose(){
  Matrice newm(dims[1], dims[0] ) ;
  for( int i=0 ; i<dims[1] ; i++){
    for(int j=0 ; j<dims[0] ; j++){
      newm[i+1][j+1] = mat[j][i+1] ; //  mat[i] accede directzmznt a l'element i-1 aussi , voir surdef de [] pour .+1
    }
  }
  return newm ;
}

Matrice Matrice::submat(int il, int jl, int ic , int jc){
  if(il>jl || ic>jc) {std::cout <<"sous ensemble inexistant"<<__func__ ; }
  int dims0 = jl-il+1 ;
  int dims1 = jc-ic+1 ;
  Matrice newm(dims0,dims1) ;
  for(int i=0 ; i<dims0 ; i++){
    newm[i+1] = mat[i+il-1].subvec(ic,jc) ; //-1 car mat est la matrice directement
  }
  return newm ;
}

float Matrice::norm(){
  float sum = 0 ;
  for( int i=0 ; i<dims[0] ; i++){
    for(int j=0 ; j<dims[1] ; j++){
      sum += mat[i][j+1]*mat[i][j+1] ; //  mat[i] accede directzmznt a l'element i-1 aussi , voir surdef de [] pour .+1 mais mat[i] est un vecteur
    }
  }
  return sqrt(sum) ;
}

Matrice Matrice::outer(Vecteur v1, Vecteur v2){
 Matrice newm(v1.dim,v2.dim) ;
 for( int i=0 ; i<v1.dim ; i++){
   for(int j=0 ; j<v2.dim ; j++){
     newm[i+1][j+1] = v1[i+1]*v2[j+1] ; //  mat[i] accede directzmznt a l'element i-1 aussi , voir surdef de [] pour .+1 mais mat[i] est un vecteur
   }
 }
  return newm ;
}
