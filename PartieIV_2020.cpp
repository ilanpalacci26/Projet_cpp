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
//dimsval et calcule de nbelts
  dimsval = new int[dim];
  int N = 1;
  for(int i = 0 ; i <dim ; i++)
  {
    N = N*tabd[i] ;
    dimsval[i] = tabd[i] ;
  }
  nbelts = N ;

  TenseurV = Vecteur(nbelts) ;
  int phi1d,jk ;
  int indice[nbelts] ;
//on se balade le long du vecteur , trouve le couple i1..id et identify a la matrice
  for (int i = 1 ; i<(nbelts+1) ; i++){
      invphi(dimsval, ordre, i , indice ) ;
      jk = phijk(dimsval, ordre, indice, k) ;
      TenseurV[i] = A[indice[k-1]][jk] ;
  }
}


int phijk(int * tabd ,int dim,int* indice,int k){ //represente la position i1.....id
  int resphi;
  if(k!= dim ) { resphi =indice[dim-1] ;}
  else{  }

  for( int l = (dim-2) ; l>0 ; l--)
  { // ici l'indice k-1 represente l'indice k du tenseur etc
    if(l<(k-1)  ) // car on travail sur un tableau indice decalé , commence a 0 de plus on ne veut pas l'indice k
    {
      resphi += tabd[l]*(indice[l-1]-1) ;
    }
    else if(l>(k)){ // plus de probleme ak l'indice k
      resphi += tabd[l]*(indice[l-1]-1) ;
    }
    else if (l == k) {
      resphi += tabd[l]*(indice[l-2]-1) ; // on ne veut pasl'indice ik
    }

  }
  return resphi ;
}

int phi(int * tabd ,int dim,int* indice){
  int resphi =indice[dim-1] ;
  for( int l = (dim-2) ; l>0 ; l--){
    resphi += tabd[l]*(indice[l-1]-1) ;
  }
  return resphi ;
}


void invphi(int * tabd, int dim,int i, int* indice){

  int it ;
  int ft_1 ;
  int ft ;
  //ici imaginons t_1 = d ;
  ft_1 = i ;
  indice[dim-1] = ft_1%tabd[dim-1] ;
  for (int t = (dim-1); t > 0 ; t++){

    ft = 1 + ( ft_1 - indice[t]) / tabd[t] ;
    ft_1 = ft ;
    indice[t-1] = ft%tabd[t-1] ;

  }

return ;
}
