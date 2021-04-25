#include "plateau.h"
#include <stdlib.h>
using namespace std;


#define CONSTRUCTIBLE 0
#define SERVICE 1
#define GARE 2
#define NON_ACHETABLE 3

/*
*	Constructeur
*/
Plateau::Plateau(){
	initPlateau();
}

/*
* Retourne un nombre aléatoire entre 1 et 6.
*/
int Plateau::lancerDe(){
	srand (time(NULL));
	int nbFaces = 6;
	return (rand() % nbFaces) + 1;;
}

/*
* Ajoute un joueur au vecteur de joueurs du plateau.
*/
void Plateau::addJoueur(Joueur *J){
	joueurs.push_back(J);
}

/*
* Init du plateau avec les cases du monopoly.
*/
void Plateau::initPlateau(){
	int id=1;
	cases.push_back(new Non_achetable("Depart", id++));	//case 1
	cases.push_back(new Constructible("Boulevard de Belleville", id++, nullptr, 60));	//case 2
	cases.push_back(new Non_achetable("Caisse de Communauté", id++));
	cases.push_back(new Constructible("Rue Lecourbe", id++, nullptr, 60));
	cases.push_back(new Non_achetable("Impots", id++)); //case 5
	cases.push_back(new Gare("Gare Montparnasse", id++, nullptr, 200));	
	cases.push_back(new Constructible("Rue de Vaugirard", id++, nullptr, 100));
	cases.push_back(new Non_achetable("chance", id++));
	cases.push_back(new Constructible("Rue de Courcelle", id++, nullptr, 100));
	cases.push_back(new Constructible("Avenue de République", id++, nullptr, 120)); //case 10
	cases.push_back(new Non_achetable("Prison", id++));	

	cases.push_back(new Constructible("Boulevard de la Villette", id++, nullptr, 140));
	cases.push_back(new Service("Compagnie d'électricité", id++, nullptr, 150));
	cases.push_back(new Constructible("Avenue de Neuilly", id++, nullptr, 140));
	cases.push_back(new Constructible("Rue de Paradis", id++, nullptr, 160)); //case 15
	cases.push_back(new Gare("Gare de Lyon", id++, nullptr, 200));	
	cases.push_back(new Constructible("Avenue Mozart", id++, nullptr, 180));
	cases.push_back(new Non_achetable("Caisse de Communauté", id++));
	cases.push_back(new Constructible("Boulevard Saint Michel", id++, nullptr, 180));
	cases.push_back(new Constructible("Place Pigalle", id++, nullptr, 200)); //case 20
	cases.push_back(new Non_achetable("free parking", id++));

	cases.push_back(new Constructible("Avenue Matignon", id++, nullptr, 220));
	cases.push_back(new Non_achetable("chance", id++));
	cases.push_back(new Constructible("Boulevard Malseherbes", id++, nullptr, 220));
	cases.push_back(new Constructible("Avenue Henri-Martin", id++, nullptr, 240)); //case 25
	cases.push_back(new Gare("Gare du Nord", id++, nullptr, 200));	
	cases.push_back(new Constructible("Faubourg Saint-Honoré", id++, nullptr, 260));
	cases.push_back(new Constructible("Place de la Bourse", id++, nullptr, 260));
	cases.push_back(new Service("Compagnie des Eaux", id++, nullptr, 260));
	cases.push_back(new Constructible("Rue de la Fayette", id++, nullptr, 280)); //case 30
	cases.push_back(new Non_achetable("Police", id++));	

	cases.push_back(new Constructible("Avenue Breteuil", id++, nullptr, 300));
	cases.push_back(new Constructible("Avenue Foch", id++, nullptr, 300));
	cases.push_back(new Non_achetable("Caisse de Communauté", id++));
	cases.push_back(new Constructible("Boulevard des Capucines", id++, nullptr, 320)); //case 35
	cases.push_back(new Gare("Gare Saint-Lazare", id++, nullptr, 200));	
	cases.push_back(new Non_achetable("chance", id++));
	cases.push_back(new Constructible("Avenue des Champs-Élysées", id++, nullptr, 350));
	cases.push_back(new Non_achetable("Taxe de Luxe", id++));
	cases.push_back(new Constructible("Rue de la Paix", id++, nullptr, 400));	//case 40
}

