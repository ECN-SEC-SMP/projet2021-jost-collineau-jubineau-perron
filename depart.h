#pragma once
#include "case.h"
#include "joueur.h"

class Depart : public Case
{ 
  public :
    Depart(string nom, int id);      //Constructeur
};

//Surchage de l'opérateur << pour l'affichage
ostream& operator<<(ostream& os, Depart c);