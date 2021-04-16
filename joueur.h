#include "plateau.h"

#pragma once
#include "string"
#include <iostream>
using namespace std;

class Joueur
{
  private :
    int fortune;
    string nom;
    int id;
    int position;

  public :
    Joueur();
    Joueur(string name);
    Plateau *refplateau;

    bool payer(Joueur* j, int price);
    void deplacer(int deplacement);
    
    string getNom() const;
    void setFortune(int money);
};