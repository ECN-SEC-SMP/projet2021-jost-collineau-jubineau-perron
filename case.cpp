#include "case.h"

/*
*	Constructeur
*/
Case::Case(string nom, int id)
{
  this->nom = nom;
  this->id = id;
}

/*
*	Retourne le nom de la case.
*/
string Case::getNom(){
  return this->nom;
}

/*
*	Affiche toutes les informations de la case.
*/
ostream& Case::write( ostream& stm )const
{ 
  return stm << id << " - " << this->nom << endl ;
} 

/*
*	Retourne l'id de la case.
*/
int Case::getID() {
	return this->id;
};

//Surchage de l'opérateur << pour l'affichage
ostream& operator<< ( ostream& stm, Case& c ) { return c.write(stm) ; }