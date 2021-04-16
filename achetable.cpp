#include "achetable.h"

Achetable::Achetable() : Case(nom, id)
{
  this -> prix = prix;
  this -> proprietaire = proprietaire;
}

joueur* Achetable::getProprio()
{
	return this -> proprietaire;
}