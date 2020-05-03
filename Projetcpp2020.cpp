#include <cmath>
#include <iostream>
#include "Projetcpp2020.h"
#include "functionTab2020.h"
//probleme1 : InitTab ne fonctionne pas il semble que l'adresse se perd


// ****************** fonctions en lien avec la classe vecteur ******************

void Vecteur::affiche(){
  std::cout << "\n\nC'est un vecteur de R^" << dim ;
  std::cout << "\nVoici ses coordonnées\n" ;
  AfficherTab(tab,dim) ;
}
// ------------------- Constructeur , Destructeur -------------------

Vecteur::Vecteur(){ //constructeur
  dim = 2 ;
  delete tab ;
  tab = new float[dim];
  for(int i = 0; i < dim; i++){
     tab[i] = 0;
   }
}

Vecteur::Vecteur(int tailleTAB){ //constructeur
  dim = tailleTAB ;
  delete tab ;
  tab = new float[dim];
  for(int i = 0; i < dim; i++){
     tab[i] = 0;
   }

}

Vecteur::Vecteur(float* vec ,int tailleTAB){ //constructeur
  dim = tailleTAB ;
  delete tab ;
  tab = new float[dim];
  for(int i = 0; i < dim; i++){// Idée : faire un catch si segfault ?
     tab[i] = vec[i];
   }

}

Vecteur::Vecteur(const Vecteur &t){
  dim = t.dim ;
  delete tab ;
  tab = new float[dim];
  for(int i = 0; i < dim; i++){// Idée : faire un catch si segfault ?
     tab[i] = t.tab[i];
   }
}

Vecteur::~Vecteur(){
  delete  tab ;
  dim = 0 ;
}

// ------------------- surdefinition -------------------

Vecteur& Vecteur::operator=(const Vecteur &t){
  if (this!=&t){
    delete tab ;
    dim = t.dim ;
    tab = new float[dim];
    for(int i=0;i<dim;i++){
      tab[i] = t.tab[i] ;
      }
    }
  return *this;
  }


Vecteur& operator+(Vecteur const &t1,Vecteur const  &t2){
    int dim = t1.dim ;
    float *tab = new float[dim];
    for(int i = 0; i < dim; i++){// Idée : faire un catch si segfault ?
       tab[i] = t1.tab[i]+t2.tab[i];
     }
    Vecteur a(tab,dim) ;
  return &a ;
  }

/*
Vecteur& Vecteur::operator-(const Vecteur &t1,const Vecteur &t2){
  if (t1.dim== t2.dim){
    delete tab ;
    dim = t1.dim ;
    tab = new float[dim];
    for(int i = 0; i < dim; i++){// Idée : faire un catch si segfault ?
       tab[i] = t1[i]-t2[i];
     }
    }
  return *this;
  }
*/
