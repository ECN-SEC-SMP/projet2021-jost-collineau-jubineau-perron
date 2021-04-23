#include "depart.h"
#include "non_achetable.h"

/*
*	Constructeur.
*/
Depart::Depart(string nom, int id) : Non_achetable(nom, id){
  this->nom = nom;
	this->id = id;
}