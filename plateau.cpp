#include "plateau.h"
#include <stdlib.h>
using namespace std;


#define CONSTRUCTIBLE 0
#define SERVICE 1
#define GARE 2
#define NON_ACHETABLE 3


Plateau::Plateau(){
	initPlateau();
}

int Plateau::lancerDe(){
	return (rand() % 6) + 1;;
}

void Plateau::addJoueur(Joueur *J){
	joueurs.push_back(J);
}

void Plateau::initPlateau(){
	int id=1;
	cases.push_back(new Non_achetable("Depart", id++));	//case 0
	cases.push_back(new Constructible("Boulevard de Belleville", id++, nullptr, 60));	//case 1
	cases.push_back(new Non_achetable("Caisse de Communauté", id++));
	cases.push_back(new Constructible("Rue Lecourbe", id++, nullptr, 60));
	cases.push_back(new Non_achetable("Impots", id++));
	cases.push_back(new Gare("Gare Montparnasse", id++, nullptr, 200));	//case 5
	cases.push_back(new Constructible("Rue de Vaugirard", id++, nullptr, 100));
	cases.push_back(new Non_achetable("chance", id++));
	cases.push_back(new Constructible("Rue de Courcelle", id++, nullptr, 100));
	cases.push_back(new Constructible("Avenue de République", id++, nullptr, 120));
	cases.push_back(new Non_achetable("Prison", id++));	//case 10

	cases.push_back(new Constructible("Boulevard de la Villette", id++, nullptr, 140));
	cases.push_back(new Service("Compagnie d'électricité", id++, nullptr, 150));
	cases.push_back(new Constructible("Avenue de Neuilly", id++, nullptr, 140));
	cases.push_back(new Constructible("Rue de Paradis", id++, nullptr, 160));
	cases.push_back(new Gare("Gare de Lyon", id++, nullptr, 200));	//case 15
	cases.push_back(new Constructible("Avenue Mozart", id++, nullptr, 180));
	cases.push_back(new Non_achetable("Caisse de Communauté", id++));
	cases.push_back(new Constructible("Boulevard Saint Michel", id++, nullptr, 180));
	cases.push_back(new Constructible("Place Pigalle", id++, nullptr, 200)); 
	cases.push_back(new Non_achetable("free parking", id++));//case 20

	cases.push_back(new Constructible("Avenue Matignon", id++, nullptr, 220));
	cases.push_back(new Non_achetable("chance", id++));
	cases.push_back(new Constructible("Boulevard Malseherbes", id++, nullptr, 220));
	cases.push_back(new Constructible("Avenue Henri-Martin", id++, nullptr, 240));
	cases.push_back(new Gare("Gare du Nord", id++, nullptr, 200));	//case 25
	cases.push_back(new Constructible("Faubourg Saint-Honoré", id++, nullptr, 260));
	cases.push_back(new Constructible("Place de la Bourse", id++, nullptr, 260));
	cases.push_back(new Non_achetable("Compagnie des Eaux", id++));
	cases.push_back(new Constructible("Rue de la Fayette", id++, nullptr, 280));
	cases.push_back(new Non_achetable("Police", id++));	//case 30

	cases.push_back(new Constructible("Avenue Breteuil", id++, nullptr, 300));
	cases.push_back(new Constructible("Avenue Foch", id++, nullptr, 300));
	cases.push_back(new Non_achetable("Caisse de Communauté", id++));
	cases.push_back(new Constructible("Boulevard des Capucines", id++, nullptr, 320));
	cases.push_back(new Gare("Gare Saint-Lazare", id++, nullptr, 200));	//case 35
	cases.push_back(new Non_achetable("chance", id++));
	cases.push_back(new Constructible("Avenue des Champs-Élysées", id++, nullptr, 350));
	cases.push_back(new Non_achetable("Taxe de Luxe", id++));
	cases.push_back(new Constructible("Rue de la Paix", id++, nullptr, 400));	//case 39
}

void Plateau::afficher(){
	cout << "Affichage du tableau :" << endl;
	  for(int i=0; i<40 ; i++){
     cases[i]->afficher();
  }
}

