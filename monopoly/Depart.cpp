#include "Depart.h"

Depart::Depart(std::string nom) : Case(nom)
{
}

void Depart::arriverSur(Joueur& joueur, Banque& bank)
{
	bank.payer(200, joueur);
}
