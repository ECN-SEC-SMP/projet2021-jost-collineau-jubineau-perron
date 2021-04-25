#pragma once
#include "achetable.h"
#include "plateau.h"

/**
* @class Gare
*	La classe Gare permet d'abstraire les gares du plateau de jeu.
*	La classe Gare est fille de la classe Achetable.
*	Cette classe a pour but d'être utilisée directement, et sera utile pour créer notre plateau.
*	
* Nous notons la méthode calculLoyer() déclarée dans Achetable et redéfinie ici
*	avec son implémentation propre aux gares.
*/

class Gare : public Achetable
{
  public :
  	//@fn Gare Constructeur
    Gare(string nom, int id, Joueur* proprietaire, int prix);         
    
    //@fn calculLoyer Calcul du loyer
    int calculLoyer();  
		//@fn acheter Permet d'attribuer un propriétaire contre paiement. Retourne true si achat ok.
    bool acheter(Joueur* acheteur) override;                    
};
