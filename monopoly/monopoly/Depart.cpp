#include "Depart.h"

Depart::Depart(std::string nom) : Case(nom)
{
}

void Depart::arriverSur(Joueur& joueur)
{
	joueur.changeSolde(200);
}
