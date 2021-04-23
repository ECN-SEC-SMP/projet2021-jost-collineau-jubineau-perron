#pragma once
#include <string>
#include <iostream>
#include <vector>

//class Joueur;
#include "achetable.h"
#include "case.h"
#include "gare.h"
#include "service.h"
#include "non_achetable.h"
#include "constructible.h"
#include "joueur.h"
using namespace std;

/**
* @class Plateau
*	La classe Plateau permet d'abstraire le plateau de jeu du Monopoly.
*	Elle contient le plateau de jeu en soi, représenté par un vecteur de Case,
*	ainsi qu'une liste des joueurs de la partie dans un vecteur de Joueur.
*	
* Nous notons la méthode tourJoueur() qui permet de jouer un tour complet pour
*	un des joueurs de la partie. Elle est appelée par la méthode tourDeTable qui
*	simule un tour de table où chaque joueur déroule son tour dans l'ordre du vecteur joueurs.
*		Dans une partie complète - cf main.cpp - on appelle cette méthode jusqu'à détecter
*		la fin de la partie avec finDePartie().
*		On élimine progressivement les joueurs en faillite avec checkFaillites.
*/

class Plateau
{
	private :
		vector <Case*> cases;
		vector <Joueur*> joueurs;
		
		int lancerDe();
		void checkFaillites();

  public :
		Plateau();
		void initPlateau();
		bool finDePartie();

		void addJoueur(Joueur *J);
    void afficher(void);
    void afficherJoueurs();
		
		void tourJoueur(Joueur *J);
		void tourDeTable();
};