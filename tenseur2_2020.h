
// tenseur d'ordre 1
class Matrice {
private:
public:
  int dims[2] ;
  Vecteur* mat ;
public:
  Matrice();
  void affiche() ;
  Matrice(int, int) ;
  Matrice(Vecteur) ;
//  Matrice(Vecteur * , int) ;

} ;
