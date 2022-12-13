#include "joueur.h"

Joueur::Joueur()
{
	pseudo = "Pseudo basique";
	tpsPrison = 0;
	position = 0;
	doubled = 0;
	isPlaying = true;
}

void Joueur::setPosition(int newPos)
{
	position = newPos;
}

void Joueur::move(int nbPas)
{
	setPosition(position + nbPas);
}

void Joueur::has_a_double(int howMany)
{
	doubled += howMany;
}

void Joueur::resetDoubles()
{
	doubled = 0;
}

void Joueur::setTempsPrison(int newTps)
{
	if (newTps < 0) newTps = 0;
	tpsPrison = newTps;
}

void Joueur::setSolde(int newSolde)
{
	solde = newSolde;
}

void Joueur::changeSolde(int montant)
{
	setSolde(solde + montant);
}
