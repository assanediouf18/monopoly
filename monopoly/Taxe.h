#ifndef _TAXE_H_
#define _TAXE_H_

#include "case.h"

class Taxe : public Case
{
public:
	Taxe(std::string nom = "Taxe", int taxe = 0);

	void arriverSur(Joueur& j, Banque& bank);

private:
	int prix;
};

#endif // !_TAXE_H_

