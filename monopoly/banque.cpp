#include "banque.h"

Banque::Banque() : solde(10000) {
}

void Banque::payer(int montant, Joueur& joueur) {
    if (montant > solde)
    {
        cout << "La banque n'a pas assez pour vous verser " << montant << " M..." << endl;
        montant = solde;
        cout << "Vous recevez donc " << solde << " M." << endl;
    }
    solde -= montant;
    joueur.changeSolde(montant);
}

void Banque::recevoir(int montant, Joueur& joueur) {
    solde += montant;
    joueur.changeSolde(-montant);
}