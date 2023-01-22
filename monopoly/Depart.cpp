#include "Depart.h"

Depart::Depart(std::string nom) : Case(nom)
{
}

void Depart::arriverSur(Joueur& joueur, Banque& bank)
{
	cout << "Bienvenue sur la case depart, recevez 200 de la banque !" << endl;
	bank.payer(200, joueur);
}
