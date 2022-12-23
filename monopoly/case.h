#ifndef CASE_H
#define CASE_H

#include <iostream>
#include "joueur.h"

class Case
{
public:
	Case(std::string nom);

	std::string getNom() { return nom; };

	void getSuivant(Joueur& joueur);

private:
	std::string nom;
};

#endif // !CASE_H

