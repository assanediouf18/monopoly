#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Propriete.h"
using namespace std;

class Terrain : protected Propriete
{
private: 
	int achat;
	int num_case;
	int num_terrain;
	int nbMaison;
	int nbHotel;
	string Nom;
	int Loyer[6];
	int mesConstructions[];


public:
	Terrain(string Nom, int prix, int num_case, int num_terrain, int maison1, int maison2, int maison3, int maison4, int hotel, int prix_maison); 
	/***void setGroupe(Terrain*& T1, Terrain*& T2);
	void setGroupe(Terrain*& T1, Terrain*& T2, Terrain*& T3);**/
};

