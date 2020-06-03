// chemin /Users/ilanpalacci/Desktop/M1_dauphine/semestre_2_M1/C++/TENSEURProjetNote2020cpp/Projet_cpp

// pour tout executer g++ *2020.cpp -o t

#include <iostream>
#include <cmath>


#include "Projetcpp2020.h"
#include "functionTab2020.h"
#include "tenseur2_2020.h"
#include "PartieIII_2020.h"




int main(int argc, char const *argv[]) {
std::cout<< "\n" ;
//verif partie III

/*
float a = 1;
float b = 2 ;
float c ;
float d ;
float beta ;
cppidcolgivens(&a,&b,&c,&d) ;
std::cout<<" coef c : " << c <<" coef s  "<<d<<"\n"  ;

Vecteur x(2) ;
x[1] = -1 ;
x[2] = 0 ;
householder(x,&beta) ;
std::cout<<" householder pour" ;
x.affiche() ;
std::cout<<" beta : "<< beta <<"\n";
Vecteur y(2) ;
y[1] = 1/sqrt(2) ;
y[2] = 1/sqrt(2) ;
householder(y,&beta) ;
std::cout<<" householder pour" ;
y.affiche() ;
std::cout<<" beta : "<< beta<<"\n" ;


Vecteur z(1) ;
z[1] = -4 ;
householder(z,&beta) ;
std::cout<<" householder pour" ;
z.affiche() ;
std::cout<<" beta : "<< beta <<"\n";

*/




Matrice A(2,2) ;
A[1][1] = 10 ;
A[1][2] = -6 ;
A[2][1] = -6 ;
A[2][2] = 10 ;
//
 Matrice Q = A ;

 A.affiche() ;
 qrsym(&A,&Q) ;
 A.affiche() ;
 Q.affiche() ;

 return 0 ;
}