/*
* Affichage du plateau case par case.
*/
void Plateau::afficher(){
	cout << "Affichage du tableau :" << endl;
	  for(int i=0; i<40 ; i++){
     cout << *cases[i];
  }
}

/*
* Effectue un tour de jeu pour un joueur J soit :
*		- Lancer d'un dé
*		- Mise à jour de la position sur le plateau
*		- Appliquer les règles du jeu selon la nouvelle position du joueur
*/
void Plateau::tourJoueur(Joueur *J){
  /* initialize random seed: */
  srand (time(NULL));
  int resultLancer = lancerDe();

  int oldPos = J->getPosition();
	cout	<< "-- Debut du tour de " << J->getNom() <<" --" << endl
	      << "le lancer de dé a donné " << resultLancer
	      << " , le joueur passe en case n." << (J->getPosition()+resultLancer)%40 + 1
        << "(Précedement " << oldPos+1 << ")" << endl;
  J->deplacer(resultLancer);
	cout << *cases[J->getPosition()];

	// NOUVELLE POSITION = CASE ACHETABLE
	if ( cases[J->getPosition()]->isAchetable() ) {	
		cout	<< "La nouvelle case est achetable " << endl ;
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
		//Case Police renvoie à la case Prison
    if(cases[J->getPosition()]->getID() == 31){
      J->setPosition(10);
      cout << J->getNom() << " est envoyé(e) en prison !\n";
    }

    //Case Départ -> +200€
    else if(cases[J->getPosition()]->getID() == 1){
      J->addFortune(200);
    }

    else {
      cout	<< "La nouvelle case N'EST PAS achetable" << endl ;
    }
	}
	cout << "-- Fin du tour pour " << J->getNom() << "--" << endl ;
	cout << endl; 
	return;
}

/*
* Effectue un tour de jeu pour chaque joueur contenu dans le vecteur joueurs<> du tableau.
*	On ignore les joueurs en faillite (getFaillite() == true).
*	ATTENTION : Au moins un joueur doit avoir été ajouté via addJoueur().
*/
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

/*
* Vérifie la situation financière de chaque joueur du vecteur Joueurs<>.
*	Si la fortune est inférieure ou égale à 0, on déclare faillite
*	Les joueurs en faillite seront ignorés lors du jeu.
*/
void Plateau::checkFaillites(){
	int nb_joueurs = joueurs.size();
	for(int i=0; i<nb_joueurs; i++)
  {
		if (joueurs[i]->getFaillite() == true) {
			cout 	<< "Le joueur " << joueurs[i]->getNom() << "a fait faillite et est retiré de la partie" << endl;
			joueurs[i]->setFaillite( true );
		}
  }
}

/*
* Vérifie si la fin de la partie (1 seul joueur restant) est atteinte.
*	retourne : 	- true si la partie est terminée (1 seul ou 0 joueurs en lice)
*							- false si la partie n'est pas terminée
*/
bool Plateau::finDePartie(){
	int joueursEnLice = 0;
	int nb_joueurs = joueurs.size();
  Joueur* gagnant;
	
	// Recenser les joueurs en lice :
	for(int i=0; i<nb_joueurs; i++) {
		if ( ! joueurs[i]->getFaillite()) {
      gagnant = joueurs[i];
			joueursEnLice ++;			
		}
  }
	if (joueursEnLice <= 1) {
		cout << "-- FIN PARTIE DETECTEE --" << endl
         << " \e[0;32mGagnant: " << gagnant->getNom() << " !" << endl;
		return true;
	}	
	else return false ;
}

/*
* Affiche un par un les infos sur chaque joueur encore en jeu
*		(cad contenu dans le vecteur joueurs<>)
*/
void Plateau::afficherJoueurs(){
  for(int i=0; i<joueurs.size(); i++){
    joueurs[i]->afficher_info_joueur();
  }
}