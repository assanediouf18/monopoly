#ifndef _CHANCE_H_
#define _CHANCE_H_

#include "case.h"
#include "ListeCarte.h"

class Chance : public Case
{
public:
	Chance(std::string nom = "Chance");

	virtual void arriverSur(Joueur& joueur);

private:
	ListeCarte liste_carte_chance;
};

#endif
