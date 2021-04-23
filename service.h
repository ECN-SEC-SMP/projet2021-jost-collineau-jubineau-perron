#pragma once
#include "achetable.h"
#include "joueur.h"

/**
* @class Service
*	La classe Service permet d'abstraire les cases de service du plateau de jeu.
*	La classe Service est fille de la classe Achetable.
*	Cette classe a pour but d'être utilisée directement, et sera utile pour créer notre plateau.
*	
* Nous notons la méthode calculLoyer() déclarée dans Achetable et redéfinie ici
*	avec son implémentation propre aux services.
*/

class Service : public Achetable
{ 
  public :
  //@fn Service Constructeur
    Service(string nom, int id, Joueur* proprietaire, int prix);      
    
		int calculLoyer();	 //@fn calculLoyer Calcul du loyer
    bool acheter(Joueur* acheteur);                         
    void afficher(void);            
};

//@fn operator<< Surchage de l'opérateur << pour l'affichage
//@see write
ostream& operator<<(ostream& os, Service c);