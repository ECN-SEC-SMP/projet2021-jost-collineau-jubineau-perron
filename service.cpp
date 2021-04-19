#include "service.h"

Service::Service(string nom, int id, Joueur* proprietaire, int prix) : Achetable(nom, id, proprietaire, prix)
{
  
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