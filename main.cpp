// Your First C++ Program
#include "joueur.h"
#include "gare.h"
//#include "plateau.h"
#include "constructible.h"
#include <iostream>


int main() {
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
  
  //g2.calculLoyer(&monPlateau);
  g1.afficher();g2.afficher();	

	monPlateau.afficher();
  return 0;
}