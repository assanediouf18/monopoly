#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>

/***
* Classe Joueur
* Contient toutes les infos nécessaires à un joueur et reste actuellement à compléter
***/
class Joueur
{
public:
	Joueur();

	std::string getPseudo() { return pseudo; };
	int getTempsPrison() { return tpsPrison; };
	int getPosition() { return position; };
	int getSolde() { return solde; };
	bool isStillPlaying() { return isPlaying; };

	/***
	* ATTENTION : Ajouter de quoi vérifier que le joueur ne sort pas du plateau (dans plateau par exemple)
	* Défini la nouvelle position du joueur
	***/
	void setPosition(int newPos);
	/***
	* Déplace le joueur de nbPas par rapport à sa position actuelle.
	* nbPas peut être négatif
	***/
	void move(int nbPas);

	/***
	* Modifie le solde du joueur;
	***/
	void setSolde(int newSolde);
	/***
	* Change le solde du joueur d'un montant montant par rapport à son solde actuel.
	* Montant peut être négatif.
	***/
	void changeSolde(int montant);


private:
	std::string pseudo;
	int tpsPrison;
	int position;
	int solde;
	bool isPlaying;
};

#endif
