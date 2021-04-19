#pragma once
#include "achetable.h"
#include "joueur.h"
#include <stdio.h>

//Case constructible
class Constructible : public Achetable                    
{
  public :
    Constructible(string nom, int id, Joueur* proprietaire, int prix);    //Constructeur

    int calculLoyer(void);                          //Calcul du loyer. On prend un loyer de base (case non batie) correspondant à 50% du prix de vente
    bool construire(int type);
    bool upgrade(int batToUpgrade);

    int getBat1();
    int getBat2();
    int getBat3();
  
  protected :
  
  // 0 - terrain
  // 1 - maison
  // 2 - hotel
    int nivBat1;                                          //Niveau du batiment 1
    int nivBat2;                                          //Niveau du batiment 2
    int nivBat3;                                          //Niveau du batiment 3
};

//Surchage de l'opérateur << pour l'affichage
ostream& operator<<(ostream& os, Constructible c);