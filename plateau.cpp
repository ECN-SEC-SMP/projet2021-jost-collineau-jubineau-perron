#include "plateau.h"

#define ACHETABLE 0
#define SERVICE 1
#define GARE 2
#define NON_ACHETABLE 3

using namespace std;

Plateau::Plateau(){
	initPlateau();
}

int Plateau::lancerDe(){
	return (rand() % 6) + 1;;
}

void Plateau::initPlateau(){
	cases.push_back(new Non_achetable("Depart", NON_ACHETABLE));	//case 0
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));	//case 1
	cases.push_back(new Constructible("je connais pas son nom xd", SERVICE, nullptr, 0));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("je connais pas son nom xd", SERVICE, nullptr, 0));
	cases.push_back(new Gare("gare", GARE, nullptr, 1000));	//case 5
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Non_achetable("chance", NON_ACHETABLE));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Non_achetable("Prison", NON_ACHETABLE));	//case 10

	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("je connais pas son nom xd", SERVICE, nullptr, 0));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Gare("gare", GARE, nullptr, 1000));	//case 15
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("je connais pas son nom xd", SERVICE, nullptr, 0));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000)); 
	cases.push_back(new Non_achetable("free parking", NON_ACHETABLE));//case 20

	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Non_achetable("chance", NON_ACHETABLE));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Gare("gare", GARE, nullptr, 1000));	//case 25
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Non_achetable("chance", NON_ACHETABLE));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Non_achetable("Police", NON_ACHETABLE));	//case 30

	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("je connais pas son nom xd", SERVICE, nullptr, 0));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Gare("gare", GARE, nullptr, 1000));	//case 35
	cases.push_back(new Non_achetable("chance", NON_ACHETABLE));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));
	cases.push_back(new Constructible("je connais pas son nom xd", SERVICE, nullptr, 0));
	cases.push_back(new Constructible("Constructible", ACHETABLE, nullptr, 1000));	//case 39
}

void Plateau::afficher(){
	cout << "Affichage du tableau :" << endl;
	  for(int i=0; i<40 ; i++){
    cases[i]->afficher();
  }
}

void Plateau::tourJoueur(Joueur *J){
	int faceDe = lancerDe();
	J->deplacer(faceDe);
	cout << "le joueur " << J->getNom() << "passe en case n." << this->getPosition();
	if ( !( faceDe % 2 == 0)){	// lancer de dé impair
		if ( cases[J->getPosition()].getID() ==  ) { //PROBLEME A RESOUDRE : DETECTER SI CASE ACHETABLE

		}
	}	
	return;
}

/*
void Plateau::tourDeJeu(){
	//si joueur arrive sur case dont il n'est pas proprio (et qui a un proprio non null) executer calculloyer sur la case
  int flag;
  int nb_joueurs = joueurs.size();

  for(int i=0; i<nb_joueurs; i++)
  {
    cout<<"Au tour du joueur "<<joueurs[i].getNom()<<endl;
    std::getchar();
    tourJoueur(joueurs[i]); //lance un dé, et déplace le joueur
  }

	return;                           //Bien penser à n'appeler la fonction acheter que si le chiffre donné par le dé est impaire
}*/
/*
bool Plateau::finDePartie(){
	return 0;
}*/