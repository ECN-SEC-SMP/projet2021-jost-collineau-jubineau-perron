#pragma once
#include <string>
#include <iostream>

class Plateau;

//#include "plateau.h"
//#include "case.h"
//#include "achetable.h"
//#include "constructible.h"
//#include "gare.h"
//#include "service.h"

using namespace std;

class Joueur
{
  private :
    int fortune;
    string nom;
    // int id; ?? pas encore utilisé
    int position;
    int nbGares;

  public :
    Joueur();
    Joueur(string name);
    Plateau *refplateau;

    bool payer(Joueur* j, int price);
    void deplacer(int deplacement);
    void tourDeJeu();
    string getNom() const;
    void setFortune(int money);
    int getFortune() const;
    int getPosition() const;
    int nbGares(){return nbGares;}

    void afficher_info_joueur();
};