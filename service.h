#pragma once
#include "achetable.h"

class Service : public Achetable
{ 
  public :
    Service(string nom, int id, Joueur* propriétaire, int prix);      //Constructeur
    int calculLoyer(string nom);                                      //Calcul du loyer
};