#include "service.h"

Service::Service(string nom, int id, Joueur* proprietaire, int prix) : Achetable(nom, id, proprietaire, prix)
{
  
}

void Service::afficher(void){
  cout << this->nom << " (coût: " << to_string(prix) << " ) ";
  if(proprietaire == nullptr){
    cout << "- sans proprietaire\n";
  }else{
    cout << "proprietaire: " << proprietaire->getNom() << ", ";

    cout << ", loyer = " << to_string(loyer) << "\n"; 
  }
}

int Service::calculLoyer() {
	// A IMPLEMENTER
	return 0;
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