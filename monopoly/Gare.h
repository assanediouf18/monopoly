#pragma once
#include <string>
#include "Propriete.h"
#include "joueur.h"
using namespace std;

class Gare : public Propriete
{
private:
	Gare* autres_gares[3];

public:
	Gare(string Nom, int prix, int idCase);
	virtual void acheter(Joueur Joueuractuel);
	virtual void arriverSur(Joueur *joueur);
	void setAutresGares(Gare* G1, Gare* G2, Gare* G3);

	
};

