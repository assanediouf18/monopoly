#pragma once
#include <string>
#include "Propriete.h"
using namespace std;

class Compagnie : public Propriete
{private :
	int nb_case;
	string nom;
	int achat;

public:
	Compagnie(string Nom, int p, int idCase);
	/**void addCompagnie();
	void setAutreCompagnie(Compagnie*& C1, Compagnie*& C2);**/
};

