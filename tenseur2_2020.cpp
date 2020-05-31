#include <iostream>
#include <cmath>
#include "Projetcpp2020.h"
#include "functionTab2020.h"
#include "tenseur2_2020.h"


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


void Matrice::affiche(){
  std::cout << "\n\nC'est une matrice de R^" <<dims[0]<<"xR^"<<dims[1]<<std::endl ;
  std::cout << "\nVoici la Matrice coordonnées\n" ;
  for( int i = 0; i<dims[0] ; i++){
      (mat[i]).affiche() ;
   }
}
