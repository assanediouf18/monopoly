#ifndef _COMMUNAUTE_H_
#define _COMMUNAUTE_H_

#include <iostream>
#include "case.h"

class Communaute : public Case
{
public:
	Communaute(std::string nom = "Communaute");

	/***
	* ATTENTION : il reste a donner la carte au joueur lorsque la classe ListeCarte sera prête !
	***/
	void arriverSur(Joueur& joueur, Banque& bank);
};

#endif // !_COMMUNAUTE_H_

