
class Tenseur {
private:
  int ordre ;
  int* dimsval ;
  int nbelts ;
  Vecteur TenseurV ;
public:
  Tenseur(int *,int) ;
  Tenseur(int * ,int , Vecteur ) ;
  Tenseur(int * tabd ,int dim, int k, Matrice A ) ;
  ~Tenseur() ;
  Tenseur(const Tenseur &T) ; 


  friend int phijk(int * tabd ,int dim,int* i,int k) ;
  friend int phi(int * tabd ,int dim,int* i) ;
} ;

int phijk(int * tabd ,int dim,int* i,int k) ;
int phi(int * tabd ,int dim,int* i) ;
