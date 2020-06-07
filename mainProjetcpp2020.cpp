// chemin /Users/ilanpalacci/Desktop/M1_dauphine/semestre_2_M1/C++/TENSEURProjetNote2020cpp/Projet_cpp

// pour tout executer g++ *2020.cpp -o t

#include <iostream>
#include <cmath>


#include "Projetcpp2020.h"
#include "functionTab2020.h"
#include "tenseur2_2020.h"
#include "PartieIII_2020.h"
#include "PartieIV_2020.h"




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





Matrice M(3,3) ;
M[1][1] = 1 ;
M[1][2] = 1./2. ;
M[1][3] = 1./3. ;
M[2][1] = 1./2. ;
M[2][2] = 1./3. ;
M[2][3] = 1./4. ;
M[3][1] = 1./3. ;
M[3][2] = 1./4. ;
M[3][3] = 1./5. ;



Matrice A(3,3) ;
A[1][1] = 10 ;
A[1][2] = -6 ;
A[1][3] = 0 ;
A[2][1] = -6 ;
A[2][2] = 10 ;
A[2][3] = 0 ;
A[3][1] = 0 ;
A[3][2] = 0 ;
A[3][3] = 1 ;
Matrice Q(3,3) ;
Matrice U = Q ;
Matrice SIGMA = Q ;
Matrice V = Q ;
Matrice copie = M ;
Matrice PI = qrpivot(&copie,&Q) ;
ErreurNumeric(&Q) ;
Q.affiche() ;
PI.affiche() ;
M.affiche() ;
Matrice R =  Q.transpose()*M*PI ;
ErreurNumeric(&R) ;
R.affiche() ;

//qrpivot(&M,&Q) ;
/*svd(&A,&U,&SIGMA,&V) ;
A.affiche() ;
U.affiche() ;
SIGMA.affiche() ;
V.affiche() ;
*/

 // Matrice copA = A ;
/*
 //A.affiche() ;
qrsym(&A,&Q) ;
 //A.affiche() ;
std::cout<<" QTAQ apres algorithme: " ;
std::cout<<" Q apres algorithme: " ;
Q.affiche() ;
 //Q.affiche() ;
 */
//   M.affiche() ;
//    Matrice PI = qrpivot(&M,&Q) ;
// // // qrsym(&C,&Q) ;
// // // Q.affiche() ;
//  Q.affiche() ;
//  M.affiche() ;
//  PI.affiche() ;
// //


 return 0 ;
}
