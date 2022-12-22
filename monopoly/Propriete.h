#pragma once
#include "joueur.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Propriete {
private:
	Joueur Proprietaire;
	int achat;
	int loyer[6];
	int hypotheque;
	string id;
	int tailleGp;
	Propriete groupe[int tailleGp];
public:
	Propriete();
	virtual void hypothequer();
	virtual void arriverSur();
	virtual void vendre();
	virtual void acheter();

};

