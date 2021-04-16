#pragma once

#include "string"
#include <iostream>
using namespace std;

class Case                                  //Classe de base pour toutes les cases du plateau
{
  public :
    Case(string nom, int id);               //Constructeur
    string getNom(void);

  protected :
    string nom;                             //Nom de la case
    int id;                                 //id de la case
};

