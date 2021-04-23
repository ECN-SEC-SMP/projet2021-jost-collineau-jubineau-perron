#pragma once

#include "string"
#include <iostream>
using namespace std;

/**
*	@class Case
*	La classe Case permet d'abstraire une case quelconque du plateau de jeu. 
*	Cette classe n'a pas pour but d'être utilisée telle quelle, il s'agit en fait d'une 
*	classe mère de laquelle découleront les véritables cases qui constituerons notre plateau.
* 
* Les deux grandes classes découlant de Case sont Achetable et Non_achetable.
*	Nous notons la méthode purement virtuelle isAchetable() qui permettra de différencier
*	ces deux classes dans notre implémentation.
**/
class Case                              //Classe de base pour toutes les cases du plateau
{
  protected :
    string nom;                         //Nom de la case
    int id;                             //id de la case

  public :
    Case(string nom, int id);           //Constructeur
    string getNom(void);

		//Méthode abstraite : permet la différenciation entre cases de 
		//classe filles : achetables ou non achetables 
		virtual bool isAchetable()=0;		

		int getID();

	/**
    * @fn write 
    * Méthode virtuelle implémentée pour la classe mère et surchargée par
    * les classes filles
    * Surcharge de l'opérateur <<
    */
	  virtual ostream& write( ostream& stm )const;                       
};

ostream& operator<< ( ostream& stm, Case& c );