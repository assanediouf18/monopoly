/*
 * Jeu.h
 *
 *  Created on: 3 janv. 2023
 *      Author: samid
 */

#ifndef JEU_H_
#define JEU_H_

#include <iostream>
#include <cstdlib>
#include "joueur.h"
#include "Plateau.h"
#include "banque.h"

using namespace std;

class Jeu {

private:
	int nbJoueurs, first;
	Joueur* joueurs;
	Plateau board;
	Banque bank;
	
	/**
	* Calcule un nombre Aleatoire contenu entre 1 et 6
	* Attention : utilise rand(), s'assurer d'avoir srand(time(0)) avant utilisation
	**/
	int getRandomNumber();
	void lancerDe(Joueur* player);
	
	void savePlayers(std::ofstream& saveFile);
	void getPlayers(std::ifstream& readFile);

	/***
	* Renvoie l'action du joueur en tenant compte de son mode de jeu
	***/
	char getPlayerAction(Joueur* player);
	/***
	* Affiche le nom du joueur, son solde et ses propriétes s'il en a
	***/
	void printPlayerProperties(Joueur* player);
	/***
	* Affiche les proprietes du joueur
	***/
	void showPlayer(Joueur* player);
	/***
	* Cette fonction récupére le choix du joueur pour les actions de vente, de construction et d'hypotheque
	***/
	std::string saleChoice(Joueur* player, std::string saleType);
	void sale(int pIndex);
	void build(int pIndex);
	void hypotheque(int pIndex);

public:
	Jeu(std::string config = "0");
	//~Jeu();
	int getNbrJoueursEnJeu();
	void lancerPartie();
	void terminerPartie();
	int joueurSuivant(int JoeurActuel);
	//void enchère(Propriete);
	void jouerTour(int index);
	void save(std::string filename, int actualPlayer);
	void read(std::string filename);
};


#endif /* JEU_H_ */
