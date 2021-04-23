#pragma once
#include "achetable.h"
#include "joueur.h"
#include <stdio.h>

/**
* @class Constructible
*	La classe Constructible permet d'abstraire une case constructible quelconque du plateau de jeu.
*	La classe Constructible est fille de la classe Achetable.
*	Cette classe a pour but d'être utilisée directement, et sera utile pour créer notre plateau.
*	
* Nous notons la méthode calculLoyer() déclarée dans Achetable et redéfinie ici
*	avec son implémentation propre aux cases constructibles.
*/
class Constructible : public Achetable                    
{
  public :
    //@fn Constructible Constructeur
    Constructible(string nom, int id, Joueur* proprietaire, int prix);    

    //@fn calculLoyer Calcul du loyer. On prend un loyer de base (case non batie) correspondant à 50% du prix de vente
    int calculLoyer();	
		bool construire(int type);
    bool upgrade(int batToUpgrade);

    int getBat1();
    int getBat2();
    int getBat3();

    //@fn write Surcharge de l'opérateur <<
	  ostream& write( ostream& stm )const override;
  
  protected :
  
  // 0 - terrain
  // 1 - maison
  // 2 - hotel
    int nivBat1;				//@var nivBat1 Niveau du batiment 1
    int nivBat2;				//@var nivBat2 Niveau du batiment 2
    int nivBat3;				//@var nivBat3 Niveau du batiment 3
};
