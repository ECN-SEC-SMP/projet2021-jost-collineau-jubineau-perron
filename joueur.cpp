#include "joueur.h"

Joueur::Joueur(){
}

Joueur::Joueur(string name)
{
  this-> nom = name;   //on set le nom du joueur avec celui donné en paramètre
  this-> fortune = 100000;  //on initialise la fortune du joueur à 100000 en début de partie
  this-> position = 0;  //on initialise la position du joueur à 0
  // this-> id = 

}

bool Joueur::payer(Joueur* j, int price)  //permet de payer un joueur
{
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
}

string Joueur::getNom() const
{
  return (this->nom);  //retourne le nom du joueur
}

void Joueur::setFortune(int money)
{
  this->fortune = this->fortune + money;  //permet d'ajouter de l'argent à la fortune du joueur
}

