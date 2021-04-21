// Your First C++ Program
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
	
	//monPlateau.tourDeTable();
	//J1->afficher_info_joueur();
	//monPlateau.tourJoueur(J2);
	//J2->afficher_info_joueur();

  unePartie(monPlateau);

	/*
	Plateau monPlateau;
	Joueur J1 ("Olivier");
  Joueur J2 ("Celine");
	
  J1.afficher_info_joueur();
  J2.afficher_info_joueur();
  
  J1.payer(&J2, 8000);
  J2.deplacer(5);

  J1.afficher_info_joueur();
  J2.afficher_info_joueur();

  Constructible c1("Quartier bon ami", 3, nullptr ,3000);
  Constructible c2("Avenue Richou", 2, &J1,1500);
  c2.construire(2);c2.construire(1);
  c1.calculLoyer();
  c2.calculLoyer();
  c1.afficher();c2.afficher();

  Gare g1("Quai 9 3/4", 15, nullptr, 2000);
  Gare g2("Gare de Lionne", 16, &J2, 2000);
  g1.calculLoyer();
  g2.calculLoyer();
  g1.afficher();g2.afficher();	
  cout << "\n";
	*/
/*
  while(J2->getFortune() != 0 | J1->getFortune()!= 0)
  {
    monPlateau.tourDeTable();
	  J1->afficher_info_joueur();
	  J2->afficher_info_joueur();
  }
  if (J2->getFortune() == 0)
  {
    cout<< "Le joueur "<< J2->getNom() << "est en faillite, il a perdu"<<endl;
    
  }
  */
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