#include <iostream>
#include "Chance.h"

Chance::Chance(std::string nom) : Case(nom)
{
}

void Chance::arriverSur(Joueur& joueur, Banque& bank)
{
	std::cout << "Bienvenue sur la case Chance" << std::endl;
	//Piocher une carte chance et agir en conséquence
}
