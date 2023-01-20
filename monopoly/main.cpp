#include <iostream>
#include <cstdlib>
#include "case.h"
#include "Gare.h"
#include "Propriete.h"
#include "test.h"
#include "Jeu.h";

int main(int argc, char** argv)
{
	srand(time(NULL));
	std::string config("0"), choice;
	bool choose = false;
	std::cout << "Voulez vous continuer une partie sauvegardée ?" << std::endl;

	do {
		std::cout << "1 - Oui" << std::endl;
		std::cout << "2 - Non" << std::endl;
		cin >> choice;
		char c = choice[0];
		switch (c) {
		case '1':
			std::cout << "Entrez le nom de votre fichier de sauvegarde : ";
			cin >> config;
			choose = true;
			break;
		case '2':
			choose = true;
			break;
		default:
			std::cout << "Cette commande n'est pas reconnue..." << endl;
			break;
		}
	} while (!choose);
	
	Jeu game(config);
	
	game.lancerPartie();

	return EXIT_SUCCESS;
}