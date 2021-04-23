#pragma once
#include "case.h"
#include "joueur.h"

/**
* @class Non_achetable
*	La classe Non_achetable permet d'abstraire les cases non achetables (ex : depart) 
*	du plateau de jeu.
*	La classe Non_achetable est fille de la classe Case.
*	Cette classe n'a pas pour but d'être utilisée telle quelle, il s'agit en fait d'une 
*	classe mère de laquelle découleront les véritables cases qui constituerons notre plateau.
*	
* Nous notons la méthode isAchetable() présente dans la classe Case et redéfinie ici.
*/

class Non_achetable : public Case                             //Case non achetable
{
  public :
  //@fn Non_achetable Constructeur
    Non_achetable(string nom, int id);               
		bool isAchetable(){return false;};
};