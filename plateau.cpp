#include "plateau.h"

#define ACHETABLE 0
#define SERVICE 1
#define GARE 2

using namespace std;

Plateau::Plateau(){
	initPlateau();
}

void Plateau::initPlateau(){
	cases.push_back(new Constructible("depart", SERVICE, nullptr, 0));	//case 0
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));	//case 1
	cases.push_back(new Constructible("je connais pas son nom xd", SERVICE, nullptr, 0));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("je connais pas son nom xd", SERVICE, nullptr, 0));
	cases.push_back(new Gare("gare", GARE, nullptr, 1000));	//case 5
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("chance", SERVICE, nullptr, 0));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("je connais pas son nom xd", SERVICE, nullptr, 0));	//case 10

	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("je connais pas son nom xd", SERVICE, nullptr, 0));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Gare("gare", GARE, nullptr, 1000));	//case 15
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("je connais pas son nom xd", SERVICE, nullptr, 0));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000)); 
	cases.push_back(new Constructible("je connais pas son nom xd", SERVICE, nullptr, 0));//case 20

	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("chance", SERVICE, nullptr, 0));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Gare("gare", GARE, nullptr, 1000));	//case 25
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("chance", SERVICE, nullptr, 0));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("je connais pas son nom xd", SERVICE, nullptr, 0));	//case 30

	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("je connais pas son nom xd", SERVICE, nullptr, 0));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Gare("gare", GARE, nullptr, 1000));	//case 35
	cases.push_back(new Constructible("chance", SERVICE, nullptr, 0));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("je connais pas son nom xd", SERVICE, nullptr, 0));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));	//case 39
}

void Plateau::afficher(){
	cout << "Affichage du tableau :" << endl;
	/*vector<Case*>::iterator it;
	for (it = cases.begin(); it !=cases.end(); it++){
		cout << *it << endl;
	}*/
	for (int i = 0; i < 40; i++) {
		cout << &cases[i] << endl;
	}
}

void Plateau::tourDeJeu(){
	//si joueur arrive sur case dont il n'est pas proprio (et qui a un proprio non null) executer calculloyer sur la case
  
  // J1.deplacer(de.lancer());

  // QUE FAIRE ?
  
	return;                           //Bien penser à n'appeler la fonction acheter que si le chiffre donné par le dé est impaire
}

bool Plateau::finDePartie(){
	return 0;
}

int Plateau::nbGares(Joueur *J){
	int varGares = 0;
	Gare *GarePtr;
	
	//Pour chaque position de gare (manuellement) :
	GarePtr = (Gare*) cases[5];
	if ( GarePtr->getProprio()->getNom() == J->getNom()) varGares ++;
	GarePtr = (Gare*) cases[15];
	if ( GarePtr->getProprio()->getNom() == J->getNom()) varGares ++;
	GarePtr = (Gare*) cases[25];
	if ( GarePtr->getProprio()->getNom() == J->getNom()) varGares ++;
	GarePtr = (Gare*) cases[35];
	if ( GarePtr->getProprio()->getNom() == J->getNom()) varGares ++;
	return varGares;
}