#include "constructible.h"
//#include "joueur.h"

Constructible::Constructible(string nom, int id, Joueur* propriétaire, int prix) : Achetable(nom, id, proprietaire, prix)
{
  this -> nivBat1 = 0;
  this -> nivBat2 = 0;
  this -> nivBat3 = 0;
}

int Constructible::getBat1(){
  return this->nivBat1;
}

int Constructible::getBat2(){
  return this->nivBat2;
}

int Constructible::getBat3(){
  return this->nivBat3;
}

//Surchage de l'opérateur << pour l'affichage
ostream& operator<<(ostream& os, Constructible c)
{
    os << c.getProprio()->getNom() << " (coût: " << to_string(c.getPrix()) << " ) ";
    if(c.getProprio() == nullptr){
      cout << "- sans proprietaire\n";
    }else{
      cout << "proprietaire: " << c.getProprio()->getNom() << ", ";

      int nbMaison = 0, nbHotel = 0;
      if(c.getBat1() == 1)nbMaison++;
      if(c.getBat1() == 2)nbHotel++;
      
      if(c.getBat2() == 1)nbMaison++;
      if(c.getBat2() == 2)nbHotel++;

      if(c.getBat3() == 1)nbMaison++;
      if(c.getBat3() == 2)nbHotel++;

      if(nbMaison != 0){ cout << to_string(nbMaison) << " maisons " ;}
      if(nbHotel){ cout << to_string(nbHotel) << " hotels";}

      cout << ", loyer = " << to_string(c.getLoyer()) << "\n"; 
    }
    return os;
}