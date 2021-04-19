#pragma once

#include "string"
#include <iostream>
using namespace std;

class Case                                  //Classe de base pour toutes les cases du plateau
{
    protected :
    string nom;                             //Nom de la case
    int id;                                 //id de la case

  public :
    Case(string nom, int id);               //Constructeur
    string getNom(void);

		int getID() {return id;};
    void afficher(void);
    //Surchage de l'opérateur << pour l'affichage
    //ostream& operator<<(ostream& os, Case c);                               
};

