#include <cmath>
#include <iostream>

#include "Projetcpp2020.h"
#include "functionTab2020.h"
#include "tenseur2_2020.h"
#include "PartieIII_2020.h"

//probleme1 : InitTab ne fonctionne pas il semble que l'adresse se perd


// ****************** fonctions en lien avec la classe vecteur ******************

// ------------------- Constructeur , Destructeur -------------------

Vecteur::Vecteur(){ //constructeur
  dim = 1 ;
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
  dim = 0 ;
  delete [] tab ;
}

// ------------------- surdefinition Membre-------------------

Vecteur& Vecteur::operator=(const Vecteur &t){
  if (this!=&t){
    delete[] tab ;
    dim = t.dim ;
    tab = new float[dim];
    for(int i=0;i<dim;i++){
      tab[i] = t.tab[i] ;
      }
    }
  return *this;
  }

  float& Vecteur::operator[](int i){
    i = i-1 ;
    return tab[i] ;
  }
//------------------ Surdefinition friend--------------

//******Attention pas fonction friend******
Vecteur operator+(const Vecteur & t1, const Vecteur & t2){
    if(t1.dim != t2.dim) { std::cout<<"ERREUR taille differente, fonction :  "<<__func__ ; return Vecteur() ;  }
    int Newdim = t1.dim ;
    float *Newtab = new float[Newdim];
    for(int i = 0; i < Newdim; i++){// Idée : faire un catch si segfault ?
       Newtab[i] = t1.tab[i]+t2.tab[i];
     }
    Vecteur a(Newtab,Newdim) ;
  return a ;
  }

Vecteur operator-(const Vecteur & t1, const Vecteur & t2){
    if(t1.dim != t2.dim) { std::cout<<"ERREUR taille differente, fonction :  "<<__func__ ; return Vecteur() ;  }
    int Newdim = t1.dim ;
    float *Newtab = new float[Newdim];
    for(int i = 0; i < Newdim; i++){// Idée : faire un catch si segfault ?
       Newtab[i] = t1.tab[i]-t2.tab[i];
     }
    Vecteur a(Newtab,Newdim) ;
    return a ;
    }


Vecteur operator*(const Vecteur & t1, float l){
      int Newdim = t1.dim ;
      float *Newtab = new float[Newdim];
      for(int i = 0; i < Newdim; i++){// Idée : faire un catch si segfault ?
         Newtab[i] = t1.tab[i]*l;
       }
      Vecteur a(Newtab,Newdim) ;
      return a ;
}

    //------------------ fonction Vecteur--------------

void Vecteur::affiche(){
//  std::cout << "\n\nC'est un vecteur de R^" << dim ;
//  std::cout << "\nVoici ses coordonnées\n" ;
  int i ;
  std::cout << " | " ;
  for(i =0 ; i< (dim-1) ; i++ ){
    std::cout << tab[i] << " ; " ;
  }
  std::cout << tab[i] ;
  std::cout << " | \n" ;
}

Vecteur Vecteur::subvec(int i, int j){
  i=i-1 ; j=j-1 ; //On veut que l'utilisateur entre 1 comme premiere coordonnée
  if (j<i){return( Vecteur(1) ) ; }
  if(i>dim){ return(Vecteur(1)) ;}
  if(i<0){
    std::cout<<"attention valeur < 1 non indexé Valeur 1 par default attribué"<<__func__ <<std::endl ; // 1:referenciel utilisateur
    i=0 ; }
  if(j> dim ) { // dans ce cas
    j=dim ;
    std::cout<< "attention la taille du vecteur est"<<dim <<__func__ <<std::endl ; } // on ne prendra pas pour une erreur
  int Newdim = (j-i)+1 ;
  Vecteur v = Vecteur(Newdim) ;
  for(int k = i; k < (j+1); k++){// Idée : faire un catch si segfault ?
    v.tab[k-i] = tab[k];
   }
  return v ;
}

//******Attention pas fonction friend******
float Vecteur::dot(const Vecteur & t1){
    float sum =0 ; // je souhaite initialiser un pointeur dont la taille dependra de son initialisation
    if(t1.dim != dim) { std::cout<<"ERREUR taille differente, fonction :  "<<__func__ ; return 0 ;  }
    for (int i=0;i<t1.dim;i++){ sum += t1.tab[i]*tab[i]; }
    return sum ;

}

float Vecteur::norm(){
    float sum =0 ;
    for (int i=0;i<dim;i++){ sum += tab[i]*tab[i]; }
    return sqrt(sum) ; // a mettre a la racine

}
