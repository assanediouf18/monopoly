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

class Plateau {
public:
	Plateau();

private:
    Terrain lesTerrains[22];
    Taxe* lesTaxes;
    //Chance* lesChances;
    Gare lesGares[4];
    Communaute* lesCommunautes;
    Prison* lesPrisons;
    Compagnie lesCompagnies[2];
    Parc leParc;
    Depart leDepart;
    Case* liste_cases[40];
};

#endif
