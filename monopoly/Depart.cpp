#include "Depart.h"

void Depart::getSuivant(Joueur& joueur)
{
	joueur.changeSolde(200);
	joueur.move(1);
}
