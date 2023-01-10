#ifndef _TAXE_H_
#define _TAXE_H_

#include "case.h"

class Taxe : public Case
{
public:
	Taxe(std::string nom, int taxe);

	void arriverSur(Joueur& j);

private:
	int prix;
};

#endif // !_TAXE_H_

