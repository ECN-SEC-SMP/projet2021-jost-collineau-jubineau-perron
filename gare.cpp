#include "gare.h"
//#include "joueur.h"

Gare::Gare(string nom, int id, Joueur* proprietaire, int prix) : Achetable(nom, id, proprietaire, prix)
{
  
}

bool Gare::acheter(Joueur* acheteur)
{
  bool b = true;
  b = Achetable::acheter(acheteur);
  acheteur->setNbGares(acheteur->getNbGares()+1);
  return b;
}

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

//Surchage de l'opérateur << pour l'affichage
ostream& operator<<(ostream& os, Gare c)
{
    os << c.getNom() << " (coût: " << to_string(c.getPrix()) << " ) ";
    if(c.getProprio() == nullptr)
    {
      cout << "- sans proprietaire\n";
    }
    else
    {
      cout << "proprietaire: " << c.getProprio()->getNom() << ", ";

      cout << "loyer = " << to_string(c.getLoyer()) << "\n"; 
    }
    return os;
}