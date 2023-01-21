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

	virtual std::string print();
	virtual void setProprietaire(Joueur* J1) { "Cette case ne peut pas avoir de proprietaire"; };
	virtual void construire(Joueur* Joueuractuel, Banque& bank) { "Il est impossible de construire sur cette case."; };
	virtual void vendre(Joueur* Joueuractuel, Banque& bank) { "Cette case n'est pas à vendre."; };
	virtual void hypothequer(Joueur* Joueuractuel, Banque& bank) { "Cette case ne peut pas être hypothequee."; };
	virtual void arriverSur(Joueur& joueur, Banque& bank)=0;

protected:
	std::string nom;
};

#endif // !CASE_H

