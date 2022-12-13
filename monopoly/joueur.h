#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>

/***
* Classe Joueur
* Contient toutes les infos n�cessaires � un joueur et reste actuellement � compl�ter
* PENSER A METTRE A JOUR LE DIAGRAMME UML
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
	/***
	* Le dernier score du joueur au lanc� de d�
	***/
	int getLastRollScore() { return lastRoll; };

	/***
	* ATTENTION : Ajouter de quoi v�rifier que le joueur ne sort pas du plateau (dans plateau par exemple)
	* D�fini la nouvelle position du joueur
	***/
	void setPosition(int newPos);
	/***
	* D�place le joueur de nbPas par rapport � sa position actuelle.
	* nbPas peut �tre n�gatif
	***/
	void move(int nbPas);
	/***
	* Modifie le nombre de doubles que le joueur a fait.
	* howMany est optionnel et sp�cifie combien de nouveaux doubles le joueur a fait
	***/
	void has_a_double(int howMany = 1);
	/***
	* Remet � z�ro le nombre de doubles du joueur.
	***/
	void resetDoubles();
	/***
	* Met � jour le dernier score du joueur au lanc� de d�
	***/
	void setNewRollScore(int newScore);

	void setTempsPrison(int newTps);

	/***
	* Modifie le solde du joueur;
	***/
	void setSolde(int newSolde);
	/***
	* Change le solde du joueur d'un montant montant par rapport � son solde actuel.
	* Montant peut �tre n�gatif.
	***/
	void changeSolde(int montant);


private:
	std::string pseudo;
	int tpsPrison;
	int position;
	int solde;
	bool isPlaying;
	int lastRoll; //dernier score obtenu en lan�ant les d�s
	int doubled; //Combien de fois le joueur a fait un double
};

#endif
