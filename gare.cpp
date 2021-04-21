#include "gare.h"

/*
*	Constructeur.
*/
Gare::Gare(string nom, int id, Joueur* proprietaire, int prix) : Achetable(nom, id, proprietaire, prix)
{
  
}

/*
*	Permet à un Joueur 'acheteur' d'acquérir la Gare et incrémente
*		le nombre de gares de l'acheteur.
*	retourne : 	- True si l'achat se fait correctement
*							- False si l'achat ne peut être effectué
*	Causes de l'échec : solde insuffisant OU propriétaire non nul.
*	ATTENTION n'a pas d'effet si la case a déjà un propriétaire.
*/
bool Gare::acheter(Joueur* acheteur)
{
  bool b = true;
  b = Achetable::acheter(acheteur);
  acheteur->setNbGares(acheteur->getNbGares()+1);
  return b;
}

/*
*	Retourne la valeur du loyer pour la Gare + MAJ attribut "loyer"
*/
int Gare::calculLoyer()
{
  if(proprietaire != nullptr)
  {
    int loyer = 25;
    if (this->proprietaire->getNbGares() == 4)loyer = 200;
    if (this->proprietaire->getNbGares() == 3)loyer = 100;
    if (this->proprietaire->getNbGares() == 2)loyer = 50;
    if (this->proprietaire->getNbGares() == 1)loyer = 25;

    this -> setLoyer(loyer);
    return loyer;
  }
  return -1;
}