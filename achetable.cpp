#include "achetable.h"

/*
*	Constructeur.
*/
Achetable::Achetable(string nom, int id, Joueur* proprietaire, int prix) : Case(nom, id) {
  this -> prix = prix;
  this -> proprietaire = proprietaire;
}

/*
*	Permet à un Joueur 'acheteur' d'acquérir l'Achetable.
*	retourne : 	- True si l'achat se fait correctement
*							- False si l'achat ne peut être effectué
*	Causes de l'écher : solde insuffisant OU propriétaire non nul.
*	ATTENTION n'a pas d'effet si la case a déjà un propriétaire.
*/
bool Achetable::acheter(Joueur* acheteur) {
  if (this -> proprietaire == NULL)
  {
    if( acheteur->getFortune() >= this->prix)
    {
      int nouveauSolde = ( acheteur->getFortune() - this->prix );
      acheteur->setFortune(nouveauSolde);		//MAJ fortune acheteur
			this->proprietaire = acheteur;				//MAJ propriétaire
      return true;
    }
    else {return false;}
  }
  else {return false;}
}

/*
*	Affiche toutes les informations de la case. Surcharge la méthode afficher de Case.
*	Infos particulières : propriétaire, loyer, cout d'achat.
*/
ostream& Achetable::write( ostream& stm )const {
  stm << id << " - " << this->nom << " (coût: " << to_string(this->prix) << " ) ";
  if(this->proprietaire == nullptr){
    stm << "- sans proprietaire\n";
  }else{
    stm << "proprietaire: " << this->proprietaire->getNom() << ", ";

    stm << ", loyer = " << to_string(this->loyer) << "\n"; 
  }
  return stm;
}

/*
*	Retourne un pointeur sur le propriétaire de la case.
*	ATTENTION : le type est Joueur *.
*/
Joueur* Achetable::getProprio() {
	return this->proprietaire;
}

/*
*	Retourne le prix d'achat de la case.
*/
int Achetable::getPrix() {
  return this->prix;
}

/*
*	\brief Calcule puis retourne la valeur du loyer actuelle pour l'Achetable.
*	ATTENTION la médhode calculLoyer appelée est virtuelle pure et doit donc être
*	implémentée dans la classe fille.
*/
int Achetable::getLoyer() {
	calculLoyer();
  return this->loyer;
}

/*
*	Permet e fixer de façon absolue le loyer pour l'Achetable.
*/
void Achetable::setLoyer(int nouveauLoyer) {
  this->loyer = nouveauLoyer;
}