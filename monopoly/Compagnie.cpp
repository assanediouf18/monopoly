#include "Compagnie.h"
#include <string>
using namespace std;

Compagnie::Compagnie(string Nom, int p, int idCase):Propriete(Nom, p, idCase){
	AutreCompagnie = NULL;
}


void Compagnie::arriverSur(Joueur& j, Banque& bank) {
	int d1 = rand() % 6 + 1;
	int d2 = rand() % 6 + 1; // lancer des deux dés
	int loyer;
	Joueur* joueur = &j;
	Joueur Joueuractuel = *joueur;
	if (joueur == Proprietaire) {
		if (Joueuractuel == AutreCompagnie->getProprietaire()) {
			loyer = (d1 + d2) * 10;
			cout << "Vous etes debite de " << loyer << " euros, car vous etes proprietaire des deux compagnies !" << endl;
		}
		else {
			loyer = (d1 + d2) * 4; ;
			cout << "Vous etes debite de " << loyer << " euros" << endl;
		}
	}
	else {
		loyer = (d1 + d2) * 4; ;
		cout << "Vous etes debite de " << loyer << " euros" << endl;
	}
	Joueuractuel.setSolde(Joueuractuel.getSolde() - loyer);
	//bank.recevoir(loyer, Joueuractuel);
	cout << "Vous avez un solde de " << Joueuractuel.getSolde() << " euros" << endl;


}

void Compagnie::setAutreCompagnie(Compagnie * C1, Compagnie * C2) {
	C1->AutreCompagnie = C2;
	C2->AutreCompagnie = C1;
}

void Compagnie::setAutreCompagnie(Compagnie* C1) {
	AutreCompagnie = C1;
}