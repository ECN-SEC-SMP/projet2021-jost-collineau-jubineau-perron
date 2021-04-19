#include "gare.h"
//#include "joueur.h"

Gare::Gare(string nom, int id, Joueur* proprietaire, int prix) : Achetable(nom, id, proprietaire, prix)
{
  
}

int Gare::calculLoyer(Plateau *p, Joueur *J)
{
  int loyer = 2500 * (p->nbGares(J));
  return loyer;
}

//Surchage de l'opérateur << pour l'affichage
ostream& operator<<(ostream& os, Gare c)
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