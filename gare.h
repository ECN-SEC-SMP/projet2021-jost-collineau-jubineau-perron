#pragma once
#include "achetable.h"
#include "plateau.h"

class Gare : public Achetable
{
  public :
  //@fn Gare Constructeur
    Gare(string nom, int id, Joueur* proprietaire, int prix);         
    
    //@fn calculLoyer Calcul du loyer
    int calculLoyer();                                      
    bool acheter(Joueur* acheteur);                    
};
