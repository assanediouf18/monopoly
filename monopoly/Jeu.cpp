#include "Jeu.h"
#include "malloc.h"

int Jeu::getRandomNumber()
{
	return (rand() % 6) + 1;
}

Jeu::Jeu(std::string config) : board()
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

int Jeu::getNbrJoueursEnJeu()
{
	if (nbJoueurs < 2) return 0;

	int enJeu = 0;

	for (int i = 0; i < nbJoueurs; i++)
	{
		enJeu += (joueurs[i].isStillPlaying()) ? 1 : 0;
	}
	
	return enJeu;
}

void Jeu::lancerPartie()
{
	if (nbJoueurs < 2)
	{
		std::cout << "Il n'y a pas assez de joueurs pour commencer une partie..." << std::endl;
		return;
	}

	std::cout << "La partie commence, bon courage à tous !" << std::endl;
	std::cout << "Chacun va jeter les dés, celui qui aura le score le plus élevé commencera la partie." << std::endl;

	//Lancer les dés
	//Le joueur qui a le max commence son index est first
	int first = 0;
	
	int player = first;
	while (getNbrJoueursEnJeu() > 1)
	{
		jouerTour(player);
		player = joueurSuivant(player);
	}
}

void Jeu::terminerPartie()
{
	if (getNbrJoueursEnJeu() > 1) return;
	//Faire l'annonce du gagnant
}

int Jeu::joueurSuivant(int actual)
{
	if (nbJoueurs < 2) return 0;
	int next = (actual + 1) % nbJoueurs;
	while (!joueurs[next].isStillPlaying()) {
		next = (next + 1) % nbJoueurs;
	}
	return next;
}

void Jeu::jouerTour(int index)
{
	Joueur* player = &joueurs[index];
	
	std::cout << "C'est au tour de " << player->getPseudo() << " !" << std::endl;

	//Gérer le cas prison

	do {
		std::cout << "Lancement des dés : " << endl;
		int de1 = getRandomNumber();
		int de2 = getRandomNumber();
		std::cout << "Dé 1 : " << de1 << " ; dé 2 : " << de2 << endl;

		if (de1 == de2) {
			player->has_a_double(1);
			std::cout << player->getPseudo() << " a fait " << player->howManyDoubles() << " double(s)." << endl;
		}
		else if (player->howManyDoubles() > 0) {
			player->has_a_double(-player->howManyDoubles()); //retour à 0 !
		}

		if (player->howManyDoubles() >= 3) {
			//Le joueur va en prison
		}
		else {
			int nbPas = de1 + de2;
			std::cout << player->getPseudo() << " avance de " << nbPas << " cases." << endl;
			board.deplacer(player, nbPas);
			board[player->getPosition()]->arriverSur(*player);
		}

	} while (player->howManyDoubles() > 0);
}
