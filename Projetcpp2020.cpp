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
//  delete tab ;
  tab = new float[dim];
  for(int i = 0; i < dim; i++){
     tab[i] = 0;
   }
}

Vecteur::Vecteur(int tailleTAB){ //constructeur
  dim = tailleTAB ;
//  delete tab ;
  tab = new float[dim];
  for(int i = 0; i < dim; i++){
     tab[i] = 0;
   }

}

Vecteur::Vecteur(float* vec ,int tailleTAB){ //constructeur
  dim = tailleTAB ;
//  delete tab ;
  tab = new float[dim];
  for(int i = 0; i < dim; i++){// Idée : faire un catch si segfault ?
     tab[i] = vec[i];
   }

}

Vecteur::Vecteur(const Vecteur &t){
  dim = t.dim ;
//  delete tab ;
  tab = new float[dim];
  for(int i = 0; i < dim; i++){// Idée : faire un catch si segfault ?
     tab[i] = t.tab[i];
   }
}

Vecteur::~Vecteur(){
  //delete  tab ;
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
//------------------ Surdefinition --------------

Vecteur operator+(const Vecteur & t1, const Vecteur & t2){
    int Newdim = t1.dim ;
    float *Newtab = new float[Newdim];
    for(int i = 0; i < Newdim; i++){// Idée : faire un catch si segfault ?
       Newtab[i] = t1.tab[i]+t2.tab[i];
     }
    Vecteur a(Newtab,Newdim) ;
  return a ;
  }


Vecteur operator-(const Vecteur & t1, const Vecteur & t2){
    int Newdim = t1.dim ;
    float *Newtab = new float[Newdim];
    for(int i = 0; i < Newdim; i++){// Idée : faire un catch si segfault ?
       Newtab[i] = t1.tab[i]-t2.tab[i];
     }
    Vecteur a(Newtab,Newdim) ;
    return a ;
    }


float& Vecteur::operator[](int i){
  return tab[i] ;
}
