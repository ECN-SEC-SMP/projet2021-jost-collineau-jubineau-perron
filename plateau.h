#pragma once
#include <string>
#include <vector>

//class Joueur;
#include "case.h"
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
		int nbGares(Joueur J);

  public :
		Plateau();
		void initPlateau();
    void afficher();
		//void avancer(); // ????
		void tourDeJeu();
		bool finDePartie();
};