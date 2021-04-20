#include "case.h"

Case::Case(string nom, int id)
{
  this->nom = nom;
  this->id = id;
}

string Case::getNom(){
  return this->nom;
}

void Case::afficher(void){
  cout << id << " - " << this->nom << "\n";
}