#pragma once
#include "joueur.h"
#include "case.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Propriete : public Case{
protected:
	Joueur * Proprietaire;
	int achat;
	int hypotheque;
	int nb_case;
	bool estachetee;
	bool esthypothequee;
	string Nom;
public:
	Propriete(string Nom, int Prix, int nb_case);
	int getAchat() { return achat; };
	int getHypotheque() { return hypotheque; };
	int getNb_case() { return nb_case; };
	bool getEstachetee() { return estachetee; };
	bool getEsthypothequee() { return esthypothequee; };
	Joueur * getProprietaire() { return Proprietaire; };
	void setEsthypothequee(bool H) { esthypothequee = H; };
	void setEstachetee(bool A) { estachetee = A; };
	void setProprietaire(Joueur * J1) { Proprietaire = J1; };
	virtual void acheter(Joueur * Joueuractuel);
	void hypothequer(Joueur * Joueuractuel);
	virtual void arriverSur(Joueur& joueur);
	void vendre(Joueur Joueuractuel);
	/*** fonctions destinées à être virtuelles qd on les definira dans Compagnie Terrain et Gare ! ***/

};

