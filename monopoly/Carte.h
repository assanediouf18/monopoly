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
	int reculeDe3Cases;
	int b;
	int c;

public:

	Carte(int idCarte = 0, int reculeDe3Cases = 0, int montant = 0, int prisonOUPasCarte = 0, int bCarte = 0, int cCarte = 0, int impactPlateau = 0, string str = "");
	void setId(int idCarte) {id = idCarte;};
	void setImpact(int montant) { impactTreso = montant; };
	void setIdCasePlateau(int impactPlateau) { idCasePlateau = impactPlateau; };
	void setConsigne(string str) { consigne = str; };
	void setPrisonOuPas(int prisonOUPasCarte) { prisonOuPas = prisonOUPasCarte; };
	void setReculeDe3Cases(int reculeDe3CasesCarte) { reculeDe3Cases = reculeDe3CasesCarte; };
	int getId() { return id; };
	int getImpact() { return impactTreso; };
	int getIdCasePlateau() { return idCasePlateau; };
	string getConsigne() {return consigne;};
	int getPrisonOuPas() { return prisonOuPas; };
	int getReculeDe3Cases() { return reculeDe3Cases; };
};


#endif /* JEU_H_ */
