/*
 * Jeu.h
 *
 *  Created on: 3 janv. 2023
 *      Author: samid
 */

#ifndef CARTE_H_
#define CARTE_H_




#include <iostream>
using namespace std;

class Carte {

private:
	string Consigne;
	int id;
	int ImpactTreso;
	int id_carteSuivante;

public:

	Carte();
	void set();
	void get();
};


#endif /* JEU_H_ */
