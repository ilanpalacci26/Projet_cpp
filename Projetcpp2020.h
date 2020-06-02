
// tenseur d'ordre 1
class Vecteur{
private:
  int dim ;
  float* tab ; // Allocation dynamique int * foo; foo = new int [5];
public:
  Vecteur() ; //constructeur initialise un vecteur dans R de valeur 0
  Vecteur(int ) ; //constructeur
  Vecteur(float*, int ) ;
  Vecteur(const Vecteur &) ;
  ~Vecteur();
  Vecteur & operator=(const Vecteur &) ;
  friend Vecteur operator+(const Vecteur & , const Vecteur & );
  friend Vecteur operator-(const Vecteur & ,const Vecteur & ) ;
  friend Vecteur operator*(const Vecteur & ,float ) ;
  float & operator[](int ) ;


  Vecteur subvec(int , int ) ;
  float dot(const Vecteur & ) ;
  float norm() ;
  void affiche() ;

  friend class Matrice ;

  friend Vecteur householder(Vecteur x , float* beta ) ;

} ;
