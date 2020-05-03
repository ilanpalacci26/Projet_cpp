// chemin /Users/ilanpalacci/Desktop/M1_dauphine/semestre_2_M1/C++/TENSEURProjetNote2020cpp/Projet_cpp

// pour tout executer g++ *2020.cpp -o t

#include <iostream>
#include "Projetcpp2020.h"
#include "functionTab2020.h"
#include <cmath>




int main(int argc, char const *argv[]) {
  float a[3] = {1,2,3} ;
  Vecteur test(a,3) ;
  test.affiche() ;
  Vecteur b = test ;
  b.affiche() ;
  Vecteur c  ;
//  c = test+b ;
  c.affiche() ;


 return 0 ;

}
