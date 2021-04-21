#pragma once
#include <string>
#include <iostream>
using namespace std;

class Plateau;	//prédéclaration: permet d'éviter une dépendance cyclique

/*
*	La classe Joueur permet d'abstraire un joueur physique à un objet dans 
*	notre programme. 
*	Un joueur peut payer un autre joueur, se déplacer sur le plateau de joueur
*	et on peut en afficher les informations.
*/
class Joueur
{
  private :
    string nom;
    int fortune;
    int position;
		bool isFaillite;
    int nbGares;
    int nbServices;
    bool tourFait;	 //Indique si le joueur a fait un tour

  public :
    Joueur();
    Joueur(string name);

    bool payer(Joueur* j, int price);
    void deplacer(int deplacement);
    void afficher_info_joueur();

		void setFaillite(bool etat);
		bool getFaillite();
    
		int getPosition() const;
    void setPosition(int newPos);
    
		void addFortune(int money);
    int getFortune() const;
    void setFortune(int money);

    int getNbGares(void);
    void setNbGares(int n);

    void addService();
    int getNbServices(void);
    void setNbServices(int n);
    
    string getNom() const;
};