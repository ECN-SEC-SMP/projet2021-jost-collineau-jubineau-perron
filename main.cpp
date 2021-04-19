// Your First C++ Program
#include "joueur.h"
#include "plateau.h"
#include <iostream>


int main() {
  
  Joueur J1 ("Olivier");
  Joueur J2 ("Celine");

  J1.afficher_info_joueur();
  J2.afficher_info_joueur();
  
  J1.payer(&J2, 8000);
  J2.deplacer(5);

  J1.afficher_info_joueur();
  J2.afficher_info_joueur();

  return 0;
}