#ifndef _PRISON_H_
#define _PRISON_H_

#include "case.h"
#include "joueur.h"

class Prison : public Case
{
public:
	Prison(std::string name = "Prison");

	void arriverSur(Joueur& joueur);
};

#endif // !_PRISON_H_

