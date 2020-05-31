// chemin /Users/ilanpalacci/Desktop/M1_dauphine/semestre_2_M1/C++/TENSEURProjetNote2020cpp/Projet_cpp

// pour tout executer g++ *2020.cpp -o t

#include <iostream>
#include <cmath>


#include "Projetcpp2020.h"
#include "functionTab2020.h"
#include "tenseur2_2020.h"




int main(int argc, char const *argv[]) {
//Partie 1
/*
  float a[3] = {1,1,1} ;
  float b[4] = {3,4,0,0} ;
  Vecteur u(a,3) ;
  Vecteur v(b,4) ;
  u.affiche() ;
  v.affiche() ;
  Vecteur t = u ;
  t.affiche() ;
  float norme = v.norm() ;
  float prodscal = v.dot(v) ;
  std::cout<< "voici la norme : " << norme << " et le produit scalaire <v,v> : " << prodscal<< std::endl ;
  (v*(1/norme)).affiche() ;
  Vecteur w = v.subvec(1,3) ;
  std::cout<< "\nvoici w : " << std::endl ;
  w.affiche() ;
  std::cout<< "\nvoici v : " << std::endl ;
  v.affiche() ;
  std::cout<< "\nvoici u+w : " <<std::endl ;
  (u+w).affiche() ;
  std::cout<< "\n voici u-w : " <<std::endl ;
  (u-w).affiche() ;
*/
float a[3] = {1,1,1} ;
Vecteur u(a,3) ;
u[2] = 3 ;
u.affiche() ;
Matrice M(u) ;
M.affiche() ;
 return 0 ;
}
