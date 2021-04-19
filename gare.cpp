#include "gare.h"
//#include "joueur.h"

Gare::Gare(string nom, int id, Joueur* proprietaire, int prix) : Achetable(nom, id, proprietaire, prix)
{
  
}

int Plateau::nbGares(Joueur *J){
	int varGares = 0;
	Gare *GarePtr;
	
	//Pour chaque position de gare (manuellement) :
	GarePtr = (Gare*) cases[5];             //Changer le fonctionnement et mettre une varible pour chaque joueur qui s'incrémente dés qu'il achète une nouvelle gare
	if ( GarePtr->getProprio()->getNom() == J->getNom()) varGares ++;
	GarePtr = (Gare*) cases[15];
	if ( GarePtr->getProprio()->getNom() == J->getNom()) varGares ++;
	GarePtr = (Gare*) cases[25];
	if ( GarePtr->getProprio()->getNom() == J->getNom()) varGares ++;
	GarePtr = (Gare*) cases[35];
	if ( GarePtr->getProprio()->getNom() == J->getNom()) varGares ++;
	return varGares;
}

int Gare::calculLoyer(Plateau *p)
{
  int loyer = 0;
  if (p->nbGares(this -> getProprio()) == 4)
  {
    loyer = 5000;                               //Bonus si le joueur a toutes les gares
  }
  else
  {
    loyer = 1000 * (p->nbGares(this -> getProprio()));
  }

  this -> setLoyer(loyer);
  
  return loyer;
}

//Surchage de l'opérateur << pour l'affichage
void Gare::afficher(void)
{
    cout << this->nom << " (coût: " << to_string(this->prix) << " ) ";
    if(this->proprietaire == nullptr){
      cout << "- sans proprietaire\n";
    }else{
      cout << "proprietaire: " << this->proprietaire->getNom() << ", ";

      cout << ", loyer = " << to_string(this->loyer) << "\n"; 
    }
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