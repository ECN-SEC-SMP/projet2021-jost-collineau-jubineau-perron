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