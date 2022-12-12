#include "joueur.h"

Joueur::Joueur()
{
	pseudo = "Pseudo basique";
	tpsPrison = 0;
	position = 0;
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

void Joueur::setSolde(int newSolde)
{
	solde = newSolde;
}

void Joueur::changeSolde(int montant)
{
	setSolde(solde + montant);
}
