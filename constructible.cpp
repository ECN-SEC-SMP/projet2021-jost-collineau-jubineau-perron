#include "constructible.h"

Constructible::Constructible(string nom, int id, Joueur* proprietaire, int prix) : Achetable(nom, id, proprietaire, prix) {
  this -> nivBat1 = 0;
  this -> nivBat2 = 0;
  this -> nivBat3 = 0;
}

/*
*	retourne la valeur nivBat1;
*/
int Constructible::getBat1() {
  return this->nivBat1;
}

/*
*	retourne la valeur nivBat2;
*/
int Constructible::getBat2() {
  return this->nivBat2;
}

/*
*	retourne la valeur nivBat3;
*/
int Constructible::getBat3() {
  return this->nivBat3;
}

/*
* Calcule le loyer de la case constructible en fonction du nombre de maisons et d'hotels
*/
int Constructible::calculLoyer() { 
  int loyer = 0;
  int prixCase = this -> getPrix();
  
  //On rajoute 10% du prix pour chaque maison sur le terrain et 20% pour chaque hotel
  loyer = (prixCase/2) 	+ ((prixCase/10) * this -> getBat1()) 
												+ ((prixCase/10) * this -> getBat2()) 
												+ ((prixCase/10) * this -> getBat3());
  this -> setLoyer(loyer);

  return loyer;
}

/*
* Fonction qui permet de CONSTRUIRE un batiment sur un terrain libre
*/
bool Constructible::construire(int type) {
  int fortune = this -> getProprio() -> getFortune();

  if ((nivBat1 != 0) && (nivBat2 != 0) && (nivBat3 != 0)) {
    return false;
  }
  
  if (type == 1) {
    if ((fortune) >= 300) {            //Prix d'une maison : 300€
      if (nivBat1 == 0) {
        this->getProprio()->setFortune(fortune - 300);
        nivBat1 = 1;
        return true;
      }
      else if (nivBat2 == 0) {
        this->getProprio()->setFortune(fortune - 300);
        nivBat2 = 1;
        return true;
      }
      else if (nivBat3 == 0) {
        this->getProprio()->setFortune(fortune - 300);
        nivBat3 = 1;
        return true;
      }
    }
    else {return false;}
  }
  else if (type == 2)
  {
    if ((fortune) >= 800)             //Prix d'un hotel : 800€
    {
      if (nivBat1 == 0)
      {
        this -> getProprio() -> setFortune(fortune - 800);
        nivBat1 = 2;
        return true;
      }
      else if (nivBat2 == 0)
      {
        this -> getProprio() -> setFortune(fortune - 800);
        nivBat2 = 2;
        return true;
      }
      else if (nivBat3 == 0)
      {
        this -> getProprio() -> setFortune(fortune - 800);
        nivBat3 = 2;
        return true;
      }
    }
    else {return false;}
  }
  else {return false;}

  return false;
}

/*
* Fonction permettant d'améliorer une maison en hotel
*/
bool Constructible::upgrade(int batToUpgrade)
{
  int fortune = this -> getProprio() -> getFortune();

  if (fortune >= 500)
  {
    if(batToUpgrade == 1)
    {
      if (nivBat1 != 1){return false;}
      else
      {
        this->nivBat1++;
        this -> getProprio() -> setFortune(fortune - 500);
        return true;
      }
    }

    if(batToUpgrade == 2)
    {
      if (nivBat1 != 1){return false;}
      else
      {
        this->nivBat2++;
        this -> getProprio() -> setFortune(fortune - 500);
        return true;
      }
    }

    if(batToUpgrade == 3)
    {
      if (nivBat1 != 1){return false;}
      else
      {
        this->nivBat3++;
        this -> getProprio() -> setFortune(fortune - 500);
        return true;
      }
    }
  }
  else{return false;}

  return false;
}

/*
*	Surcharge de l'opérateur <<
*/
ostream& Constructible::write( ostream& stm )const
{
    stm << id << " - " << this->nom << " (coût: " << to_string(this->prix) << " ) ";
    if(this->proprietaire == nullptr){
      stm << "- sans proprietaire\n";
    }else{
      stm << "proprietaire: " << this->proprietaire->getNom() << ", ";

      int nbMaison = 0, nbHotel = 0;

      if(this->nivBat1 == 1)nbMaison++;
      if(this->nivBat1 == 2)nbHotel++;
      
      if(this->nivBat2 == 1)nbMaison++;
      if(this->nivBat2 == 2)nbHotel++;

      if(this->nivBat2 == 1)nbMaison++;
      if(this->nivBat3 == 2)nbHotel++;

      if(nbMaison != 0){ stm << to_string(nbMaison) << " maisons " ;}
      if(nbHotel != 0){ stm << ", " << to_string(nbHotel) << " hotels";}

      stm << ", loyer = " << to_string(loyer) << "\n"; 
    }
}