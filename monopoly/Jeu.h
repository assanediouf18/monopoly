/*
 * Jeu.h
 *
 *  Created on: 3 janv. 2023
 *      Author: samid
 */

#ifndef JEU_H_
#define JEU_H_

#include "joueur.h"


#include <iostream>
using namespace std;

class Jeu {

private:
	int nbJoueurs;
	Joueur* joueurs;

public:
	Jeu();//std::string config = "0");
	//~Jeu();
	int getNbrJoueursEnJeu();
	void lancerPartie();
	void terminerPartie();
	int joueurSuivant(int JoeurActuel);
	//void enchère(Propriete);
	void jouerTour(Joueur*);


};


#endif /* JEU_H_ */
