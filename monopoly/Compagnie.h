#pragma once
#include <string>
using namespace std;

class Compagnie
{private :
	int idCase;
	string NomCompagnie;
	int Prix;

public:
	Compagnie(string Nom, int p, int idCase);
	void addCompagnie();
	void setAutreCompagnie(Compagnie*& C1, Compagnie*& C2);
};

