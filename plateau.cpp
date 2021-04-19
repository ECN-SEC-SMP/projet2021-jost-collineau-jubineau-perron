#include "plateau.h"

#include <iostream>
using namespace std;

Plateau::Plateau(){
	initPlateau();
}

void Plateau::initPlateau(){
	//init cases
	//Constructible const1;
	//cases.push_back(const1);
}

void Plateau::afficher(){
	cout << "Affichage du tableau :" << endl;
	vector<Case*>::iterator it;
	for (it = cases.begin(); it !=cases.end(); it++){
		//cout << *it << endl;;
	}
}

void Plateau::tourDeJeu(){
	return;                           //Bien penser à n'appeler la fonction acheter que si le chiffre donné par le dé est impaire
}

bool Plateau::finDePartie(){
	return 0;
}

int Plateau::nbGares(Joueur J){
	/*int varGares = 0;
	Gare *GarePtr = new Gare;
	
	//Pour chaque position de gare (manuellement) :
	GarePtr = (Gare*) cases[0];
	if ( GarePtr->getProprio()->getNom() == J.getNom()) varGares ++;
	GarePtr = (Gare*) cases[5];
	if ( GarePtr->getProprio()->getNom() == J.getNom()) varGares ++;
	GarePtr = (Gare*) cases[15];
	if ( GarePtr->getProprio()->getNom() == J.getNom()) varGares ++;
	GarePtr = (Gare*) cases[25];
	if ( GarePtr->getProprio()->getNom() == J.getNom()) varGares ++;
	GarePtr = (Gare*) cases[35];
	if ( GarePtr->getProprio()->getNom() == J.getNom()) varGares ++;
	return varGares;*/
}