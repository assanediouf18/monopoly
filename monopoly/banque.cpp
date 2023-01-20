#include "banque.h"

Banque::Banque() : solde(10000) {
}

void Banque::payer(int montant, Joueur& joueur) {
    solde += montant;
    joueur.changeSolde(montant);
}

void Banque::recevoir(int montant, Joueur& joueur) {
    solde -= montant;
    joueur.changeSolde(montant);
}