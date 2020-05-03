// chemin /Users/ilanpalacci/Desktop/M1_dauphine/semestre_2_M1/C++/TENSEURProjetNote2020cpp/Projet_cpp

// pour tout executer g++ *2020.cpp -o t

#include <iostream>
#include "Projetcpp2020.h"
#include "functionTab2020.h"
#include <cmath>




int main(int argc, char const *argv[]) {
  float a[3] = {1,2,3} ;
  Vecteur test(a,3) ;
  Vecteur b = test
  Vecteur c  ;
  c = test+b ;
  Vecteur d= c-b-b ;
  d[1] = 5 ;
  Vecteur e = d.subvec(1,2) ;
  Vecteur g  = b.dot(test) ;
  Vecteur h = g.norm() ;
  (g*4).affiche() ;

 return 0 ;

}
