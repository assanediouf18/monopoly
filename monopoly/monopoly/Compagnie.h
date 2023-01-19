#pragma once
#include <string>
#include "Propriete.h"
using namespace std;

class Compagnie : public Propriete
{
private :
	Compagnie* AutreCompagnie;

public:
	Compagnie(string Nom = "Nom", int p = 0, int idCase = 0);
	virtual void arriverSur(Joueur* Joueuractuel);
	//void addCompagnie();
	void setAutreCompagnie(Compagnie * C1, Compagnie * C2);
	void setAutreCompagnie(Compagnie* C1);
};

