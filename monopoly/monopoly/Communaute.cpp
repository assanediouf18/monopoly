#include "Communaute.h"

Communaute::Communaute(std::string nom) : Case(nom)
{
}

void Communaute::arriverSur(Joueur& joueur)
{
	std::cout << joueur.getPseudo() << " pioche une carte communauté." << std::endl;
	//Le joueur pioche une carte;
}
