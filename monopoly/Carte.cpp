#include "Carte.h"
#include <iostream>
using namespace std;

/***
liste_carte_chance[0] = Carte(1, 0, 50, 0, 0, 0, -1, "La Banque vous verse une dividende de 50€.");
string Consigne;
int id;
int ImpactTreso;
int id_carteSuivante;
**/

Carte::Carte(int idCarte, int int1, int int2, int int3, int int4, int int5, int impactPlateau, string str) {
	consigne = str;
	id = idCarte;
	x = int1;
	impactTreso = int2;
	y = int3;
	z = int4;
	a = int5;
	idCartePlateau = impactPlateau;
}