
// chemin /Users/ilanpalacci/Desktop/M1_dauphine/semestre_2_M1/C++/TENSEURProjetNote2020cpp/Projet_cpp/test
# include <iostream>
# include <vector>

void InitTab (float *tab,int tailleTAB){

  tab = new float[tailleTAB];
for(int i = 0; i < tailleTAB; i++)
     tab[i] = 0;
  }

void AfficherTab(float *tab,int tailleTAB){
        int i ;
        for(i =0 ; i<tailleTAB ; i++ ){
          std::cout << tab[i] << "\n" ;
        }
      }



int main(int argc, char const *argv[]) {

    float *p = new float[1]  ; // je souhaite initialiser un pointeur dont la taille dependra de son initialisation
    p[0] = 1 ;
    std::cout<< *p ;
    delete [] p ;
  return 0;
}
