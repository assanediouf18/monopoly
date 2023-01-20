#include "test.h"
#include "Jeu.h"

using namespace std;

void testerChargementJeu()
{
	std::cout << "Test de chargement de fichier de sauvegarde" << endl;
	std::cout << "Chargement de exemple.txt" << endl;
	std::string filename = "Partie1";
	Jeu global(filename);
	global.lancerPartie();
}

void testerSauvegardeJeu()
{
	Jeu global;
	string filename = "exemple.txt";
	global.save(filename, 0);
	cout << "S'il n'y a pas eu de message d'erreurs, "<< filename <<" vient d'apparaitre : " << endl;
	system("ls");
	cout << "Ouverture de " << filename << " :" << endl;
	string catCmd = "cat " + filename;
	system(catCmd.c_str());
	string deleteCmd = "rm " + filename + " && ls";
	cout << "On supprime le fichier " << filename << " :" << endl;
	system(deleteCmd.c_str());
}

void testerLectureJeu()
{
	Jeu global;
	string filename = "exemple.txt";
	cout << "S'il n'y a pas eu de message d'erreurs, " << filename << " vient d'apparaitre : " << endl;
	system("ls");
	cout << "Ouverture de " << filename << " :" << endl;
	string catCmd = "cat " + filename;
	system(catCmd.c_str());
	global.read(filename);
}

void testerProprieteJoueur()
{
	Terrain paix("Rue de la Paix", 400, 39, 50, 200, 600, 1400, 1700, 2000, 200);
	Terrain elysees("Avenue des Champs-Élysées", 350, 37, 35, 175, 500, 1100, 1300, 1500, 200);
	Gare lazare("Gare Saint Lazare", 200, 35);

	Joueur j;
	j.addProperty(paix.getNb_case());
	j.addProperty(elysees.getNb_case());
	j.addProperty(lazare.getNb_case());

	std::vector<int> properties = j.getProprietes();
	for (int i = 0; i < properties.size(); i++)
	{
		cout << properties[i] << endl;
	}
	cout << "On s'attend à voir 39, 37 et 35" << endl;
	
	cout << "le joueur perd la rue de la paix" << endl;
	j.removeProperty(paix.getNb_case());
	properties = j.getProprietes();
	for (int i = 0; i < properties.size(); i++)
	{
		cout << properties[i] << endl;
	}
	cout << "On s'attend à voir 37 et 35" << endl;
	
	cout << "le joueur perd la propriété 45" << endl;
	j.removeProperty(45);
	properties = j.getProprietes();
	for (int i = 0; i < properties.size(); i++)
	{
		cout << properties[i] << endl;
	}
	cout << "On s'attend à voir 37 et 35" << endl;
}

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
	G.acheter(&J, *bank);
	cout << std::boolalpha << G.getEstachetee() << endl;
	G.arriverSur(J, *bank);
	delete bank;
}

void testerCompagnie() {
	cout << "Test de la classe Compagnie" << endl;
	Joueur J = Joueur();
	Banque* bank = new Banque();
	cout << "votre pseudo est" << J.getPseudo() << endl;
	Compagnie C1=Compagnie("Compagnie de distribution d'électricité", 150, 12);
	Compagnie C2=Compagnie("Compagnie de distribution des eaux", 150, 28);
	C1.arriverSur(J, *bank);
	delete bank;
}
