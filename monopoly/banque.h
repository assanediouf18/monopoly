#ifndef _BANQUE_H__
#define _BANQUE_H__

#include "joueur.h"
using namespace std;

class Banque {
public:
    Banque();

    int get_Solde() { return solde; }

    void payer(int montant, Joueur& joueur);

    void recevoir(int montant, Joueur& joueur);

private:
    int solde;
};

#endif;