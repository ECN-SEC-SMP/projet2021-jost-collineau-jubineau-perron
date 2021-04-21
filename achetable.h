#pragma once
#include "case.h"
#include "joueur.h"


/*
*	La classe Achetable permet d'abstraire une case achetable quelconque du plateau de jeu.
*	La classe Achetable est fille de la classe Case.
*	Cette classe n'a pas pour but d'être utilisée telle quelle, il s'agit en fait d'une 
*	classe mère de laquelle découleront les véritables cases qui constituerons notre plateau.
*	
* Les classes découlant de Case sont Gare, Constructible et Service.
*		Nous notons l'implémentation de la méthode isAchetable() qui permettra de différencier
*		ces les objets achetables des non achetables.
*		Nous notons la méthode purement virtuelle isAchetable() qui permettra de différencier
*		ces deux classes dans notre implémentation.
*/
class Achetable : public Case                             //Case achetable
{
  private :
    
	protected :
		int prix;							//Prix d'achat
    int loyer;  					//Loyer de la case une foix achetée
    Joueur* proprietaire; //pointeur vers le proprietaire

  public :
    Achetable(string nom, int id, Joueur* proprietaire, int prix);      //Constructeur

    bool acheter(Joueur* acheteur);
    virtual int calculLoyer() = 0;                        //Calcul du loyer

		Joueur* getProprio();
    
		int getPrix();
    
		int getLoyer();
    void setLoyer(int nouveauLoyer);
		
		bool isAchetable() { return true; }

    //Surcharge de l'opérateur <<
	  ostream& write( ostream& stm )const override; 
};