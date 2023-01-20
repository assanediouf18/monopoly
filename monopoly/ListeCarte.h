#pragma once
#include <iostream>
#include "Carte.h"
#include "NoeudListeCarte.h"
using namespace std;

class ListeCarte{
private:
	NoeudListeCarte* tete = NULL;
	NoeudListeCarte* queue = NULL;

public:
	ListeCarte();
	Carte* tirer();
	void defausser(Carte*);
};