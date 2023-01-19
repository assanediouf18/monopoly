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

void Propriete::acheter(Joueur * Joueuractuel){
	if (Joueuractuel->getMode() == "Manuel"){
		std::string avisJoueur;
		cout << "Cette propriete n'a pas de proprietaire, voulez-vous l'acheter pour " << achat<< " euros ? Repondez soit 'Oui' soit 'Non'" << endl;
		cin >> avisJoueur;
		if (avisJoueur == "Oui") {
				Proprietaire = Joueuractuel;
				Joueuractuel->setSolde(Joueuractuel->getSolde() - getAchat());
				setEstachetee(true);
				cout << "Vous etes le nouveau proprietaire, felicitations ! " << endl;
		}
	}
	if (Joueuractuel->getMode() == "Aléatoire"){
		string avisJoueur;
		avisJoueur = (rand() % 2) == 0 ? "Non" : "Oui";
		if (avisJoueur == "Oui") {
			cout << "Le joueur "<< Joueuractuel->getPseudo()<<" essaie d'acheter la propriété " << endl;
			Proprietaire = Joueuractuel;
			Joueuractuel->setSolde(Joueuractuel->getSolde() - getAchat());
			setEstachetee(true);
			cout << "Vous etes le nouveau proprietaire, felicitations ! " << endl;
		}
	}
	if (Joueuractuel->getMode() == "Automatique"){
		cout << "Le joueur "<< Joueuractuel->getPseudo()<<" essaie d'acheter la propriété " << endl;
		Proprietaire = Joueuractuel;
		Joueuractuel->setSolde(Joueuractuel->getSolde() - getAchat());
		setEstachetee(true);
		cout << "Vous etes le nouveau proprietaire, felicitations ! " << endl;
	}
}



void Propriete::hypothequer(Joueur * Joueuractuel){
	if (getEstachetee()) {
		std::string avisJoueur;
		cout << "Voulez-vous hypothequer votre bien? R�pondez 'Oui' si vous le voulez. (avec la majuscule !)" << endl;
		cin >> avisJoueur;
		if (avisJoueur == "Oui") {
			Joueuractuel->setSolde(Joueuractuel->getSolde() - getHypotheque());
			setEsthypothequee(true);
			cout << "Vous avez bien hypothequer votre Propriete" << endl;
		}
		else {}
	}
	else {}
}

void Propriete::arriverSur(Joueur& joueur)
{
	std::cout << "Bienvenue sur la propriete " << this->getNom() << std::endl;
}

void Propriete::vendre(Joueur Joueuractuel) {

}



