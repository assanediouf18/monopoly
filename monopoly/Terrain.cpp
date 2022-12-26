#include "Terrain.h"
#include <string>
using namespace std;

Terrain::Terrain(string nom, int prix, int num_case, int nb_terrain, int maison1, int maison2, int maison3, int maison4, int hotel, int prix_maison):Propriete(nom, prix, num_case) {
	std::string Nom = nom;
	int achat = prix;
	int Loyer[6] = { maison1, maison2, maison3, maison4, hotel, prix_maison };
	int nb_case = num_case;
	int num_terrain = nb_terrain;
}
