#include "Propriete.h"
#include "joueur.h"
#include "case.h"
using namespace std;

Propriete::Propriete(string Nom, int Prix, int num_case):Case(Nom) {
	achat=Prix;
	hypotheque = achat / 2;
	nb_case = num_case;
	estachetee = false;
	esthypothequee = false;
	Proprietaire = NULL;
}

void Propriete::acheter(Joueur * Joueuractuel, Banque& bank){
	std::string avisJoueur;
	cout << "Cette propriete n'a pas de proprietaire, voulez-vous l'acheter pour " << achat<< " euros ? Repondez soit 'Oui' soit 'Non'" << endl;
	cin >> avisJoueur;
	if (avisJoueur == "Oui") {
			Proprietaire = Joueuractuel;
			bank.recevoir(getAchat(), *Joueuractuel);
			setEstachetee(true);
			cout << "Vous etes le nouveau proprietaire, felicitations ! " << endl;
			cout << Joueuractuel->getPseudo() << " a désormais un solde de " << Joueuractuel->getSolde() << endl;
	}
}


void Propriete::hypothequer(Joueur * Joueuractuel, Banque& bank){
	if (getEstachetee()) {
		std::string avisJoueur;
		cout << "Voulez-vous hypothequer votre bien? Répondez 'Oui' si vous le voulez. (avec la majuscule !)" << endl;
		cin >> avisJoueur;
		if (avisJoueur == "Oui") {
			bank.recevoir(getHypotheque(), *Joueuractuel);
			setEsthypothequee(true);
			cout << "Vous avez bien hypothequer votre Propriete" << endl;
		}
	}
}

void Propriete::arriverSur(Joueur& joueur, Banque& bank)
{
	std::cout << "Bienvenue sur la propriete " << this->getNom() << std::endl;
}

void Propriete::vendre(Joueur Joueuractuel) {

}



