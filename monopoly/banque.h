

#include "joueur.h"
using namespace std;

class Banque {
public:
    Banque() {
        solde = 100000; // initialiser l'argent de la banque
    }

    int get_Solde() {
        return solde;
    }

    void payer(int montant, Joueur& joueur) {
        argent_ -= montant;
        joueur.changeSolde(montant);
    }

    void recevoir(int montant, Joueur& joueur) {
        argent_ += montant;
        joueur.changeSolde(montant);
    }

private:
    int solde;
};

