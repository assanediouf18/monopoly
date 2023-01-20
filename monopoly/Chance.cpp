#include <iostream>
#include "Chance.h"

Chance::Chance(std::string nom) : Case(nom)
{//cr�ation des cartes Chance
    liste_carte_chance.defausser(Carte(1, 0, 50, 0, 0, 0, -1, "La Banque vous verse une dividende de 50�."));
    liste_carte_chance.defausser(Carte(2, 0, -20, 0, 0, 0, -1, "Amende pour ivresse : 20�."));
    liste_carte_chance.defausser(Carte(3, 0, -15, 0, 0, 0, -1, "Amende pour exc�s de vitesse : 15�."));
    liste_carte_chance.defausser(Carte(4, 0, 100, 0, 0, 0, -1, "Vous avez gagn� le prix de mots crois�s. Recevez 100�."));
    liste_carte_chance.defausser(Carte(5, 0, -150, 0, 0, 0, -1, "Payez pour frais de scolarit� 150�."));
    liste_carte_chance.defausser(Carte(6, 0, 150, 0, 0, 0, -1, "Votre immeuble et votre pr�t rapportent. Vous devez toucher 150�."));
    liste_carte_chance.defausser(Carte(7, 0, 0, 0, 0, 0, 24, "Rendez-vous � l'Avenue Henri-Martin."));
    liste_carte_chance.defausser(Carte(8, 0, 0, 0, 0, 0, 30, "Allez en prison."));
    liste_carte_chance.defausser(Carte(9, 0, 0, 0, 0, 0, 0, "Avancez jusqu'� la case D�part."));
    liste_carte_chance.defausser(Carte(10, 0, 0, 0, 0, 0, 39, "Rendez-vous � la rue de la Paix."));
    liste_carte_chance.defausser(Carte(11, 0, 0, 0, 0, 0, 15, "Allez � la gare de Lyon."));
    liste_carte_chance.defausser(Carte(12, 0, 0, 0, 0, 0, 11, "Avancez au Boulevard de la Vilette."));
    //liste_carte_chance.defausser(Carte(13, 0, 0, 0, 1, 0, -1, "Faites des r�parations dans vos maisons. Versez pour chaque maison 25� et versez pour chaque h�tel 100�."));
    //liste_carte_chance.defausser(Carte(14, 0, 0, 0, 0, 1, -1, "Faites des r�parations dans vos maisons. Versez pour chaque maison 40� et versez pour chaque h�tel 115�."));
    liste_carte_chance.defausser(Carte(15, 1, 0, 0, 0, 0, -1, "Reculez de trois cases."));
    liste_carte_chance.defausser(Carte(16, 0, 0, 1, 0, 0, -1, "Vous �tes lib�r� de prison. Cette carte peut �tre conserv�e jusqu'� ce qu'elle soit utilis�e."));
}

void Chance::arriverSur(Joueur& joueur)
{
	std::cout << "Bienvenue sur la case Chance" << std::endl;
	Carte carteTiree = liste_carte_chance.tirer();
    std::cout << carteTiree.getConsigne() << std::endl;
    
    //Faire la fonction 'payer'

    if (carteTiree.getIdCasePlateau() >= 0) {
        joueur.setPosition(carteTiree.getIdCasePlateau());
    };

    if (carteTiree.getPrisonOuPas()) {
        joueur.addCarte(carteTiree, liste_carte_chance);
    };
}
