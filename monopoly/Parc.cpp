#include "Parc.h"

Parc::Parc(std::string nom) : Case(nom)
{
}

void Parc::arriverSur(Joueur& j, Banque& bank)
{
	std::cout << "Bienvenue au parc " << j.getPseudo() << ". Reposes toi bien." << std::endl;
}
