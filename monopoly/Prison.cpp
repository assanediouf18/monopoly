#include "Prison.h"

using namespace std;

Prison::Prison(std::string name) : Case(name)
{
}

void Prison::arriverSur(Joueur& joueur)
{
	if (this->getNom() == "Aller en prison") {
		cout << joueur.getPseudo() << " va en prison" << endl;
		//Bouger le joueur en prison
		return;
	}

	cout << joueur.getPseudo() << " est en prison depuis " << joueur.getTempsPrison() + 1 << " tour(s)." << endl;
	if (joueur.getTempsPrison() >= 0)
	{
		//Faire un double et sortir de prison en faisant un lancé de dés pour avancer
		if (joueur.howManyDoubles() > 0 && joueur.howManyDoubles() < 3) {
			joueur.setTempsPrison(-1); //On fait ça pour dire que le temps en prison est terminé
			//Le joueur pourra donc joueur normalement la prochaine fois
			cout << joueur.getPseudo() << " peut sortir de prison !" << endl;
			return;
		}
		//Ou après 3 tours de prison, payer 50 euros à la banque et sortir
		if (joueur.getTempsPrison() >= 2)
		{
			cout << joueur.getPseudo() << " paie 50 billets à la banque et sort de prison." << endl;
			joueur.changeSolde(-50);
			joueur.setTempsPrison(-1);
			return;
		}
		//Ou payer une amande de 50 balles et sortir
		cout << "1 - Payer une amende de 50 billets et sortir" << endl;
		//Ou utiliser une carte "libéré de prison" puis relancer les dés
		cout << "2 - Acheter une carte prison" << endl; //Proposer au joueur de l'utiliser s'il en possède une + proposer seulement si la carte est piochée ?
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
