#include "joueur.h"

Joueur::Joueur(){
}

Joueur::Joueur(string name)
{
  this-> nom = name;   //on set le nom du joueur avec celui donné en paramètre
  this-> fortune = 100000;  //on initialise la fortune du joueur à 100000 en début de partie
  this-> position = 0;  //on initialise la position du joueur à 0
}

bool Joueur::payer(Joueur* j, int price)  //permet de payer un joueur
{
  cout<<this->nom<<" doit payer "<<price<<" a "<<j->getNom()<<endl;
  cout<<endl;
  if(this->fortune >= price)  //si la fortune du joueur est inférieure ou égale au prix à payer...
  {
    this->fortune = this->fortune - price;  //soustraire le prix à la fortune du joueur
    j->setFortune(price);                   //ajouter la valeur du prix à payer à l'autre joueur
    
    return true;
  }
  else
  {
    return false; //si le prix est plus élevé que la fortune du joueur, on retourne false
  }
}

void Joueur::deplacer(int deplacement)  //permet de déplacer le joueur en fonction de la valeur en paramètre
{
  this->position = (this->position + deplacement)%40; //modulo 40 pour boucler sur le plateau
  cout<<this->nom<<" se retrouve en case "<<this->position<<endl;
  cout<<endl;
}

string Joueur::getNom() const
{
  return (this->nom);  //retourne le nom du joueur
}

void Joueur::setFortune(int money)
{
  this->fortune = this->fortune + money;  //permet d'ajouter de l'argent à la fortune du joueur
}

int Joueur::getFortune() const
{
  return (this->fortune);
}

int Joueur::getPosition() const
{
  return (this->position);
}

void Joueur::afficher_info_joueur()
{
  cout << "   INFO JOUEUR   " << endl;
  cout << "Nom = " << this->getNom() << endl;
  cout << "Fortune = " << this->getFortune() << endl;
  cout << "Position = " << this->getPosition() << endl;
  cout << "           "<< endl;
}

/*
void Joueur::tourDeJeu(){
	int faceDe = lancerDe();
	this->deplacer(faceDe);
	cout << "le joueur " << this->getNom() << "passe en case n." << this->getPosition();
	if ( !( faceDe % 2 == 0)){	// lancer de dé impair
		if (refplateau-> )
	}	
	return;
}*/