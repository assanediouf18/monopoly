#pragma once
#include <iostream>
#include "Carte.h"
using namespace std;

class NoeudListeCarte{
private :
	Carte carte_courante;
	NoeudListeCarte* carte_suivante = NULL;

public :
	NoeudListeCarte(Carte);

	Carte getCarteCourante() {
		return carte_courante;
	};

	NoeudListeCarte* getCarteSuivante() {
		return carte_suivante;
	};

	void setCarteSuivante(NoeudListeCarte* n) {
		carte_suivante = n;
	};
};

