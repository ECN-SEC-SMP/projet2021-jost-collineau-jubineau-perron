#pragma once
#include "achetable.h"
#include "joueur.h"
#include <stdio.h>

//Case constructible
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
