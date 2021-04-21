#pragma once
#include "achetable.h"
#include "joueur.h"

class Service : public Achetable
{ 
  public :
    Service(string nom, int id, Joueur* proprietaire, int prix);      //Constructeur
    
    bool acheter(Joueur* acheteur);                         
		int calculLoyer();	 //Calcul du loyer
    void afficher(void);            
};

//Surchage de l'opérateur << pour l'affichage
ostream& operator<<(ostream& os, Service c);