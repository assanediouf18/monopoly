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
	Gare(string nom = "Nom", int prix = 0, int idCase = 0);
	virtual void acheter(Joueur * Joueuractuel);
	virtual void arriverSur(Joueur *joueur);
	void setAutreGares(Gare* G1, Gare* G2, Gare* G3);
	void setAutreGares(Gare* moi, Gare* G1, Gare* G2, Gare* G3);

	
};

