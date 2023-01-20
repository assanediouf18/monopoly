#ifndef _BANQUE_H__
#define _BANQUE_H__

#include "joueur.h"
using namespace std;

class Banque {
public:
    Banque();

    int get_Solde() { return solde; }

    /***
    * Cette méthode est définie par rapport à la banque
    * La banque va donc verser montant à joueur.
    ***/
    void payer(int montant, Joueur& joueur);

    /***
    * Cette méthode est définie par rapport à la banque
    * La banque va donc prélever montant à joueur.
    ***/
    void recevoir(int montant, Joueur& joueur);

private:
    int solde;
};

#endif;