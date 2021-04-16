#pragma once
#include "achetable.h"

class Gare : public Achetable
{
  public :
    Gare();                              //Constructeur
    int calculLoyer(string nom);         //Calcul du loyer
};
