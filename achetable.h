#pragma once
#include "case.h"
#include "joueur.h"

class Achetable : public Case                             //Case achetable
{
  private :
    
	protected :
		int prix;                                             //Prix d'achat
    int loyer  //Loyer 

  public :
    Achetable(string nom, int id, joueur* proprietaire, int prix);      //Constructeur

    bool acheter(string nom);                             //Fonction d'achat et de transfer de propriété
    int virtual calculLoyer(string nom);                  //Calcul du loyer
		joueur* getProprio();
    joueur* proprietaire;                                     //pointeur vers le proprietaire
};