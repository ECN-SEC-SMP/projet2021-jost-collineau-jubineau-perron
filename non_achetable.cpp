#include "non_achetable.h"

/*
*	Constructeur.
*/
Non_achetable::Non_achetable(string nom, int id) : Case(nom, id)
{
	this->nom = nom;
	this->id = id;
}
