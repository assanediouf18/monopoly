#ifndef _COMMUNAUTE_H_
#define _COMMUNAUTE_H_

#include <iostream>
#include "case.h"
#include "ListeCarte.h"

class Communaute : public Case
{
public:
	Communaute(std::string nom = "Communaute");

	/***
	* ATTENTION : il reste a donner la carte au joueur lorsque la classe ListeCarte sera prête !
	***/
	void arriverSur(Joueur& joueur, Banque& bank);

private:
	ListeCarte liste_carte_communaute;
};

#endif // !_COMMUNAUTE_H_

