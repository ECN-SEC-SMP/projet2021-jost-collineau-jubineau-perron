#pragma once
#include "case.h"
#include "joueur.h"

class Non_achetable : public Case                             //Case non achetable
{
  public :
    Non_achetable(string nom, int id);               //Constructeur
		bool isAchetable(){return false;};
};