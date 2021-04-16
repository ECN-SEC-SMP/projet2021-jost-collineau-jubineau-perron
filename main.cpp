// Your First C++ Program
#include "joueur.h"
#include <iostream>


int main() {
  
  Joueur J1 ("Olivier");
  Joueur J2 ("Celine");

  
  J1.payer(&J2, 8000);

  return 0;
}