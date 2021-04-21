#include "service.h"

Service::Service(string nom, int id, Joueur* proprietaire, int prix) : Achetable(nom, id, proprietaire, prix)
{
  
}

bool Service::acheter(Joueur* acheteur)
{
  bool b = true;
  b = Achetable::acheter(acheteur);
  acheteur->setNbServices(acheteur->getNbServices()+1);
  return b;
}

void Service::afficher(void){
  cout << this->id << " - " << this->nom << " (coût: " << to_string(prix) << " ) ";
  if(proprietaire == nullptr){
    cout << "- sans proprietaire\n";
  }else{
    cout << "proprietaire: " << proprietaire->getNom() << ", ";

    cout << ", loyer = " << to_string(loyer) << "\n"; 
  }
}

int Service::calculLoyer() 
{
  if(proprietaire != nullptr)
  {
    int loyer = 0;
    if (this->proprietaire->getNbServices() == 2)
    {
      loyer = 2500;                               //Bonus si le joueur a tous les services
    }
    else
    {
      loyer = 1000 * this->proprietaire->getNbServices();
    }

    this -> setLoyer(loyer);
    
    return loyer;
  }
  return -1;
}

//Surchage de l'opérateur << pour l'affichage
ostream& operator<<(ostream& os, Service c)
{
    os << c.getNom() << " (coût: " << to_string(c.getPrix()) << " ) ";
    if(c.getProprio() == nullptr){
      cout << "- sans proprietaire\n";
    }else{
      cout << "proprietaire: " << c.getProprio()->getNom() << ", ";

      cout << ", loyer = " << to_string(c.getLoyer()) << "\n"; 
    }
    return os;
}