#ifndef _DEPART_H_
#define _DEPART_H_

#include <iostream>
#include "case.h"
#include "joueur.h"

class Depart : public Case
{
public:
	void getSuivant(Joueur& joueur);
};

#endif // !_DEPART_H_

