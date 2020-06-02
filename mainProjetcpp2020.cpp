// chemin /Users/ilanpalacci/Desktop/M1_dauphine/semestre_2_M1/C++/TENSEURProjetNote2020cpp/Projet_cpp

// pour tout executer g++ *2020.cpp -o t

#include <iostream>
#include <cmath>


#include "Projetcpp2020.h"
#include "functionTab2020.h"
#include "tenseur2_2020.h"
#include "PartieIII_2020.h"




int main(int argc, char const *argv[]) {
float a = 1;
float b = 2 ;
float c = 3 ;
float d = 4 ;

cppidcolgivens(&a,&b,&c,&d) ;
Matrice A(4,4) ;
A[1][1] = 1 ;
A[1][2] = -1/2 ;
A[1][3] = 5 ;
A[2][1] = 0 ;
A[2][2] = 2 ;
A[2][3] = -1 ;
A[3][1] = 0 ;
A[3][2] = 0 ;
A[3][3] = 1 ;
A[4][4] = 2 ;
Matrice B = reductridiag(&A) ;
Matrice Q = A ;
qrsym(&A,&Q) ;

 return 0 ;
}
