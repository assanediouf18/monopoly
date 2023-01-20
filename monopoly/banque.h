#ifndef _BANQUE_H__
#define _BANQUE_H__

#include "joueur.h"
using namespace std;

class Banque {
public:
    Banque();

    int get_Solde() { return solde; }

    /***
    * Cette m�thode est d�finie par rapport � la banque
    * La banque va donc verser montant � joueur.
    ***/
    void payer(int montant, Joueur& joueur);

    /***
    * Cette m�thode est d�finie par rapport � la banque
    * La banque va donc pr�lever montant � joueur.
    ***/
    void recevoir(int montant, Joueur& joueur);

private:
    int solde;
};

#endif;