#pragma once
#include "achetable.h"
#include "plateau.h"

class Gare : public Achetable
{
  public :
    Gare(string nom, int id, Joueur* proprietaire, int prix);         //Constructeur
    int calculLoyer();                                      //Calcul du loyer
    
    bool acheter(Joueur* acheteur);                    
};

//Surchage de l'opérateur << pour l'affichage
ostream& operator<<(ostream& os, Gare c);
