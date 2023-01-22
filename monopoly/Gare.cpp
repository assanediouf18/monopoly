#include "Gare.h"

Gare::Gare(string nom, int prix, int idCase):Propriete(nom, prix, idCase) {
	autres_gares[0] = NULL;
	autres_gares[1] = NULL;
	autres_gares[2] = NULL;
}

void Gare::acheter(Joueur * Joueuractuel, Banque& bank){
	if (estachetee) {}
	else {
		string avisJoueur;
		cout << "Cette gare n'a pas de proprietaire, voulez-vous l'acheter pour " << getAchat() << " euros ? Repondez soit 'Oui' soit 'Non'" << endl;
		avisJoueur = choixAchat(Joueuractuel);
		if (avisJoueur == "Oui") {
			setProprietaire(Joueuractuel);
			bank.recevoir(getAchat(), *Joueuractuel);
			setEstachetee(true);
			Joueuractuel->setMesGares(Joueuractuel->getMesGares() + 1);
			cout << "Vous etes le nouveau proprietaire, felicitations ! " << endl;
			cout << Joueuractuel->getPseudo() << " a desormais un solde de " << Joueuractuel->getSolde() << endl;
			cout << "Voici le titre de propriete de " << Nom << endl;
			cout << "Le loyer sera de :" << endl;
			cout << " - 25 M si vous possèdez 1 gare" << endl;
			cout << " - 50 M si vous possèdez 2 gares" << endl;
			cout << " - 100 M si vous possèdez 3 gares" << endl;
			cout << " - 200 M si vous possèdez 3 gares" << endl;
			cout << "L'hypothèque est de " << hypotheque << " M" << endl;
		}
		else {
			std::cout << Joueuractuel->getPseudo() << " n'achète pas." << endl;
		}
	}
}

void Gare::arriverSur(Joueur& Joueuractuel, Banque& bank) {
	Propriete::arriverSur(Joueuractuel, bank);
	Joueur * Proprietaire=getProprietaire();
	if (estachetee) {
		if (Joueuractuel == Proprietaire) {
			cout << "Vous possedez cette gare, bravo" << endl;
		}
		else {
			if (getEsthypothequee()) { cout << "La gare est hypothequee" << endl; }
			else{
				if (Proprietaire->getMesGares() == 1) {
					cout << "Vous avez une seule gare, vous payez donc un loyer de 25 M." << endl;
					Joueuractuel.setSolde(Joueuractuel.getSolde() - 25);
					Proprietaire->setSolde(Proprietaire->getSolde() + 25);
				}
				if (Proprietaire->getMesGares() == 2) {
					cout << "Vous avez deux gares, vous payez donc un loyer de 50 M." << endl;
					Joueuractuel.setSolde(Joueuractuel.getSolde() - 50);
					Proprietaire->setSolde(Proprietaire->getSolde() + 50);
				}
				if (Proprietaire->getMesGares() == 3) {
					cout << "Vous avez trois gares, vous payez donc un loyer de 100 M." << endl;
					Joueuractuel.setSolde(Joueuractuel.getSolde() - 100);
					Proprietaire->setSolde(Proprietaire->getSolde() + 100);
				}
				if (Proprietaire->getMesGares() == 4) {
					cout << "Vous avez quatre gares, vous payez donc un loyer de 200 M." << endl;
					Joueuractuel.setSolde(Joueuractuel.getSolde() - 200);
					Proprietaire->setSolde(Proprietaire->getSolde() + 200);
				}
				else {
					cout << "Cette gare n'a pas de proprietaire donc vous ne payez pas de loyer." << endl;
				}
			}
		}
	}
	else {
		acheter(&Joueuractuel, bank);
	}
}


void Gare::setAutreGares(Gare* G1, Gare* G2, Gare* G3) {
	autres_gares[0] = G1;
	autres_gares[1] = G2;
	autres_gares[2] = G3;
}

void Gare::setAutreGares(Gare* moi, Gare* voisin1, Gare* voisin2, Gare* voisin3) {
	moi->autres_gares[0] = voisin1;
	moi->autres_gares[1] = voisin2;
	moi->autres_gares[2] = voisin3;

	voisin1->autres_gares[0] = moi;
	voisin1->autres_gares[1] = voisin2;
	voisin1->autres_gares[2] = voisin3;

	voisin2->autres_gares[0] = voisin1;
	voisin2->autres_gares[1] = moi;
	voisin2->autres_gares[2] = voisin3;

	voisin3->autres_gares[0] = voisin1;
	voisin3->autres_gares[1] = voisin2;
	voisin3->autres_gares[2] = moi;
}