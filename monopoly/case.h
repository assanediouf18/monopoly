#ifndef CASE_H
#define CASE_H

#include <iostream>
#include "joueur.h"
#include "banque.h"

class Case
{
public:
	Case(std::string nom);

	std::string getNom() { return nom; };

	virtual void arriverSur(Joueur& joueur, Banque& bank)=0;

protected:
	std::string nom;
};

#endif // !CASE_H

