#include "Terrain.h"
#include <string>
using namespace std;

Terrain::Terrain() : Propriete("nom", 0, 0)
{
	Nom = "Terrain";
	achat = 0;
	loyer[0] = 0;
	loyer[1] = 0;
	loyer[2] = 0;
	loyer[3] = 0;
	loyer[4] = 0;
	loyer[5] = 0;
	prixmaison = 0;
	nb_case = 0;
	nbMaison = 0;
	nbVoisin = 0;

	groupe[0] = NULL;
	groupe[1] = NULL;
}

Terrain::Terrain(string nom, int prix, int num_case, int terrainnu, int maison1, int maison2, int maison3, int maison4, int hotel, int prix_maison):Propriete(nom, prix, num_case) {
	loyer[0] = terrainnu;
	loyer[1] = maison1;
	loyer[2] = maison2;
	loyer[3] = maison3;
	loyer[4] = maison4;
	loyer[5] = hotel;
	prixmaison = prix_maison;
	nbMaison = 0;
	nbVoisin = 0;

	groupe[0] = NULL;
	groupe[1] = NULL;
}

void Terrain::arriverSur(Joueur& J, Banque& bank){
	Propriete::arriverSur(J, bank);
	Joueur* Joueuractuel = &J;
	Proprietaire = getProprietaire();
	if (estachetee==true) {
		if (Joueuractuel == Proprietaire) {
			cout << "Vous possedez ce terrain, bravo" << endl;
			hypothequer(Joueuractuel, bank);
		}
		else {
			if (getEsthypothequee()) {
				cout << "Le terrain est hypotheque" << endl;
			}
			else {
				Joueuractuel->setSolde(Joueuractuel->getSolde() - loyer[nbMaison]);
				Proprietaire->setSolde(Proprietaire->getSolde() + loyer[nbMaison]);
				cout << "Le proprietaire a " << getNbMaison() << " maisons vous payez donc un loyer de " << loyer[nbMaison] << " a " << Proprietaire->getPseudo() << endl;
			}
		}
	}
	else {
		acheter(Joueuractuel, bank);
	}
}

std::string Terrain::print()
{
	return std::to_string(nbMaison);
}

void Terrain::ajouterMaison(Joueur* Joueuractuel, Banque& bank)
{
	if (groupeEntier(Joueuractuel)) {
		bank.recevoir(prixmaison, *Joueuractuel);
		nbMaison++;
		if (nbMaison == 5) {
			cout << "Vous possedez desormais un hotel a " << Nom << endl;
		}
		else {
			cout << "Vous venez d'acheter une maison a " << Nom << " qui a maintenant " << nbMaison << " maisons." << endl;
		}
	}
	else {
		cout << "Pour pouvoir construire il faut poss�der un groupe et ";
		cout << "il faut que la diff�rences entre le nombre de maisons d'un groupe soit d'au plus 1..." << endl;
	}
}

void Terrain::construire(Joueur* Joueuractuel, Banque& bank)
{
	if (nbMaison >= 5)
	{
		cout << "Il n'est pas possible de construire davantage ici..." << endl;
		cout << "Mais invitez vos amis � s�journer dans votre hotel !" << endl;
		return;
	}
	std::string building = (nbMaison == 4) ? "un hotel" : "une maison";
	std::string avisJoueur;
	cout << "Voulez-vous construire " << building << " ? R�pondez 'Oui' si vous le voulez. (avec la majuscule !)" << endl;
	avisJoueur = choixAchat(Joueuractuel);
	if (avisJoueur == "Oui") {
		ajouterMaison(Joueuractuel, bank);
	};
}

bool Terrain::groupeEntier(Joueur* Joueuractuel)
{
	bool possedeTout= (Joueuractuel == Proprietaire);
	for (int i = 0; i < nbVoisin; i++) {
		if (groupe[i]->getEstachetee()) {
			possedeTout = (groupe[i]->getProprietaire()== Joueuractuel);
		}
		else {
			possedeTout = false;
		}
	}
	return possedeTout;
}

void Terrain::setGroupe(Terrain * moi, Terrain * voisin){
	groupe[0] = voisin;
	nbVoisin = 1;
	//voisin->setGroupe(moi);
	voisin->groupe[0] = moi;
	voisin->nbVoisin = 1;
}

void Terrain::setGroupe(Terrain* voisin) {
	groupe[0] = voisin;
	nbVoisin = 1;
}

void Terrain::setGroupe(Terrain * moi, Terrain * voisin1, Terrain * voisin2) {
	moi->groupe[0] = voisin1;
	moi->groupe[1] = voisin2;
	moi->nbVoisin = 2;

	voisin1->groupe[0] = moi;
	voisin1->groupe[1] = voisin2;
	voisin1->nbVoisin = 2;
	
	voisin2->groupe[0] = moi;
	voisin2->groupe[1] = voisin1;
	voisin2->nbVoisin = 2;
}

