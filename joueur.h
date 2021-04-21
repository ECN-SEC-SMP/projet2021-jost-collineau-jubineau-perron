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
    int nbServices;
		bool isFaillite;
    bool tourFait; //Définit si le joueur a fait un tour

  public :
    Joueur();
    Joueur(string name);

    bool payer(Joueur* j, int price);
    void deplacer(int deplacement);
    void tourDeJeu();
    string getNom() const;
    void setFortune(int money);
    void addFortune(int money);
		void setFaillite(bool etat);
		bool getFaillite();
    int getFortune() const;
    int getPosition() const;
    void setPosition(int newPos);

    int getNbGares(void);
    void setNbGares(int n);
    int getNbServices(void);
    void setNbServices(int n);
    void addService();
    
    void afficher_info_joueur();
};