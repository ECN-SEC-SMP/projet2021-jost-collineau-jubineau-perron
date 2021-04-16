#include "achetable.h"

Achetable::Achetable(string nom, int id, Joueur* proprietaire, int prix) : Case(nom, id)
{
  this -> prix = prix;
  this -> proprietaire = proprietaire;
}

Joueur* Achetable::getProprio()
{
	return this -> proprietaire;
}