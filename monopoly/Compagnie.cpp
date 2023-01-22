#include "Compagnie.h"
#include <string>
using namespace std;

Compagnie::Compagnie(string Nom, int p, int idCase):Propriete(Nom, p, idCase){
	AutreCompagnie = NULL;
}


void Compagnie::arriverSur(Joueur& j, Banque& bank) {
	Propriete::arriverSur(j, bank);
	int d1 = rand() % 6 + 1;
	int d2 = rand() % 6 + 1; // lancer des deux dés
	int loyer = 0;
	Joueur* joueur = &j;
	Joueur Joueuractuel = *joueur;
	if (estachetee) {
		if (joueur != Proprietaire) {
			cout << "Vous rejetez les dés pour déterminer le loyer : " << endl;
			std::cout << "De 1 : " << d1 << " ; de 2 : " << d2 << endl;
			if (AutreCompagnie->getProprietaire() == NULL)
			{
				loyer = (d1 + d2) * 4; ;
				cout << "Vous etes debite de " << loyer << " euros" << endl;
			}
			else if (Proprietaire == AutreCompagnie->getProprietaire()) {
				loyer = (d1 + d2) * 10;
				cout << "Vous etes debite de " << loyer << " euros" << endl;
			}
			else {
				loyer = (d1 + d2) * 4; ;
				cout << "Vous etes debite de " << loyer << " euros" << endl;
			}
		}/*
		else {
			loyer = (d1 + d2) * 4; ;
			cout << "Vous etes debite de " << loyer << " euros" << endl;
		}*/
		//Joueuractuel.setSolde(Joueuractuel.getSolde() - loyer);
		bank.recevoir(loyer, Joueuractuel);
		cout << "Vous avez un solde de " << Joueuractuel.getSolde() << " euros" << endl;
	}
	else {
		acheter(&j, bank);
	}


}

void Compagnie::setAutreCompagnie(Compagnie * C1, Compagnie * C2) {
	C1->AutreCompagnie = C2;
	C2->AutreCompagnie = C1;
}

void Compagnie::setAutreCompagnie(Compagnie* C1) {
	AutreCompagnie = C1;
}