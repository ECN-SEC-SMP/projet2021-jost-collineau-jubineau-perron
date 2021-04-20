#include "gare.h"
//#include "joueur.h"

Gare::Gare(string nom, int id, Joueur* proprietaire, int prix) : Achetable(nom, id, proprietaire, prix)
{
  
}

bool Gare::acheter(Joueur* acheteur){
  bool b = true;
  b = Achetable::acheter(acheteur);
  acheteur->setNbGares(acheteur->getNbGares()+1);
  return b;
}

int Gare::calculLoyer()
{
  if(proprietaire != nullptr){
    int loyer = 0;
    if (this->proprietaire->getNbGares() == 4)
    {
      loyer = 5000;                               //Bonus si le joueur a toutes les gares
    }
    else
    {
      loyer = 1000 * this->proprietaire->getNbGares();
    }

    this -> setLoyer(loyer);
    
    return loyer;
  }
  return -1;
}

//Surchage de l'opérateur << pour l'affichage
ostream& operator<<(ostream& os, Gare c)
{
    os << c.getNom() << " (coût: " << to_string(c.getPrix()) << " ) ";
    if(c.getProprio() == nullptr){
      cout << "- sans proprietaire\n";
    }else{
      cout << "proprietaire: " << c.getProprio()->getNom() << ", ";

      cout << "loyer = " << to_string(c.getLoyer()) << "\n"; 
    }
    return os;
}