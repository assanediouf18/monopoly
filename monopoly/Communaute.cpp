#include "Communaute.h"

Communaute::Communaute(std::string nom) : Case(nom)
{
}

void Communaute::arriverSur(Joueur& joueur, Banque& bank)
{
	std::cout << joueur.getPseudo() << " pioche une carte communaut�." << std::endl;
	//Le joueur pioche une carte;
}
