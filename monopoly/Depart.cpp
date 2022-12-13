#include "Depart.h"

Depart::Depart(std::string nom) : Case(nom)
{
}

void Depart::getSuivant(Joueur& joueur)
{
	joueur.changeSolde(200);
}
