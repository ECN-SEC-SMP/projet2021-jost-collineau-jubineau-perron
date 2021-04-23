#pragma once
#include "case.h"
#include "joueur.h"


/**
* @class Achetable
*	La classe Achetable permet d'abstraire une case achetable quelconque du plateau de jeu.
*	La classe Achetable est fille de la classe Case.
*	Cette classe n'a pas pour but d'être utilisée telle quelle, il s'agit en fait d'une 
*	classe mère de laquelle découleront les véritables cases qui constituerons notre plateau.
*	
* Les classes découlant de Case sont Gare, Constructible et Service.
*		Nous notons l'implémentation de la méthode isAchetable(), virtuelle dans Case,
*		qui permettra de différencier ces les objets achetables des non achetables.
*/
class Achetable : public Case                             //Case achetable
{
  private :
    
	protected :
		int prix;							//@var prix Prix d'achat
    int loyer;  					//@var loyer Loyer de la case une foix achetée
    Joueur* proprietaire; //@var proprietaire pointeur vers le proprietaire

  public :
    //@fn Achetable Constructeur
    Achetable(string nom, int id, Joueur* proprietaire, int prix);      

    bool acheter(Joueur* acheteur);

    //@fn calculLoyer Calcul du loyer
    virtual int calculLoyer() = 0;                        

		Joueur* getProprio();
    
		int getPrix();
    
		int getLoyer();
    void setLoyer(int nouveauLoyer);
		
		bool isAchetable()override { return true; }

    //@fn write Surcharge de l'opérateur <<
	  ostream& write( ostream& stm )const override; 
};