#ifndef _PARC_H_
#define _PARC_H_

#include "case.h"

class Parc : public Case
{
public:
	Parc(std::string name);

	void arriverSur(Joueur& j);
};

#endif
