#ifndef CASE_H
#define CASE_H

#include <iostream>
#include "joueur.h"

class Case
{
public:
	Case(std::string nom);

	std::string getNom() { return nom; };

	virtual void arriverSur(Joueur& joueur)=0;

protected:
	std::string nom;
};

#endif // !CASE_H

