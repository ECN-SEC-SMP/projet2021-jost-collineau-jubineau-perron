#pragma once
#include <string>
#include <iostream>
#include <vector>

//class Joueur;
#include "case.h"
#include "gare.h"
#include "constructible.h"
#include "service.h"
#include "joueur.h"
using namespace std;


class De {
	private :
		int nbFaces;
	
	public :
		De() { nbFaces = 6; }
		int lancer(){ return (rand() % nbFaces) + 1; }
};

class Plateau
{
	private :
		vector <Case*> cases;
		De de;
		vector <Joueur> joueurs;

  public :
		Plateau();
		void initPlateau();
    void afficher();
		//void avancer(); // ????
		void tourDeJeu();
		bool finDePartie();
		int nbGares(Joueur *J);
    
};