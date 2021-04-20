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
	this->calculLoyer();
  return this->loyer;
}

void Achetable::setLoyer(int nouveauLoyer)
{
  this -> loyer = nouveauLoyer;
}

bool Achetable::acheter(Joueur* acheteur)
{
  if (this -> proprietaire == NULL)
  {
    if( acheteur -> getFortune() >= this -> prix)
    {
      int nouveauSolde = ( acheteur -> getFortune()) - (this -> prix);
      acheteur -> setFortune(nouveauSolde);
			this -> proprietaire = acheteur;
      return true;
    }
    else {return false;}
  }
  else {return false;}
}

void Achetable::afficher(void)
{
    cout << id << " - " << this->nom << " (coût: " << to_string(this->prix) << " ) ";
    if(this->proprietaire == nullptr){
      cout << "- sans proprietaire\n";
    }else{
      cout << "proprietaire: " << this->proprietaire->getNom() << ", ";

      cout << ", loyer = " << to_string(this->loyer) << "\n"; 
    }
}

/*
//Surchage de l'opérateur << pour l'affichage
ostream& Achetable::operator<<(ostream& os, Achetable c){
  os << c.getNom();
    return os;
}*/