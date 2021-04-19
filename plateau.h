#pragma once
#include <string>
#include <iostream>
#include <vector>

//class Joueur;
#include "case.h"
#include "gare.h"
#include "non_achetable.h"
#include "constructible.h"
#include "service.h"
#include "joueur.h"
using namespace std;

class Plateau
{
	private :
		vector <Case*> cases;
		vector <Joueur> joueurs;
		int lancerDe();

  public :
		Plateau();
		void initPlateau();
    void afficher(void);
		//void avancer(); // ????
		void tourJoueur(Joueur *J);
		void tourDeJeu();
		bool finDePartie();
    
};