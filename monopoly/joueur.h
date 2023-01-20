#ifndef _JOUEUR_H
#define _JOUEUR_H

#include <iostream>
#include "ListeCarte.h"
#include "Carte.h"
#include <vector>

/***
* Classe Joueur
* Contient toutes les infos nécessaires à un joueur et reste actuellement à compléter
* PENSER A METTRE A JOUR LE DIAGRAMME UML ET A COMPLETER LA CLASSE !
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
	* Retourne combien de fois le joueur a fait un double
	***/
	int howManyDoubles() { return doubled; };
	std::vector<int> getProprietes() { return propertiesPos; };

	/***
	* ATTENTION : Ajouter de quoi vérifier que le joueur ne sort pas du plateau (dans plateau par exemple)
	* Défini la nouvelle position du joueur
	***/
	void setPosition(int newPos);
	void setPseudo(std::string newPseudo) { pseudo = newPseudo; };
	/***
	* Déplace le joueur de nbPas par rapport à sa position actuelle.
	* nbPas peut être négatif
	***/
	void move(int nbPas);
	/***
	* Modifie le nombre de doubles que le joueur a fait.
	* howMany est optionnel et spécifie combien de nouveaux doubles le joueur a fait
	***/
	void has_a_double(int howMany = 1);
	/***
	* Remet à zéro le nombre de doubles du joueur.
	***/
	void resetDoubles();

	void setTempsPrison(int newTps);

	/***
	* Modifie le solde du joueur;
	***/
	void setSolde(int newSolde);
	/***
	* Change le solde du joueur d'un montant montant par rapport à son solde actuel.
	* Montant peut être négatif.
	***/
	void changeSolde(int montant);
	void setMesGares(int g) { int mesGares = g; };
	int getMesGares() { return mesGares; };
	void addProperty(int boughtPtyPos);
	void removeProperty(int removePtyPos);
	
	bool operator==(Joueur * J2);

	friend std::ostream& operator<<(std::ostream& out, Joueur& v);
	friend std::istream& operator>>(std::istream& out, Joueur& v);

	void addCarte(Carte*, ListeCarte*);
	void utiliserCarte();

	void setMode(std::string);
	std::string getMode() { return mode; };


private:
	std::string pseudo;
	int tpsPrison;
	int position;
	int solde;
	bool isPlaying;
	int doubled; //Combien de fois le joueur a fait un double ?
	int mesGares;
	std::vector<int> propertiesPos;
	int nbCartePrison;
	ListeCarte* listeOrigine[2];
	Carte* cartesPrison[2];
	std::string mode;
};

#endif
