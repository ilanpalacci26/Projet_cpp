#include "functionTab2020.h"
# include <iostream>
using namespace std ;

void InitTab (float *tab,int tailleTAB){
  tab = new float[tailleTAB];
  float * p = tab ;
  int i ;
  for(i =0 ; i<tailleTAB ; i++ ){
     *p = 0 ;
    p++ ;
    }
  }


void DeclarationTab(float *tab , int tailleTAB) {
      for( float* p = tab ; p<tab +tailleTAB ; p++){
        *p = 5 ;
      }
    }

void AfficherTab(float *tab,int tailleTAB){
      float * p = tab ;
      int i ;
      for(i =0 ; i<tailleTAB ; i++ ){
        std::cout << *p << "\n" ;
        p++ ;
      }
    }

void RemplirTab(float *tab , int tailleTAB){
  float* p = tab ;
  int temp ;
  if (tailleTAB >10) return ;
  for( float* p = tab ; p<tab +tailleTAB ; p++){
//
    std::cout << "entrez la valeur" ;
    std::cin >> temp  ;
    *p = temp ;
  }

}
