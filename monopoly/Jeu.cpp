#include "Jeu.h"
#include "malloc.h"

Jeu::Jeu()
{
	joueurs = NULL;
	nbJoueurs = 0;

	std::cout << "Combien de joueurs êtes-vous ?";
	std::cin >> nbJoueurs;

	if (nbJoueurs <= 1) {
		cout << "Désolé, le Monopoly se joue au moins à deux..." << endl;
		return;
	}

	joueurs = new Joueur[nbJoueurs];
	
	int startingMoney = 2 * 500 + 4 * 100 + 50 + 20 + 10 + 5 + 1;

	for (int i = 0; i < nbJoueurs; i++)
	{
		std::cin >> joueurs[i];
		std::cout << std::endl;

		joueurs[i].changeSolde(startingMoney);
		joueurs[i].setPosition(0);

		std::cout << joueurs[i] << std::endl;
	}
}
