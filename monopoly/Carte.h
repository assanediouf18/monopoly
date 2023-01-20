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
	int idCasePlateau;
	int prisonOuPas;
	int a;
	int b;
	int c;

public:

	Carte(int idCarte, int aCarte, int montant, int prisonOUPasCarte, int bCarte, int cCarte, int impactPlateau, string str);
	void setId(int idCarte) {id = idCarte;};
	void setImpact(int montant) { impactTreso = montant; };
	void setIdCasePlateau(int impactPlateau) { idCasePlateau = impactPlateau; };
	void setConsigne(string str) { consigne = str; };
	void setPrisonOuPas(int prisonOUPasCarte) { prisonOuPas = prisonOUPasCarte; };
	int getId() { return id; };
	int getImpact() { return impactTreso; };
	int getIdCasePlateau() { return idCasePlateau; };
	string getConsigne() {return consigne;};
	int getPrisonOuPas() { return prisonOuPas; };
};


#endif /* JEU_H_ */
