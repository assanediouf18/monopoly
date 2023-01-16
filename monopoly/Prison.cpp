#include "Prison.h"

using namespace std;

Prison::Prison(std::string name) : Case(name)
{
}

void Prison::arriverSur(Joueur& joueur)
{
	if (this->getNom() == "Aller en prison") {
		cout << joueur.getPseudo() << " va en prison" << endl;
		joueur.setTempsPrison(0); //le joueur est envoy� en prison apr�s lors de jouerTour
		return;
	}

	if (joueur.getTempsPrison() < 0) {
		std::cout << "Bienvenue sur la case prison." << std::endl;
		return;
	}

	cout << joueur.getPseudo() << " est en prison depuis " << joueur.getTempsPrison() + 1 << " tour(s)." << endl;
	if (joueur.getTempsPrison() >= 0)
	{
		//Faire un double et sortir de prison en faisant un lanc� de d�s pour avancer
		if (joueur.howManyDoubles() > 0 && joueur.howManyDoubles() < 3) {
			joueur.setTempsPrison(-1); //On fait �a pour dire que le temps en prison est termin�
			//Le joueur pourra donc joueur normalement la prochaine fois
			cout << joueur.getPseudo() << " peut sortir de prison !" << endl;
			return;
		}
		//Ou apr�s 3 tours de prison, payer 50 euros � la banque et sortir
		if (joueur.getTempsPrison() >= 2)
		{
			cout << joueur.getPseudo() << " paie 50 billets � la banque et sort de prison." << endl;
			joueur.changeSolde(-50);
			joueur.setTempsPrison(-1);
			return;
		}
		//Ou payer une amande de 50 balles et sortir
		cout << "1 - Payer une amende de 50 billets et sortir" << endl;
		//Ou utiliser une carte "lib�r� de prison" puis relancer les d�s
		cout << "2 - Acheter une carte prison" << endl; //Proposer au joueur de l'utiliser s'il en poss�de une + proposer seulement si la carte est pioch�e ?
		cout << "3 - Continuer son tour" << endl;

		int choice;
		std::cout << "Choix de " << joueur.getPseudo() << " : ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			joueur.setTempsPrison(-1);
			joueur.changeSolde(-50);
			return;
			break;
		case 2:
			//Demander aux joueurs si quelqu'un veut vendre une carte
			break;
		default:
			break;
		}

	}

	joueur.setTempsPrison(joueur.getTempsPrison() + 1);
}
