#pragma once
#include "case.h"
#include "non_achetable.h"
#include "joueur.h"

/**
* @class Depart
*	La classe Depart permet d'abstraire la case départ du plateau de jeu.
*	La classe Depart est fille de la classe Non_achetable.
*	Cette classe a pour but d'être utilisée directement, et sera utile pour créer notre plateau.
*	
* Nous implémenterons le fonctionnement de cette case par la suite.
*/

class Depart : public Non_achetable
{ 
  public :
    //@fn Depart Constructeur
    Depart(string nom, int id);      
};