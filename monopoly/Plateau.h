#ifndef PLATEAU_H
#define PLATEAU_H

#include <iostream>
#include <fstream>
#include <string>
#include "Terrain.h"
#include "Gare.h"
#include "case.h"
#include "Compagnie.h"
#include "Depart.h"
#include "Parc.h"
#include "Prison.h"
#include "Communaute.h"
#include "Chance.h"
#include "banque.h"
#include "Taxe.h"
#include "ListeCarte.h"
using namespace std;

const int NB_CASES = 40;

class Plateau {
public:
	Plateau();

    void deplacer(Joueur* j, int nbPas, Banque& bank);
    void save(std::ofstream& saveFile);
    void load(std::ifstream& loadFile);
    void recupProprietes(std::vector<int> ptes);

    Case* operator[](int index);

    static const int prisonLocation = 10;


private:
    Terrain lesTerrains[22];
    Taxe lesTaxes[2];
    Chance case_chance;
    Gare lesGares[4];
    Communaute case_communaute;
    Prison lesPrisons[2];
    Compagnie lesCompagnies[2];
    Parc leParc;
    Depart leDepart;
    Case* liste_cases[NB_CASES];
};

#endif
