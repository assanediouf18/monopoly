#ifndef PLATEAU_H
#define PLATEAU_H

#include <iostream>
#include "Terrain.h"
#include "Gare.h"
#include "case.h"
#include "Compagnie.h"
#include "ListeCartes.h"
#include "Depart.h"
#include "Parc.h"
#include "Prison.h"
#include "Communaute.h"
#include "Chance.h"
#include "Taxe.h"
using namespace std;

class Plateau {

protected:
	Terrain* lesTerrains;
	Taxes* lesTaxes;
	Chance* lesChances;
	Gare* lesGares;
	Communaute* lesCommunautes;
	Prison* lesPrisons;
	Compagnie* lesCompagnies;
	Parc leParc;
	Depart leDepart;
	Case* liste_cases;
	ListeCartes listeCarte;
	int nbMaxMaisons;
	int nbMaxHotels;

public:
	Plateau();

	void caseSuivante(Case);
	void deplacer(Joueur&, int);

	void setPlateau(string adresse) {
		this->adresse = adresse;
	}

	void setTelephone(string telephone) {
		this->telephone = telephone;
	}

	string getNom() {
		return nom;
	}

	string getPrenom() {
		return prenom;
	}

	string getAdresse() {
		return adresse;
	}

	string getTelephone() {
		return telephone;
	}
};

#endif
