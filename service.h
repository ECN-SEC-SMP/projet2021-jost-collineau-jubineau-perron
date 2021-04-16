#pragma once
#include "achetable.h"

class Service : public Achetable
{ 
  public :
    Service();                          //Constructeur
    int calculLoyer(string nom);        //Calcul du loyer
};