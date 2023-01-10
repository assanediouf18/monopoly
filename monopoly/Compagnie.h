#pragma once
#include <string>
#include "Propriete.h"
using namespace std;

class Compagnie : public Propriete
{private :
	int nb_case;
	string nom;
	int achat;
	Compagnie* AutreCompagnie;

public:
	Compagnie(string Nom, int p, int idCase);
	virtual void arriverSur(Joueur* Joueuractuel);
	//void addCompagnie();
	void setAutreCompagnie(Compagnie * C1, Compagnie * C2);
	void setAutreCompagnie(Compagnie* C1);
};

