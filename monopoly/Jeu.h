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

using namespace std;

class Jeu {

private:
	int nbJoueurs;
	Joueur* joueurs;
	Plateau board;
	
	/**
	* Calcule un nombre aléatoire contenu entre 1 et 6
	* Attention : utilise rand(), s'assurer d'avoir srand(time(0)) avant utilisation
	**/
	int getRandomNumber();
	void lancerDe(Joueur* player);
	//void menu(Joueur* j);

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
};


#endif /* JEU_H_ */