void Plateau::tourJoueur(Joueur *J){
  /* initialize random seed: */
  srand (time(NULL));
	int faceDe = 6;
  int resultLancer = rand() % faceDe + 1;

  int oldPos = J->getPosition();
	J->deplacer(resultLancer);
	cout	<< "-- Debut du tour de " << J->getNom() <<" --" << endl
	      << "le lancer de dé a donné " << resultLancer 
				<< " , le joueur passe en case n." << J->getPosition()+1
        << "(Précedement " << oldPos+1 << ")" << endl;
	cases[J->getPosition()]->afficher(); 

	// NOUVELLE POSITION = CASE ACHETABLE
	if ( cases[J->getPosition()]->isAchetable() ) {	
		cout	<< "La nouvelle case est achetable ..." << endl ;
		Achetable * CaseAchetablePtr = (Achetable *) cases[J->getPosition()];
		Joueur * proprioCase = CaseAchetablePtr->getProprio();
		
		//CAS 1 - pas de proprio
		if ( proprioCase == nullptr){	
			cout	<< " et n'a pas de propriétaire" << endl ;
			int prixCase = CaseAchetablePtr->getPrix();

			//Si J peut se permettre l'achat ET lancer dé impair -> achat systématique de la case
			if (prixCase <= J->getFortune()  &&  !( resultLancer % 2 == 0)) {
				cout	<< "Le lancer est impair et les moyens suffisants ; achat de la case" << endl ;	
				CaseAchetablePtr->acheter(J);	//Achat case 
				// -> A IMPLEMENTER : CHECK ACHAT OK ? (acheter()renvoie booleen)
			}
		}

		//CAS 2 - proprio de la case existe et n'est pas J -> payer le loyer
		else if ( proprioCase != J && proprioCase != nullptr){	
			cout	<< "et a un propriétaire autre que " << J->getNom() << endl ;
			cout << "on paie donc le loyer de " << CaseAchetablePtr->getLoyer() << endl;
			J->payer(proprioCase, CaseAchetablePtr->getLoyer());	//payer loyer
		}
	}

	// NOUVELLE POSITION = CASE NON ACHETABLE
	else {
		cout	<< "La nouvelle case N'EST PAS achetable ... A IMPLEMENTER" << endl ;

    //Case Police renvoie à la case Prison
    if(cases[J->getPosition()]->getID() == 30){
      J->setPosition(10);
      cout << J->getNom() << " est envoyé(e) en prison !\n";
    }
	}
	cout << "-- Fin du tour pour " << J->getNom() << "--" << endl ;
	cout << endl; 
	return;
}

void Plateau::tourDeTable(){
  int flag;
  int nb_joueurs = joueurs.size();

  for(int i=0; i<nb_joueurs; i++)  {
		//ignorer joueurs en faillite
		if (! joueurs[i]->getFaillite()){

			cout 	<< "Au tour du joueur " << joueurs[i]->getNom(); 
      
      // clear console
      cout << "\033c";

    	tourJoueur(joueurs[i]); //faire un tour pour le joueur i
      joueurs[i]->afficher_info_joueur();

      cout	<< "\nAppuyer sur Entrée pour continuer ..." << endl;
    	std::getchar();
		}
  }
	checkFaillites();	//éliminer les joueurs ayant fait faillite
	return;
}

void Plateau::checkFaillites(){
	int nb_joueurs = joueurs.size();
	for(int i=0; i<nb_joueurs; i++)
  {
		if (joueurs[i]->getFortune() <= 0) {
			cout 	<< "Le joueur " << joueurs[i]->getNom() << "a fait faillite et est retiré de la partie" << endl;
			joueurs[i]->setFaillite( true );
		}
  }
}

bool Plateau::finDePartie(){
	int joueursEnLice = 0;
	int nb_joueurs = joueurs.size();
	for(int i=0; i<nb_joueurs; i++)
  {
		if ( ! joueurs[i]->getFaillite()) {
			joueursEnLice ++;			
		}
  }
	if (joueursEnLice <= 1) {
		cout << "-- FIN PARTIE DETECTEE --" << endl;
		return true;
	}	
	else return false ;
}

void Plateau::afficherJoueurs(){
  for(int i=0; i<joueurs.size(); i++){
    joueurs[i]->afficher_info_joueur();
  }
}