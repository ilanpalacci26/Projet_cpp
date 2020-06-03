#include "functionTab2020.h"
# include <iostream>
using namespace std ;

void InitTab (float *tab,int tailleTAB){
  tab = new float[tailleTAB];
  for(int i = 0; i < tailleTAB; i++){
     tab[i] = 0;
   }
  }


void DeclarationTab(float *tab , int tailleTAB) {
      for( float* p = tab ; p<tab +tailleTAB ; p++){
        *p = 5 ;
      }
    }

void AfficherTab(float *tab,int tailleTAB){
      int i ;
      std::cout << "( " ;
      for(i =0 ; i< (tailleTAB-1) ; i++ ){
        std::cout << tab[i] << "   ; " ;
      }
      std::cout << tab[i] ;
      std::cout << " ) \n" ;
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
