#pragma once
#include <string>
#include "Propriete.h"
using namespace std;

class Gare : protected Propriete
{
private:
	string Nom;
	int achat;
	int nb_case;

public:
	Gare(string Nom, int prix, int idCase);
	
};

