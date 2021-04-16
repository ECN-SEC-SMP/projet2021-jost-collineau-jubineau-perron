#pragma once
#include "achetable.h"

class Gare : public Achetable
{
  public :
    Gare(string nom, int id, Joueur* proprietaire, int prix);         //Constructeur
    int calculLoyer(string nom);                                      //Calcul du loyer
};
