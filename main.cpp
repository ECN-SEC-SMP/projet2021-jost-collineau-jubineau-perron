// Your First C++ Program
#include "joueur.h"
#include "plateau.h"
#include "constructible.h"
#include <iostream>


int main() {
  Joueur J1 ("Olivier");
  Joueur J2 ("Celine");

  J1.afficher_info_joueur();
  J2.afficher_info_joueur();
  
  // cout<<"Olivier doit 8000 a Celine"<<endl;
  J1.payer(&J2, 8000);
  J2.deplacer(5);

  J1.afficher_info_joueur();
  J2.afficher_info_joueur();

  Constructible c("57 rue des fdp", 2, &J1,1500);
  cout << c;
  return 0;
}