# Projet_cpp
projet 2020 c++ dauphine

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

/*
//PARTIE II
Matrice A(3,3) ;
A[1][1] = 1 ;
A[1][2] = -1/2 ;
A[1][3] = 0 ;
A[2][1] = 1 ;
A[2][2] = 2 ;
A[2][3] = -1 ;
A[3][1] = 0 ;
A[3][2] = -1 ;
A[3][3] = 1 ;
std::cout << "A" ;
A.affiche() ;

Matrice B(2,2) ;
B[1][1] = -2 ;
B[1][2] = 3 ;
B[2][1] = 0 ;
B[2][2] = 1 ;
std::cout << "B" ;
B.affiche() ;

Matrice C = B ;
B[1][2] = 0 ;
std::cout << "B puis C" ;
B.affiche() ;
C.affiche() ;

Matrice D = A.submat(1,3,1,2) ;
std::cout << "D" ;
D.affiche() ;

Vecteur v(3) ;
v[1] = 3 ;
v[2] = 2 ;
v[3] = 1 ;
Matrice E(v) ;
std::cout << "E" ;
E.affiche();

std::cout << "B+C , C-B , D*C" ;
(B+C).affiche() ;
(C-B).affiche() ;
(D*C).affiche() ;

C.norm() ;
(0.5*(B+B.transpose()) ).affiche() ;
*/
