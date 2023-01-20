#include "Taxe.h"

Taxe::Taxe(std::string nom, int taxe) : Case(nom)
{
	prix = taxe;
}

void Taxe::arriverSur(Joueur& j, Banque& bank)
{
	std::cout << j.getPseudo() << " paie une taxe de " << prix << " billets à la banque." << std::endl;
	bank.recevoir(prix, j);
}
