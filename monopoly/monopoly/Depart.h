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
	* Donne 200 billets au joueur sans vérifier si celui-ci est en début de partie et à fait un double.
	***/
	void arriverSur(Joueur& joueur);
};

#endif // !_DEPART_H_

