
// tenseur d'ordre 1
class Vecteur{
  public:
  int dim ;
  float * tab ; // Allocation dynamique int * foo; foo = new int [5];
  Vecteur() ; //constructeur initialise un vecteur dans R de valeur 0
  //  Vecteur(float* ?) //constructeur
  // Vecteur(float*, int ?) //constructeur
  void affiche() ; // affiche dim et les elements de tab
  // //  deletvecteur(); // destructeur
  // //  copievecteur(); // copie le vecteur
  //   //surdefinition voir Projet
  // } ;

} ;
