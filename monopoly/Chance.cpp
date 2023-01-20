#include <iostream>
#include "Chance.h"

Chance::Chance(std::string nom) : Case(nom)
{//création des cartes Chance
    liste_carte_chance.defausser(Carte(1, 0, 50, 0, 0, 0, -1, "La Banque vous verse une dividende de 50€."));
    liste_carte_chance.defausser(Carte(2, 0, -20, 0, 0, 0, -1, "Amende pour ivresse : 20€."));
    liste_carte_chance.defausser(Carte(3, 0, -15, 0, 0, 0, -1, "Amende pour excès de vitesse : 15€."));
    liste_carte_chance.defausser(Carte(4, 0, 100, 0, 0, 0, -1, "Vous avez gagné le prix de mots croisés. Recevez 100€."));
    liste_carte_chance.defausser(Carte(5, 0, -150, 0, 0, 0, -1, "Payez pour frais de scolarité 150€."));
    liste_carte_chance.defausser(Carte(6, 0, 150, 0, 0, 0, -1, "Votre immeuble et votre prêt rapportent. Vous devez toucher 150€."));
    liste_carte_chance.defausser(Carte(7, 0, 0, 0, 0, 0, 24, "Rendez-vous à l'Avenue Henri-Martin."));
    liste_carte_chance.defausser(Carte(8, 0, 0, 0, 0, 0, 30, "Allez en prison."));
    liste_carte_chance.defausser(Carte(9, 0, 0, 0, 0, 0, 0, "Avancez jusqu'à la case Départ."));
    liste_carte_chance.defausser(Carte(10, 0, 0, 0, 0, 0, 39, "Rendez-vous à la rue de la Paix."));
    liste_carte_chance.defausser(Carte(11, 0, 0, 0, 0, 0, 15, "Allez à la gare de Lyon."));
    liste_carte_chance.defausser(Carte(12, 0, 0, 0, 0, 0, 11, "Avancez au Boulevard de la Vilette."));
    //liste_carte_chance.defausser(Carte(13, 0, 0, 0, 1, 0, -1, "Faites des réparations dans vos maisons. Versez pour chaque maison 25€ et versez pour chaque hôtel 100€."));
    //liste_carte_chance.defausser(Carte(14, 0, 0, 0, 0, 1, -1, "Faites des réparations dans vos maisons. Versez pour chaque maison 40€ et versez pour chaque hôtel 115€."));
    liste_carte_chance.defausser(Carte(15, 1, 0, 0, 0, 0, -1, "Reculez de trois cases."));
    liste_carte_chance.defausser(Carte(16, 0, 0, 1, 0, 0, -1, "Vous êtes libéré de prison. Cette carte peut être conservée jusqu'à ce qu'elle soit utilisée."));
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
