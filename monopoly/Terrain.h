#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Propriete.h"
using namespace std;

class Terrain : public Propriete
{
private: 
	int num_terrain;
	int nbMaison;
	int nbHotel;
	int Loyer[6];
	int mesConstructions[9];


public:
	Terrain(string Nom, int prix, int num_case, int num_terrain, int maison1, int maison2, int maison3, int maison4, int hotel, int prix_maison); 
	int getNum_terrain() { return num_terrain; };
	int getNbMaison() { return nbMaison; };
	int getNbHotel() { return nbHotel; };
	int getLoyer() { return Loyer[6]; };
	int getmesConstructions() { return mesConstructions[9]; };
	/***void setGroupe(Terrain*& T1, Terrain*& T2);
	void setGroupe(Terrain*& T1, Terrain*& T2, Terrain*& T3);**/
};

