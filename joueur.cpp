#include "joueur.h"

Joueur::Joueur(){
}

Joueur::Joueur(string name)
{
  this-> nom = name;   //on set le nom du joueur avec celui donné en paramètre
  this-> fortune = 200;  //on initialise la fortune du joueur à 100000 en début de partie
  this-> position = 0;  //on initialise la position du joueur à 0
	this->isFaillite = false;
}

//permet de payer un joueur PEU IMPORTE LE SOLDE
bool Joueur::payer(Joueur* j, int price)  
{
  cout << this->nom << " veut payer " 
			 << price			<< " a " 
			 << j->getNom() << "..." ;

  this->fortune = this->fortune - price;  //soustraire le prix à la fortune du joueur
  j->setFortune(j->getFortune() + price );                   //ajouter la valeur du prix à payer à l'autre joueur
  cout << "paiement ok." << endl;
  return true;
}

void Joueur::deplacer(int deplacement)  //permet de déplacer le joueur en fonction de la valeur en paramètre
{
  this->position = (this->position + deplacement)%40; //modulo 40 pour boucler sur le plateau
  //cout<<this->nom<<" se retrouve en case "<<this->position<<endl;
  cout<<endl;
}

string Joueur::getNom() const
{
  return (this->nom);  //retourne le nom du joueur
}

void Joueur::setFortune(int money)
{
  this->fortune = money;  //permet de modifier la fortune
}

void Joueur::addFortune(int money)
{
  this->fortune += money;
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
  cout << "Position = " << this->getPosition()+1 << endl;
  cout << "           "<< endl;
}

void Joueur::setPosition(int newPos){
  position = newPos;
}

void Joueur::setNbGares(int n)
{
  this -> nbGares = n;
}


int Joueur::getNbGares(void)
{
  return (this -> nbGares);
}

void Joueur::setNbServices(int n)
{
  this -> nbServices = n;
}

int Joueur::getNbServices(void)
{
  return (this -> nbServices);
}

void Joueur::setFaillite(bool etat){
	this->isFaillite = etat;
}

bool Joueur::getFaillite(){
	return this->isFaillite;
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