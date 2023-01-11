#include "Jeu.h"
#include "malloc.h"

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
	int next = actual + 1;
	while (!joueurs[next].isStillPlaying()) {
		next += 1;
		next = next % nbJoueurs;
	}
	return next;
}

void Jeu::jouerTour(int index)
{
	Joueur* player = &joueurs[index];
	
	std::cout << "C'est au tour de " << player->getPseudo() << " !" << std::endl;

	//Gérer le cas prison

	//Lancer les dés
	int nbPas = 6;
	/*
	Bougez votre pion d’autant de cases que le nombre de points indiqué sur les dés et
	dans le sens des aiguilles d’une montre.
	La case où vous vous arrêterez déterminera ce que vous avez à faire.
	*/

	board.deplacer(player, nbPas);

	/*
	Si vous passez par ou vous arrêtez sur la case DÉPART, vous recevez M200 de la Banque.
	*/

	/*
	Si vous faites un double aux dés, effectuez les opérations habituelles sur la case où vous vous arrêtez
	puis relancez les dés(étapes 1 à 4).
	Attention !Si vous faites trois doubles de suite, rendez - vous immédiatement en prison.
	*/
	board[player->getPosition()]->arriverSur(*player);
	/*
	Lorsque vous avez terminé votre tour, donnez les dés au joueur situé sur votre gauche.
	*/
}
