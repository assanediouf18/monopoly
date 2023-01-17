#ifndef _CHANCE_H_
#define _CHANCE_H_

#include "case.h"

class Chance : public Case
{
public:
	Chance(std::string nom = "Chance");

	virtual void arriverSur(Joueur& joueur, Banque& bank);
};

#endif
