#include <fstream>
#include <string>
#include "Jeu.h"
#include "malloc.h"

int Jeu::getRandomNumber()
{
	return (rand() % 6) + 1;
}

Jeu::Jeu(std::string config) : board(), bank()
{
	joueurs = NULL;
	nbJoueurs = 0;
	first = -1;

	if (config != "0")
	{
		read(config);
		return;
	}

	std::cout << "Combien de joueurs etes-vous ?";
	std::cin >> nbJoueurs;

	if (nbJoueurs <= 1) {
		cout << "Desole, le Monopoly se joue au moins a deux..." << endl;
		return;
	}

	joueurs = new Joueur[nbJoueurs];

	int startingMoney = 2 * 500 + 4 * 100 + 50 + 20 + 2 * 10 + 5 + 5;

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

	std::cout << "Avant de commencer, veuillez declarer le mode de chaque joueur : Aleatoire, Automatique ou Manuel" << std::endl;
	for (int i = 0; i < nbJoueurs; i++)
	{
		std::cout << "Quelle est le mode du joueur " << joueurs[i].getPseudo() << " ? " << std::endl;
		std::string mode;
		std::cin >> mode;
		joueurs[i].setMode(mode);
	}

	std::cout << "La partie commence, bon courage a tous !" << std::endl;
	std::cout << "Chacun va jeter les des, celui qui aura le score le plus eleve commencera la partie." << std::endl;

	if (first < 0)
	{
		int max = 0;
		for (int i = 0; i < nbJoueurs; i++) {
			if (joueurs[i].getMode() == "Manuel")
			{
				std::cout << joueurs[i].getPseudo() << " appuies sur une touche pour lancer des des. " << endl;

				std::string validation;
				std::cin >> validation;
			}

			int de1 = getRandomNumber();
			int de2 = getRandomNumber();
			std::cout << "De 1 : " << de1 << " ; de 2 : " << de2 << endl;
			int total = de1 + de2;
			if (total > max) {
				max = total;
				first = i;
				std::cout << "Le score est de " << total << std::endl;
			}
		}

		std::cout << "Avec un score de " << max << " " << joueurs[first].getPseudo() << " va commencer" << std::endl;
	}
	
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

void Jeu::lancerDe(Joueur* player)
{
	do {
		std::cout << "Lancement des des : " << endl;
		int de1 = getRandomNumber();
		int de2 = getRandomNumber();
		std::cout << "De 1 : " << de1 << " ; de 2 : " << de2 << endl;

		if (de1 == de2) {
			player->has_a_double(1);
			std::cout << player->getPseudo() << " a fait " << player->howManyDoubles() << " double(s)." << endl;
			if (player->isInPrison())
			{
				std::cout << player->getPseudo() << " sort de prison !" << endl;
				player->getOutOfPrison();
			}
		}
		else if (player->howManyDoubles() > 0) {
			player->has_a_double(-player->howManyDoubles()); //retour à 0 !
		}

		if (player->howManyDoubles() >= 3) {
			//Le joueur va en prison
			player->setPosition(Plateau::prisonLocation);
		}
		else {
			if (player->isInPrison())
			{
				std::cout << player->getPseudo() << " est en prison et ne peut pas bouger..." << endl;
				return;
			}
			int nbPas = de1 + de2;
			std::cout << player->getPseudo() << " avance de " << nbPas << " cases." << endl;
			board.deplacer(player, nbPas, bank);
			int pos = player->getPosition();
			board[player->getPosition()]->arriverSur(*player, bank);
			if (player->getPosition() != pos) {
				board[player->getPosition()]->arriverSur(*player, bank);
			}
		}

	} while (player->howManyDoubles() > 0);
}

void Jeu::jouerTour(int index)
{
	Joueur* player = &joueurs[index];
	bool hasPlayed = false, diceRolled = false;

	std::cout << "##############################################################" << endl;
	std::cout << "C'est au tour de " << player->getPseudo() << " !" << std::endl;

	//Gérer le cas prison
	if (player->getTempsPrison() >= 0) {
		//diceRolled = true;
		if (player->getPosition() != 10) {
			player->setPosition(10);
		}
		board[player->getPosition()]->arriverSur(*player, bank);
	}

	do {
		std::cout << "1 - Lancer les des" << std::endl;
		std::cout << "2 - Construire" << std::endl;
		std::cout << "3 - Hypothequer" << std::endl;
		std::cout << "4 - Vendre" << std::endl;
		std::cout << "5 - Voir son profil" << std::endl;
		std::cout << "6 - Finir son tour" << std::endl;
		std::cout << "7 - Sauvegarder la partie" << std::endl;
		
		char c = getPlayerAction(player);

		switch (c) {
		case '1':
			if (!diceRolled) {
				lancerDe(player);
				diceRolled = true;
			}
			else {
				std::cout << "Cette option n'est pas disponible" << std::endl;
			}
			break;
		case '3':
			if (player->hasProperties())
			{
				hypotheque(index);
			}
			else {
				std::cout << "Cette option n'est pas disponible" << std::endl;
			}
			break;
		case '4':
			if (player->hasProperties())
			{
				sale(index);
			}
			else {
				std::cout << "Cette option n'est pas disponible" << std::endl;
			}
			break;
		case '5':
			showPlayer(player);
			break;
		case '6':
			if (!diceRolled) {
				lancerDe(player);
				diceRolled = true;
			}
			hasPlayed = true;
			break;
		case '7':
		{
			cout << "Bienvenue sur la sauvegarde, entrez le nom de votre sauvegarde." << endl;
			cout << "Tapez \"0\" pour annuler." << endl;
			cout << "Nom de la sauvegarde : ";
			std::string filename;
			std::cout << endl;
			cin >> filename;
			if (filename != "0")
			{
				save(filename, index);
			}
		}
			break;
		default:
			std::cout << "Cette option n'est pas disponible" << std::endl;
			break;
		}
	} while (!hasPlayed);
}


void Jeu::savePlayers(std::ofstream& saveFile)
{
	saveFile << nbJoueurs << endl;

	for (int i = 0; i < nbJoueurs; i++)
	{
		Joueur j = joueurs[i];
		saveFile << j.getPseudo() << endl;
		saveFile << j.getSolde() << endl;
		saveFile << j.getPosition() << endl;
		std::vector<int> ptes = j.getProprietes();
		saveFile << ptes.size() << endl;
		for (int j = 0; j < ptes.size(); j++)
		{
			saveFile << ptes[j] << endl;
		}
	}
}

void Jeu::saveBoard(std::ofstream& saveFile)
{
	saveFile << nbJoueurs << endl;

	for (int i = 0; i < NB_CASES; i++)
	{
		saveFile << board[i]->print() << endl;
	}
}

void Jeu::getPlayers(std::ifstream& readFile)
{
	readFile >> nbJoueurs;
	joueurs = new Joueur[nbJoueurs];
	for (int i = 0; i < nbJoueurs; i++)
	{
		std::string pseudo;
		readFile >> pseudo;
		int solde = 0, position = 0, nbPte = 0;
		readFile >> solde;
		readFile >> position;
		joueurs[i].setPseudo(pseudo);
		joueurs[i].setSolde(solde);
		joueurs[i].setPosition(position);
		readFile >> nbPte;
		for (int j = 0; j < nbPte; j++)
		{
			int ptyNb = 0;
			readFile >> ptyNb;
			joueurs[i].addProperty(ptyNb);
			joueurs[i].setTempsPrison(-1); // Changer ce code par la lecture du temps en prison
			//Indiquer à la pté qui est son propriétaire
		}
		cout << joueurs[i] << endl;
	}
}

void Jeu::getBoard(std::ifstream& readFile)
{
	//A améliorer
	for (int i = 0; i < NB_CASES; i++)
	{
		std::string nbMaisons = "";
		readFile >> nbMaisons;
		cout << board[i]->getNom() << " a " << nbMaisons << " maisons" << endl;
	}
}

char Jeu::getPlayerAction(Joueur* player)
{
	char c = '6';
	if (player->getMode() == "Manuel")
	{
		std::cout << "Choisis ton option : ";
		std::string choice;
		std::cin >> choice;
		c = choice[0];
	}
	else if (player->getMode() == "Aleatoire")
	{
		int de = getRandomNumber();
		c = std::to_string(de)[0];
		std::cout << "Action numero :" << c << endl;
	}
	else if (player->getMode() == "Automatique")
	{
		c = '6';
		std::cout << "Action numero : " << c << endl;
	}
	return c;
}

void Jeu::printPlayerProperties(Joueur* player)
{
	std::vector<int> ptes = player->getProprietes();
	if (ptes.size() > 0)
	{
		std::cout << ptes.size() << " proprietes :" << endl;
		for (int i = 0; i < ptes.size(); i++)
		{
			std::cout << " " << i << " - " << board[ptes[i]]->getNom() << endl;
		}
	}
	else {
		cout << "Vous n'avez pas de proprietes..." << endl;
	}
}

void Jeu::showPlayer(Joueur* player)
{
	std::cout << "----------------------------------------------------" << endl;
	std::cout << (*player) << std::endl;
	std::cout << "Position : " << board[player->getPosition()]->getNom() << std::endl;
	printPlayerProperties(player);
	std::cout << "----------------------------------------------------" << endl;
}

std::string Jeu::saleChoice(Joueur* player, std::string saleType)
{
	cout << "Bienvenue dans le menu " << saleType << " de vos proprietes " << player->getPseudo() << endl;
	cout << "(pour en sortir tapez q)" << endl;
	printPlayerProperties(player);
	cout << "Tapez le numero d'une propriete pour la selectionner : ";
	std::string choice;
	cin >> choice;
	return choice;
}

void Jeu::sale(int pIndex)
{
	Joueur* player = &joueurs[pIndex];
	std::string choice = saleChoice(player, "vente");
	if (choice == "q" || choice == "Q")
	{
		cout << "Vous quittez le menu de vente." << endl;
		return;
	}
	try
	{
		int index = stoi(choice);
		std::vector<int> ptes = player->getProprietes();
		int boardLocation = ptes[index];
		board[boardLocation]->vendre(player, bank);
	}
	catch (const std::exception& e)
	{
		cout << "Une erreur est survenue, vous quittez le menu de vente." << endl;
	}
	cout << "Vous quittez le menu de vente." << endl;
}

void Jeu::hypotheque(int pIndex)
{
	Joueur* player = &joueurs[pIndex];
	std::string choice = saleChoice(player, "hypotheque");
	if (choice == "q" || choice == "Q")
	{
		cout << "Vous quittez le menu hypotheque." << endl;
		return;
	}
	try
	{
		int index = stoi(choice);
		std::vector<int> ptes = player->getProprietes();
		int boardLocation = ptes[index];
		board[boardLocation]->hypothequer(player, bank);
	}
	catch (const std::exception& e)
	{
		cout << "Une erreur est survenue, vous quittez le menu hypotheque." << endl;
	}
	cout << "Vous quittez le menu hypotheque." << endl;
}

void Jeu::save(std::string filename, int actualPlayer)
{
	std::ofstream saveFile(filename, ios::out | ios::trunc);
	try
	{
		savePlayers(saveFile);
		saveBoard(saveFile);
		saveFile << actualPlayer << endl;
		saveFile.close();
	}
	catch (const std::exception& e)
	{
		cout << "Desole l'operation de sauvegarde n'a pas fonctionnee..." << endl;
	}
}

void Jeu::read(std::string filename)
{
	std::ifstream configFile(filename, ios::in);
	try
	{
		getPlayers(configFile);
		//Creuser pour les ptés
		getBoard(configFile);
		configFile >> first;
		configFile.close();
	}
	catch (const std::exception& e)
	{
		cout << "Désolé l'opération de sauvegarde n'a pas fonctionnée..." << endl;
	}
}
