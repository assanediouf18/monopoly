#include "Terrain.h"
#include <string>
using namespace std;

Terrain::Terrain(string nom, int prix, int nb_case, int nb_terrain, int maison1, int maison2, int maison3, int maison4, int hotel, int prix_maison):Propriete(nom, prix, nb_case) {
	string Nom = nom;
	int achat = prix;
	int Loyer[6] = { maison1, maison2, maison3, maison4, hotel, prix_maison };
	int num_case = nb_case;
	int num_terrain = nb_terrain;
}
