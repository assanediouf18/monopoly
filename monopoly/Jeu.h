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
	//void menu(Joueur* j);
	void savePlayers(std::ofstream& saveFile);
	/***
	* Sauvegarde le nombre de maisons et le nombre d'hotels pour chaque ptés
	***/
	void saveBoard(std::ofstream& saveFile);
	void getPlayers(std::ifstream& readFile);
	void getBoard(std::ifstream& readFile);

	char getPlayerAction(Joueur* player);
	void printPlayerProperties(Joueur* player);
	void showPlayer(Joueur* player);

	std::string saleChoice(Joueur* player, std::string saleType);
	void sale(int pIndex);
	void hypotheque(int pIndex);

public:
	Jeu(std::string config = "0");
	//~Jeu();
	int getNbrJoueursEnJeu();
	void lancerPartie();
	void terminerPartie();
	//Ajouter de quoi gérer l'exception causée par le fait qu'il n'y a pas assez de joueurs
	int joueurSuivant(int JoeurActuel);
	//void enchère(Propriete);
	void jouerTour(int index);
	//sauvegarde le jeu dans filename
	void save(std::string filename, int actualPlayer);
	void read(std::string filename);
};


#endif /* JEU_H_ */
