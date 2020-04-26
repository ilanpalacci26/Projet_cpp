#include <cmath>
#include <iostream>
#include "Projetcpp2020.h"
#include "functionTab2020.h"


// fonctions en lien avec la classe vecteur ------------------------------------

void Vecteur::affiche(){
  AfficherTab(tab,dim) ;
  std::cout << "la dimension du vecteur est : " << dim ;
  std::cout << "voici ses coordonnées" ;
}

Vecteur::Vecteur(){ //constructeur
  dim = 1 ;
  InitTab(tab,1);
}
