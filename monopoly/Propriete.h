#pragma once
#include "joueur.h"
#include "case.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Propriete : public Case{
private:
	Joueur Proprietaire;
	int achat;
	int hypotheque;
	int nb_case;
	int estachetee;
	int esthypothequee;
public:
	Propriete(string Nom, int Prix, int nb_case);
	int getAchat() { return achat; };
	int getHypotheque() { return hypotheque; };
	int getNb_case() { return nb_case; };
	int getEstachetee() { return estachetee; };
	int getEsthypothequee() { return esthypothequee; };
	void setEsthypothequee(int H) { esthypothequee = H; };
	void setEstachetee(int A) { estachetee = A; };
	void acheter(Joueur Joueuractuel);
	void hypothequer(Joueur Joueuractuel);
	void arriverSur(Joueur Joueuractuel);
	void vendre(Joueur Joueuractuel);
	/*** fonctions destinées à être virtuelles qd on les definira dans Compagnie Terrain et Gare ! ***/

};

