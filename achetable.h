#pragma once
#include "case.h"
#include "joueur.h"

class Achetable : public Case                             //Case achetable
{
  private :
    
	protected :
		int prix;                                             //Prix d'achat
    int loyer;  //Loyer de la case une foix achetée
    Joueur* proprietaire;  //pointeur vers le proprietaire

  public :
    Achetable(string nom, int id, Joueur* proprietaire, int prix);      //Constructeur

    bool acheter(Joueur* acheteur);                             //Fonction d'achat. Renvoie 1 si l'achat se fait, 0 sinon
    virtual int calculLoyer() = 0;                        //Calcul du loyer
		Joueur* getProprio();
    int getPrix();
    int getLoyer();
    void setLoyer(int nouveauLoyer);
    void afficher(void) override;
		bool isAchetable() {return true;}
};