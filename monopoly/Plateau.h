#ifndef PLATEAU_H
#define PLATEAU_H

#include <iostream>
#include "Terrain.h"
#include "Gare.h"
#include "case.h"
#include "Compagnie.h"
#include "Depart.h"
#include "Parc.h"
#include "Prison.h"
#include "Communaute.h"
#include "Taxe.h"
using namespace std;

const int NB_CASES = 0;

class Plateau {
public:
	Plateau();

    void deplacer(Joueur* j, int nbPas);
    //Je ne suis pas certain que la fonction case suivante soit utile sous cette forme
    //void caseSuivante(Case c);

private:
    Terrain lesTerrains[22];
    Taxe lesTaxes[2];
    //Chance* lesChances;
    Gare lesGares[4];
    Communaute* lesCommunautes;
    Prison* lesPrisons;
    Compagnie lesCompagnies[2];
    Parc leParc;
    Depart leDepart;
    Case* liste_cases[NB_CASES];
};

#endif
