#pragma once
#include "case.h"
#include "non_achetable.h"
#include "joueur.h"

class Depart : public Non_achetable
{ 
  public :
    Depart(string nom, int id);      //Constructeur
};

//Surchage de l'opérateur << pour l'affichage
ostream& operator<<(ostream& os, Depart c);