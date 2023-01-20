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
#include "Chance.h"
#include "Taxe.h"
#include "ListeCarte.h"
using namespace std;

const int NB_CASES = 40;

class Plateau {
public:
	Plateau();

    void deplacer(Joueur* j, int nbPas);
    //Je ne suis pas certain que la fonction case suivante soit utile sous cette forme
    //void caseSuivante(Case c);

    //Ajouter une exception si index n'est pas dans les limites
    Case* operator[](int index);

    static const int prisonLocation = 10;


private:
    Terrain lesTerrains[22];
    Taxe lesTaxes[2];
    Chance Case_chance;
    Gare lesGares[4];
    Communaute Case_communaute;
    Prison lesPrisons[2];
    Compagnie lesCompagnies[2];
    Parc leParc;
    Depart leDepart;
    Case* liste_cases[NB_CASES];
};

#endif
