#pragma once
#include "achetable.h"

class Constructible : public Achetable                    //Case constructible
{
  public :
    Constructible(string nom, int id, Joueur* proprietaire, int prix);    //Constructeur

    int calculLoyer(string nom);                          //Calcul du loyer
    bool construire(int type);
    bool upgrade(int batToUpgrade);
  
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