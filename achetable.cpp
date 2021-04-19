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

int Achetable::getPrix(){
  return this->prix;
}

int Achetable::getLoyer(){
  return this->loyer;
}

void Achetable::setLoyer(int nouveauLoyer)
{
  this -> loyer = nouveauLoyer;
}

bool Achetable::acheter(Joueur* acheteur)
{
  if (this -> proprietaire != NULL)
  {
    if(this -> proprietaire -> getFortune() >= this -> prix)
    {
      int nouveauSolde = (this -> proprietaire -> getFortune()) - (this -> prix);
      this -> proprietaire -> setFortune(nouveauSolde);
    }
    else {return false;}
  }
  else {return false;}
}

/*
//Surchage de l'opérateur << pour l'affichage
ostream& Achetable::operator<<(ostream& os, Achetable c){
  os << c.getNom();
    return os;
}*/