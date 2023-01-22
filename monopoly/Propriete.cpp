#include "Propriete.h"
#include "joueur.h"
#include "case.h"
using namespace std;

std::string Propriete::choixAchat(Joueur* player)
{
	std::string avisJoueur;
	if (player->getMode() == "Manuel") {
		std::cin >> avisJoueur;
	}
	else if (player->getMode() == "Aleatoire") {
		avisJoueur = (rand() % 2) == 0 ? "Non" : "Oui";
	}
	else if (player->getMode() == "Automatique") {
		avisJoueur = "Oui";
	}
	return avisJoueur;
}

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
	avisJoueur = choixAchat(Joueuractuel);
	if (avisJoueur == "Oui") {
			setProprietaire(Joueuractuel);
			bank.recevoir(getAchat(), *Joueuractuel);
			setEstachetee(true);
			cout << "Vous etes le nouveau proprietaire, felicitations ! " << endl;
			cout << Joueuractuel->getPseudo() << " a desormais un solde de " << Joueuractuel->getSolde() << endl;
	}
	else {
		std::cout << Joueuractuel->getPseudo() << " n'achete pas." << endl;
	}
}


void Propriete::hypothequer(Joueur * Joueuractuel, Banque& bank){
	if (getEstachetee()) {
		std::string avisJoueur;
		cout << "Voulez-vous hypothequer votre bien? Répondez 'Oui' si vous le voulez. (avec la majuscule !)" << endl;
		avisJoueur = choixAchat(Joueuractuel);
		if (avisJoueur == "Oui") {
			bank.payer(getHypotheque(), *Joueuractuel);
			setEsthypothequee(true);
			cout << "Vous avez bien hypothequer votre Propriete" << endl;
		}
	}
}

void Propriete::arriverSur(Joueur& joueur, Banque& bank)
{
	std::cout << "Bienvenue sur la propriete " << this->getNom() << std::endl;
}

void Propriete::vendre(Joueur* Joueuractuel, Banque& bank) {
	if (getEstachetee()) {
		std::string avisJoueur;
		cout << "Voulez-vous vendre votre bien pour "<< getAchat() / 2 << " ? Répondez 'Oui' si vous le voulez. (avec la majuscule !)" << endl;
		avisJoueur = choixAchat(Joueuractuel);
		if (avisJoueur == "Oui") {
			setEstachetee(false);
			Proprietaire = NULL;
			Joueuractuel->removeProperty(nb_case);
			cout << "Vous avez bien vendu votre propriete" << endl;
			bank.payer(getAchat() / 2, *Joueuractuel);
		}
	}
}

void Propriete::setProprietaire(Joueur* J1)
{
	if (Proprietaire != NULL)
	{
		cout << "Le propriétaire est deja " << Proprietaire->getPseudo() << endl;
		return;
	}
	Proprietaire = J1;
	setEstachetee(true);
	J1->addProperty(nb_case);
}


