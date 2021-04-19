#include "achetable.h"
#include "service.h"
#include "joueur.h"

Service::Service(string nom, int id, Joueur* proprietaire, int prix) : Achetable(nom, id, proprietaire, prix)
{
  
}