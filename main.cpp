#include "joueur.h"
#include "gare.h"
//#include "plateau.h"
#include "constructible.h"
#include <iostream>

void unePartie(Plateau monPlateau);

int main() 
{
  //Initialisation du Jeu
  Plateau monPlateau;

	Joueur * J1  = new Joueur("Olivier");
  Joueur * J2 = new Joueur("Celine");
	monPlateau.addJoueur(J1);
	monPlateau.addJoueur(J2);

	J1->afficher_info_joueur();
  J2->afficher_info_joueur();
	monPlateau.afficher();

  unePartie(monPlateau);

  return 0;
}

void unePartie(Plateau monPlateau){
  cout << "\n\n ---     DÉBUT DU JEU     --- \n"
       << "\nAppuyer sur Entrée pour continuer ..." << endl;
  std::getchar();

  int nbTours =1;
	do {
		monPlateau.tourDeTable();

    cout << "\033c" 
         << " --- Fin du " << nbTours;
    if(nbTours == 1)cout << "er ";
    else            cout << "ème ";
    cout << "tour de table --- \n";

    monPlateau.afficherJoueurs();
    cout << " ---------------------------- \n"
         << "\nAppuyer sur Entrée pour continuer ..." << endl;
    std::getchar();
    nbTours++;
	} while ( !(monPlateau.finDePartie()) );
}