#pragma once
#include "achetable.h"
#include "joueur.h"

class Service : public Achetable
{ 
  public :
  //@fn Service Constructeur
    Service(string nom, int id, Joueur* proprietaire, int prix);      
    
    bool acheter(Joueur* acheteur);                         
		int calculLoyer();	 //Calcul du loyer
    void afficher(void);            
};

//@fn operator<< Surchage de l'opérateur << pour l'affichage
//@see write
ostream& operator<<(ostream& os, Service c);