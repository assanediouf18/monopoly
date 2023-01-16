#pragma once
#include <iostream>
#include "Carte.h"
using namespace std;

class ListeCarte {
private:
	Carte* tas;
	Carte* defausse;
	string str;
	Carte liste_carte_chance[15];
	Carte liste_carte_communaute[13];


public:
	ListeCarte();
	void tirer();
	void melanger();
	void defausser(Carte* carte);


};