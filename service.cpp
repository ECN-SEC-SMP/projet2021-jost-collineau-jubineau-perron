#include "service.h"

/*
*	Constructeur.
*/
Service::Service(string nom, int id, Joueur* proprietaire, int prix) : Achetable(nom, id, proprietaire, prix)
{
  
}

/*
*	Permet à un Joueur 'acheteur' d'acquérir le Service et incrémente
*		le nombre de getNbServices de l'acheteur.
*	retourne : 	- True si l'achat se fait correctement
*							- False si l'achat ne peut être effectué
*	Causes de l'échec : solde insuffisant OU propriétaire non nul.
*	ATTENTION n'a pas d'effet si la case a déjà un propriétaire.
*/
bool Service::acheter(Joueur* acheteur)
{
  bool b = true;
  b = Achetable::acheter(acheteur);
  acheteur->addService();
  return b;
}

/*
*	Retourne la valeur du loyer pour le Service + MAJ attribut "loyer"
*	Retourne -1 si la case n'a pas de propriétaire.
*/
int Service::calculLoyer() 
{
  if(proprietaire != nullptr) {
    int loyer = 0;
    if (this->proprietaire->getNbServices() == 2) {
      loyer = 2500;			//Bonus si le joueur a tous les services
    }
    else {
      loyer = 1000 * this->proprietaire->getNbServices();
    }

    this->setLoyer(loyer);
    return loyer;
  }
  return -1;
}

/*
*	Affiche toutes les informations de la case. Surcharge la méthode afficher de Case.
*	Infos particulières : propriétaire, loyer, cout d'achat.
*/
void Service::afficher(void){
  cout << this->id << " - " << this->nom << " (coût: " << to_string(prix) << " ) ";
  if(proprietaire == nullptr){
    cout << "- sans proprietaire\n";
  }else{
    cout << "proprietaire: " << proprietaire->getNom() << ", ";

    cout << ", loyer = " << to_string(loyer) << "\n"; 
  }
}

/*
*	Surchage de l'opérateur << pour l'affichage
*/
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