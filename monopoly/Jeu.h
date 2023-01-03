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
	int nbrJoueurs;
	Joueur joueurs[];

public:
	jeu jeu(nbrJoueurs);
	jeu ~jeu();
	int getNbrJoueursEnJeu();
	void lancerPartie();
	void terminerPartie();
	int joueurSuivant(int JoeurActuel);
	enchère(Propriete);
	jouerTour(Joueur);
	Jeu(config = "0")


};


#endif /* JEU_H_ */
