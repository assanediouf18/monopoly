#include "joueur.h"

Joueur::Joueur() : propertiesPos()
{
	pseudo = "Pseudo basique";
	tpsPrison = -1;
	position = 0;
	doubled = 0;
	solde = 0;
	isPlaying = true;
	nbCartePrison = 0;
	mode = "Manuel";
}

int Joueur::getSolde()
{
	isPlaying = !(solde < 0 && (propertiesPos.size() == 0));
	return solde;
}

bool Joueur::isStillPlaying()
{
	return isPlaying;
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
	tpsPrison = newTps;
}

void Joueur::setSolde(int newSolde)
{
	solde = newSolde;
	if (solde < 0)
	{
		if (propertiesPos.size() <= 0)
		{
			cout << pseudo << " est en faillite !" << endl;
			isPlaying = false;
		}
		else {
			cout << "Attention " << pseudo << ", ton solde est negatif." << endl;
			cout << "Hypotheque ou vend pour rester dans la partie !" << endl;
		}
	}
}

void Joueur::changeSolde(int montant)
{
	setSolde(solde + montant);
}

void Joueur::addProperty(int boughtPtyPos)
{
	propertiesPos.push_back(boughtPtyPos);
}

void Joueur::removeProperty(int removePtyPos)
{
	int lastIndex = propertiesPos.size() - 1;
	int item = propertiesPos[0];
	int removeItemIndex = 0;
	while (removeItemIndex < lastIndex && item != removePtyPos)
	{
		removeItemIndex++;
		item = propertiesPos[removeItemIndex];
	}
	if (item != removePtyPos) return;
	propertiesPos[removeItemIndex] = propertiesPos[lastIndex];
	propertiesPos.pop_back();
}

bool Joueur::operator ==(Joueur * J2) {
	return (pseudo == J2->getPseudo()) && (solde == J2->solde);
}

std::ostream& operator<<(std::ostream& out, Joueur& j)
{
	out << "Nom du joueur : " << j.getPseudo() << std::endl;
	out << "Solde : " << j.getSolde() << " M";
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

void Joueur::addCarte(Carte* carte, ListeCarte* listeCarte) {
	if (nbCartePrison < 2) {
		cartesPrison[nbCartePrison] = carte;
		listeOrigine[nbCartePrison] = listeCarte;
		nbCartePrison++;
	};
}

void Joueur::utiliserCarte() {
	if (nbCartePrison > 0) {
		listeOrigine[nbCartePrison - 1]->defausser(cartesPrison[nbCartePrison - 1]);
		nbCartePrison--;
	};
}

//ajout Samy

void Joueur::setMode(std::string newMode)
{
	mode = newMode;
}