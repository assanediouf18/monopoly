#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Propriete.h"
using namespace std;

class Terrain : public Propriete
{
private: 
	int nbMaison;
	int loyer[6];
	int prixmaison;
	Terrain* groupe[2];
	int nbVoisin;


public:
	Terrain();
	Terrain(string Nom, int prix, int num_case, int terrainnu, int maison1, int maison2, int maison3, int maison4, int hotel, int prix_maison); 
	int getNbMaison() { return nbMaison; };
	int getLoyer() { return loyer[0]; };
	
	virtual void arriverSur(Joueur& Joueuractuel);
	
	void ajouterMaison(Joueur* Joueuractuel);
	void setGroupe(Terrain * moi, Terrain * voisin);
	void setGroupe(Terrain * moi, Terrain * voisin1, Terrain * voisin2);
	bool groupeEntier(Joueur* Joueuractuel);
	void setGroupe(Terrain* voisin);
};

