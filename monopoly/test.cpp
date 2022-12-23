#include "test.h"

using namespace std;

void testerTerrain()
{
	cout << "Test de la classe Terrain" << endl;
	Terrain Terrain("Rue de la Paix", 400, 39, 50, 200, 600, 1400, 1700, 2000, 200);

}

void testerPropriete() {
	cout << "Test de la classe Propriete" << endl;
	Joueur J=Joueur();
	Case C=Case("Terrain");
	Propriete P=Propriete("Terrain", 400, 3);
	P.acheter(J);

}