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
	string consigne;
	int id;
	int impactTreso;
	int idCartePlateau;
	int x;
	int y;
	int z;
	int a;

public:

	Carte(int idCarte, int int1, int int2, int int3, int int4, int int5, int impactPlateau, string str);
	void setId(int i) {id = i;};
	void setImpact(int i) { impactTreso = i; };
	void setIdCartePlateau(int i) { idCartePlateau = i; };
	void setConsigne(string str) { consigne = str; };
	int getId() { return id; };
	int getImpact() { return impactTreso; };
	int getIdCartePlateau() { return idCartePlateau; };
	string getConsigne() {return Consigne;};
};


#endif /* JEU_H_ */
