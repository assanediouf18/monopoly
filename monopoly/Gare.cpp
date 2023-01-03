#include "Gare.h"

Gare::Gare(string nom, int prix, int idCase):Propriete(nom, prix, idCase) {
}

void Gare::acheter(Joueur * Joueuractuel){
	if (estachetee) {}
	else {
		string avisJoueur;
		cout << "Cette gare n'a pas de proprietaire, voulez-vous l'acheter pour " << getAchat() << " euros ? Repondez soit 'Oui' soit 'Non'" << endl;
		cin >> avisJoueur;
		if (avisJoueur == "Oui") {
			setProprietaire(Joueuractuel);
			Joueuractuel->setSolde(Joueuractuel->getSolde() - achat);
			setEstachetee(true);
			Joueuractuel->setMesGares(Joueuractuel->getMesGares() + 1);
			cout << "Vous etes le nouveau proprietaire, felicitations ! " << endl;
		}
	}
}

void Gare::arriverSur(Joueur* joueur) {
	Joueur Joueuractuel = *joueur;
	Joueur * Proprietaire=getProprietaire();
	if (estachetee) {
		if (joueur == Proprietaire) {
			cout << "Vous possedez cette gare, bravo" << endl;
			hypothequer(Joueuractuel);
		}
		else {
			if (getEsthypothequee()) { cout << "La gare est hypothequee" << endl; }
			else{
				if (Joueuractuel.getMesGares() == 1) {
					Joueuractuel.setSolde(Joueuractuel.getSolde() - 25);
					Proprietaire->setSolde(Proprietaire->getSolde() + 25);
					cout << "Vous avez une seule gare, vous payez donc un loyer de 25 M." << endl;
				}
				if (Joueuractuel.getMesGares() == 2) {
					Joueuractuel.setSolde(Joueuractuel.getSolde() - 50);
					Proprietaire->setSolde(Proprietaire->getSolde() + 50);
					cout << "Vous avez deux gares, vous payez donc un loyer de 50 M." << endl;
				}
				if (Joueuractuel.getMesGares() == 3) {
					Joueuractuel.setSolde(Joueuractuel.getSolde() - 100);
					Proprietaire->setSolde(Proprietaire->getSolde() + 100);
					cout << "Vous avez trois gares, vous payez donc un loyer de 100 M." << endl;
				}
				if (Joueuractuel.getMesGares() == 4) {
					Joueuractuel.setSolde(Joueuractuel.getSolde() - 200);
					Proprietaire->setSolde(Proprietaire->getSolde() + 200);
					cout << "Vous avez quatre gares, vous payez donc un loyer de 200 M." << endl;
				}
				else {
					cout << "Vous n'avez pas de gare pour l'instant, vous ne payez donc pas de loyer :)" << endl;
				}
			}
		}
	}
	else {
		acheter(joueur);
	}
	cout << "Votre solde actuel est de " << Joueuractuel.getSolde() << endl;
}


void Gare::setAutresGares(Gare* G1, Gare* G2, Gare* G3) {
	autres_gares[0] = G1;
	autres_gares[1] = G2;
	autres_gares[2] = G3;
}