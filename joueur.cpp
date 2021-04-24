#include "joueur.h"

/*
*	Constructeur.
*/
Joueur::Joueur(){
	this->nom = "unnamed";
	this->fortune = 1000;  //on initialise la fortune du joueur à 1000 en début de partie
  this->position = 0;  //on initialise la position du joueur à 0
	this->isFaillite = false;
  this->tourFait = false;
}

/*
*	Constructeur.
*/
Joueur::Joueur(string name)
{
  this->nom = name;   //on set le nom du joueur avec celui donné en paramètre
  this->fortune = 1000;  //on initialise la fortune du joueur à 1000 en début de partie
  this->position = 0;  //on initialise la position du joueur à 0
	this->isFaillite = false;
  this->tourFait = false;
}

/*
* Permet d'incrémenter la fortune courrante.
*/
void Joueur::addFortune(int money)
{
  this->fortune += money;
}

/*
* Permet d'incrémenter le nombre de services.
*/
void Joueur::addService()
{
  nbServices++;
}

/*
* Permet de transférer une somme "price" du joueur courant vers le joueur J
* 	Retourne : 	- True si le paiement s'effectue sans problèmes
*								- False si la fortune est insuffisante
*	Si la fortune n'est pas suffisante, on fait :
*		- fortune = 0
*		- faillite = true
*/
bool Joueur::payer(Joueur* j, int price)  
{
  cout << this->nom << " veut payer " 
			 << price			<< " a " 
			 << j->getNom() << "\n" ;
  
  // Fortune suffisante :
  if( this->fortune > price){
    this->fortune = this->fortune - price;  	//soustraire le prix à la fortune du joueur
    j->setFortune(j->getFortune() + price );	//ajouter la valeur du prix à payer à l'autre joueur
		cout << "paiement ok." << endl;
    return true;
  }

  //Fortune insuffisante :
  else {
    cout << "Pas assez de fonds" << endl;
    isFaillite = true;
    fortune=0;
    cout << "\e[0;31m" << nom << " est en FAILLITE\e[0m" << endl;
    return false;
  }
}

/*
* Permet de modifier la position d'un joueur sur le plateau.
* La position actuelle est incrémentée de la valeur de "deplacement"
*/
void Joueur::deplacer(int deplacement)  //permet de déplacer le joueur en fonction de la valeur en paramètre
{
  int oldPos=this->position;
  this->position = (this->position + deplacement)%40; //modulo 40 pour boucler sur le plateau
  if((position+deplacement)-oldPos < 0){
    cout << "Passage par la case départ !" << endl;
    this->fortune += 200;
  }
}

/*
* Affiche à l'écran toutes les informations sur le Joueur.
*/
void Joueur::afficher_info_joueur()
{
  cout << "   INFO JOUEUR   " << endl;
  cout << "Nom = " << this->getNom() << endl;
  cout << "Fortune = " << this->getFortune() << endl;
  cout << "Position = " << this->getPosition()+1 << endl;
  if(isFaillite)cout << "\e[0;31mEn Faillite !\e[0m" << endl;
  cout << "           "<< endl;
}

/*
* Retourne la valeur de position courrante.
*/
int Joueur::getPosition() const
{
  return (this->position);
}

/*
* Retourne le nom du Joueur
*/
string Joueur::getNom() const
{
  return (this->nom);  //retourne le nom du joueur
}

/*
* Retourne la valeur de position courrante.
*/
int Joueur::getFortune() const
{
  return (this->fortune);
}

/*
* Permet de modifier la valeur de fortune courrante.
*/
void Joueur::setFortune(int money)
{
  this->fortune = money;  //permet de modifier la fortune
}

/*
* Permet d'attribuer une position absolue au joueur.
*/
void Joueur::setPosition(int newPos){
  position = newPos;
}

/*
* Permet de renseigner de façon absolue le nombre de gares du Joueur.
*/
void Joueur::setNbGares(int n)
{
  this -> nbGares = n;
}

/*
* Retourne le nombre de gares du Joueur.
*/
int Joueur::getNbGares(void)
{
  return (this -> nbGares);
}

/*
* Retourne le nombre de services du Joueur.
*/
int Joueur::getNbServices(void)
{
  return (this -> nbServices);
}

/*
* Permet de renseigner de façon absolue le nombre de gares du Joueur.
*/
void Joueur::setNbServices(int n)
{
  this -> nbServices = n;
}

/*
*	Retourne le statut de faillite du joueur.
*/
bool Joueur::getFaillite()
{
	return this->isFaillite;
}

/*
* Permet de définir le statut de faillite du Joueur.
*/
void Joueur::setFaillite(bool etat)
{
	this->isFaillite = etat;
}