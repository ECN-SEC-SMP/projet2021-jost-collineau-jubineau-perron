#include "constructible.h"
#include "joueur.h"

Constructible::Constructible(string nom, int id, Joueur* propriétaire, int prix) : Achetable(nom, id, proprietaire, prix)
{
  this -> nivBat1 = 0;
  this -> nivBat2 = 0;
  this -> nivBat3 = 0;
}

//Surchage de l'opérateur << pour l'affichage
ostream& operator<<(ostream& os, Constructible c)
{
    os << c.proprietaire->getNom() << " (coût: " << to_string(c.prix) << " ) ";
    if(c.proprietaire == nullptr)){
      cout << "- sans proprietaire\n";
    }else{
      cout << "proprietaire: " << c.proprietaire->getNom() << ", ";

      int nbMaison = 0, nbHotel = 0;
      if(c.nivBat1 != 0)nbMaison++;
    }
    return os;
}