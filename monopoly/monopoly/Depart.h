#ifndef _DEPART_H_
#define _DEPART_H_

#include <iostream>
#include "case.h"
#include "joueur.h"

class Depart : public Case
{
public:
	Depart(std::string nom);
	
	/***
	* Donne 200 billets au joueur sans v�rifier si celui-ci est en d�but de partie et � fait un double.
	***/
	void arriverSur(Joueur& joueur);
};

#endif // !_DEPART_H_

