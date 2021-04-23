#pragma once
#include "case.h"
#include "joueur.h"

class Non_achetable : public Case                             //Case non achetable
{
  public :
  //@fn Non_achetable Constructeur
    Non_achetable(string nom, int id);               
		bool isAchetable(){return false;};
};