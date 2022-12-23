#include "Propriete.h"
#include "joueur.h"
#include "case.h"
using namespace std;

Propriete::Propriete(string Nom, int Prix, int num_case):Case(Nom) {
	int achat=Prix;
	int hypotheque = achat / 2;
	int nb_case = num_case;
	int estachetee = 0;
	int esthypothequee = 0;
}

void Propriete::acheter(Joueur Joueuractuel){
	string avisJoueur;
	cout << "Cette propriete n'a pas de proprietaire, voulez-vous l'acheter pour " << achat<< " euros ? Repondez soit 'Oui' soit 'Non'" << endl;
	cin >> avisJoueur;
	if (avisJoueur == "Oui" or avisJoueur == "oui") {
		if (Joueuractuel.getSolde() >= getAchat()) {
			Joueur Proprietaire = Joueuractuel;
			Joueuractuel.setSolde(Joueuractuel.getSolde() - getAchat());
			setEstachetee(1);
			cout << "Vous etes le nouveau proprietaire, felicitations ! " << endl;
		}
		else {
			cout << "Votre solde est insuffisant pour acheter cette propriete. Vous risquez d'être en negatif. Voulez-vous quand-meme acheter la propriete ?" << endl;
			cin >> avisJoueur;
			if (avisJoueur == "Oui" or avisJoueur == "oui") {
				if (Joueuractuel.getSolde() >= getAchat()) {
					Joueur Proprietaire = Joueuractuel;
					Joueuractuel.setSolde(Joueuractuel.getSolde() - getAchat());
					int estachetee = 1;
					cout << "Vous êtes le nouveau proprietaire, felicitations ! " << endl;
				}
				else {}
			}
		}
	}
}


void Propriete::hypothequer(Joueur Joueuractuel){
	if (getEstachetee() == 1) {
		string avisJoueur;
		cout << "Voulez-vous hypothequer votre bien?" << endl;
		cin >> avisJoueur;
		if (avisJoueur == "Oui" or avisJoueur == "oui") {
			Joueuractuel.setSolde(Joueuractuel.getSolde() - getHypotheque());
			setEsthypothequee(1);
			cout << "Vous avez bien hypothequer votre Propriete" << endl;
		}
		else {}
	}
	else {}
}

void Propriete::vendre(Joueur Joueuractuel) {

}


void Propriete::arriverSur(Joueur Joueuractuel) {

}
