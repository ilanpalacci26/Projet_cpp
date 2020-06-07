
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
  Matrice(Vecteur * , int) ;
  Matrice(const Matrice &) ; // recopie
  ~Matrice();
  Vecteur& operator[](int i) ;
  Matrice & operator=(const Matrice &) ; //affectation

  Matrice operator+(const Matrice &) ;
  Matrice operator-(const Matrice &) ;
  Matrice operator*(const Matrice &) ;
  friend Matrice operator*(float , Matrice) ;

  Vecteur mvprod(Vecteur) ;
  Matrice transpose() ;
  Matrice submat(int, int, int, int) ;
  float norm() ;
  static Matrice outer(Vecteur, Vecteur) ;

  friend Matrice reductridiag(Matrice *) ;
//partie 3 optionnelle
  void copiesousmatricecarre(Matrice ,int ) ;
  void copiesousmatriceLibre(Matrice ,int , int) ;
  static Matrice Identity(int ) ;

  friend Matrice qrpivot(Matrice * , Matrice *);
  friend float verifdiagonal(Matrice A) ;
  friend void qrsym(Matrice *A ,Matrice *Q) ;
} ;

void ErreurNumeric(Matrice * A) ;
