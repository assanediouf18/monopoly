#include "joueur.h"

Joueur::Joueur()
{
	pseudo = "Pseudo basique";
	tpsPrison = -1;
	position = 0;
	doubled = 0;
	solde = 0;
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

bool Joueur::operator ==(Joueur * J2) {
	return (pseudo == J2->getPseudo());
}

std::ostream& operator<<(std::ostream& out, Joueur& j)
{
	out << "Nom du joueur : " << j.getPseudo() << std::endl;
	out << "Solde : " << j.getSolde() << " M" << std::endl;
	out << "Position : " << j.getPosition();
	return out;
}

std::istream& operator>>(std::istream& in, Joueur& j)
{
	std::string pseudo;
	std::cout << "Hello ! Nouveau joueur quel est ton pseudo ? ";
	in >> pseudo;
	j.pseudo = pseudo;
	std::cout << "Okay bon courage " << pseudo << " !";
	return in;
}
