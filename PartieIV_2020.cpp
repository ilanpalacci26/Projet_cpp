#include <iostream>
#include <cmath>

#include "Projetcpp2020.h"
#include "functionTab2020.h"
#include "tenseur2_2020.h"
#include "PartieIII_2020.h"
#include "PartieIV_2020.h"

Tenseur::Tenseur(int * tab ,int dim){
  ordreD = dim ;
  dims = new int[dim];
  int prod = 1;
  for(int i = 0 ; i <dim ; i++){
    prod = prod*tab[i] ;
  }
  nbelts=prod ;
  phi = new Vecteur[nbelts] ;
}
