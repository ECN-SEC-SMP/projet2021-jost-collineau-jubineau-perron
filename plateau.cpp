#include "plateau.h"
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

void Plateau::initPlateau(){
	int id=0;
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
	int faceDe = 9 ; //lancerDe();
	J->deplacer(faceDe);
	cout	<< "-- Debut du tour de " << J->getNom() <<" --" << endl ; 
	cout	<< "le lancer de dé a donné " << faceDe 
				<< " , le joueur passe en case n." << (J->getPosition()) << ":" << endl;
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
			if (prixCase <= J->getFortune()  &&  !( faceDe % 2 == 0)) {
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
	}
	cout << "-- Fin du tour pour " << J->getNom() << "--" << endl ;
	cout << endl; 
	return;
}

/*
void Plateau::tourDeJeu(){
	//si joueur arrive sur case dont il n'est pas proprio (et qui a un proprio non null) executer calculloyer sur la case
  int flag;
  int nb_joueurs = joueurs.size();

  for(int i=0; i<nb_joueurs; i++)
  {
    cout<<"Au tour du joueur "<<joueurs[i].getNom()<<endl;
    std::getchar();
    tourJoueur(joueurs[i]); //lance un dé, et déplace le joueur
  }

	return;                           //Bien penser à n'appeler la fonction acheter que si le chiffre donné par le dé est impaire
}*/
/*
bool Plateau::finDePartie(){
	return 0;
}*/