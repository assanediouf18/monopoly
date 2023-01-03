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

void testerGare() {
	cout << "Test de la classe Gare" << endl;
	Joueur J = Joueur();
	cout << "votre pseudo est" << J.getPseudo() << endl;
	Gare G = Gare("Saint Laz", 400, 5);
	G.acheter(J);
	cout << std::boolalpha << G.getEstachetee() << endl;
	G.arriverSur(J,2);
}

void testerCompagnie() {
	cout << "Test de la classe Compagnie" << endl;
	Joueur J = Joueur();
	cout << "votre pseudo est" << J.getPseudo() << endl;
	Compagnie C1=Compagnie("Compagnie de distribution d'électricité", 150, 12);
	Compagnie C2=Compagnie("Compagnie de distribution des eaux", 150, 28);
	C1.arriverSur(J, 12);
}