#include <iostream>
#include <cmath>

#include "Projetcpp2020.h"
#include "functionTab2020.h"
#include "tenseur2_2020.h"
#include "PartieIII_2020.h"
#include "PartieIV_2020.h"

Tenseur::Tenseur(int * tabd ,int dim){
  ordre = dim ;
  dimsval = new int[dim];
  int N = 1;
  for(int i = 0 ; i <dim ; i++)
  {
    N = N*tabd[i] ;
    dimsval[i] = tabd[i] ;
  }
  nbelts = N ;
  TenseurV = Vecteur(N) ;

}

Tenseur::Tenseur(int * tabd ,int dim, Vecteur tensv){
    ordre = dim ;
    dimsval = new int[dim];
    int N = 1;
    for(int i = 0 ; i <dim ; i++)
    {
      N = N*tabd[i] ;
      dimsval[i] = tabd[i] ;
    }
    TenseurV = tensv ;

}

Tenseur::~Tenseur(){
  delete dimsval ; // c'est le seul pointeur , destructeur de Vecteur existe deja
}


Tenseur::Tenseur(const Tenseur &T) { // recopie
  ordre = T.ordre ;
//copie de dimsval
  for(int i = 0 ; i <ordre ; i++)
  {
    dimsval[i] = T.dimsval[i] ;
  }

  nbelts = T.nbelts ;
  TenseurV = T.TenseurV ;

}


Tenseur::Tenseur(int * tabd ,int dim, int k, Matrice A ){
  ordre = dim ;
  dimsval = new int[dim];
  int N = 1;
  for(int i = 0 ; i <dim ; i++)
  {
    N = N*tabd[i] ;
    dimsval[i] = tabd[i] ;
  }
  nbelts = N ;
  int phi1d,jk ;
  int curseurboucle = 0 ;
  int Indice[dim] ;
  for(int i = 0 ; i<dim ; i++){
    Indice[i] = 1 ;
  }

  int * Vtabd = tabd ;
  bool boucleindice = true ;
  while(boucleindice){
    if(curseurboucle==(dim-1) ){ boucleindice =false ; }
    else
    {
      for(int i = 0 ; i<Vtabd[curseurboucle] ; i++) //il y a Vtabd[curseurboucle] valeur
      {
        jk = phijk(tabd ,dim, Indice , k ) ;
        phi1d = phi(tabd , dim, Indice) ;
        TenseurV[phi1d] = A[phi1d][jk] ;
        Indice[curseurboucle]++ ;
      }
      curseurboucle++;
    }
  }

}












int phijk(int * tabd ,int dim,int* i,int k){ //represente la position i1.....id
  int resphi;
  if(k!= dim ) { resphi =i[dim-1] ;}
  else{  }

  for( int l = (dim-2) ; l>0 ; l--)
  { // ici l'indice k-1 represente l'indice k du tenseur etc
    if(l<(k-1)  ) // car on travail sur un tableau indice decalé , commence a 0 de plus on ne veut pas l'indice k
    {
      resphi += tabd[l]*(i[l-1]-1) ;
    }
    else if(l>(k)){ // plus de probleme ak l'indice k
      resphi += tabd[l]*(i[l-1]-1) ;
    }
    else if (l == k) {
      resphi += tabd[l]*(i[l-2]-1) ; // on ne veut pasl'indice ik
    }

  }
  return resphi ;
}

int phi(int * tabd ,int dim,int* i){
  int resphi =i[dim-1] ;
  for( int l = (dim-2) ; l>0 ; l--){
    resphi += tabd[l]*(i[l-1]-1) ;
  }
  return resphi ;
}

void invphi(int * tabd, int dim,int i, int* indice){
return ;
}
