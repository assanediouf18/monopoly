#include "ListeCarte.h"

ListeCarte::ListeCarte(){
	}

Carte ListeCarte::tirer(){
	if (tete == NULL) {
		return;
	}

	if (tete == queue) {
		return tete->getCarteCourante();
	}

	NoeudListeCarte* anciennne_tete = tete;
	NoeudListeCarte* nouvelle_tete = anciennne_tete->getCarteSuivante();
	tete = nouvelle_tete;
	return anciennne_tete->getCarteCourante();
}

void ListeCarte::defausser(Carte carte){
	NoeudListeCarte n1 = NoeudListeCarte(carte);
	
	if (queue == NULL) {
		tete = &n1;
		queue = &n1;
	}

	queue->setCarteSuivante(&n1);
	queue = &n1;
}