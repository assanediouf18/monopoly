#include "test.h"
#include "Prison.h"
#include "Jeu.h"
#include "Plateau.h"

using namespace std;

void testerJeu()
{
	Jeu global;
	global.lancerPartie();
}

void testerPlateau()
{
	Plateau board;
}

void indiquerJoueur()
{
	Joueur A;
	std::cin >> A;
	cout << endl;
	std::cout << A << endl;
}

void testerTerrain()
{
	cout << "Test de la classe Terrain" << endl;
	Joueur J = Joueur();
	Banque* bank = new Banque();
	Terrain T1 = Terrain("Rue Lecourbe", 60, 3, 4, 20, 60, 180, 320, 450, 50);
	Terrain T0 = Terrain("Boulevard de Belleville", 60, 1, 2, 10, 30, 90, 160, 250, 50);
	T0.setGroupe(&T0, &T1);
	T1.arriverSur(J, (*bank));
	cout << std::boolalpha << T1.getEstachetee() << endl;
	Joueur J2 = Joueur();
	T1.arriverSur(J2, (*bank));
	T1.arriverSur(J, *bank);
	T1.arriverSur(J2, *bank);
	T0.arriverSur(J, *bank);
	T1.arriverSur(J2, *bank);
	T0.arriverSur(J, *bank);
	T0.arriverSur(J2, *bank);
	
}

void testerPropriete() {
	cout << "Test de la classe Propriete" << endl;
	Joueur J=Joueur();
	// pas de test possible pcq Propriete  
}

void testerGare() {
	cout << "Test de la classe Gare" << endl;
	Joueur J = Joueur();
	Banque* bank = new Banque();
	cout << "votre pseudo est" << J.getPseudo() << endl;
	Gare G = Gare("Saint Laz", 400, 5);
	G.acheter(&J);
	cout << std::boolalpha << G.getEstachetee() << endl;
	G.arriverSur(J, *bank);
	delete bank;
}

void testerCompagnie() {
	cout << "Test de la classe Compagnie" << endl;
	Joueur J = Joueur();
	Banque* bank = new Banque();
	cout << "votre pseudo est" << J.getPseudo() << endl;
	Compagnie C1=Compagnie("Compagnie de distribution d'�lectricit�", 150, 12);
	Compagnie C2=Compagnie("Compagnie de distribution des eaux", 150, 28);
	C1.arriverSur(J, *bank);
	delete bank;
}
