#include <iostream>
#include "Chance.h"

Chance::Chance(std::string nom) : Case(nom)
{//création des cartes Chance
    Carte* carte1 = new Carte(1, 0, 50, 0, 0, 0, -1, "La Banque vous verse une dividende de 50 euros.");
    liste_carte_chance.defausser(carte1);
    Carte* carte2 = new Carte(2, 0, -20, 0, 0, 0, -1, "Amende pour ivresse : 20 euros.");
    liste_carte_chance.defausser(carte2);
    Carte* carte3 = new Carte(3, 0, -15, 0, 0, 0, -1, "Amende pour exces de vitesse : 15 euros.");
    liste_carte_chance.defausser(carte3);
    Carte* carte4 = new Carte(4, 0, 100, 0, 0, 0, -1, "Vous avez gagne le prix de mots croises. Recevez 100 euros.");
    liste_carte_chance.defausser(carte4);
    Carte* carte5 = new Carte(5, 0, -150, 0, 0, 0, -1, "Payez pour frais de scolarite 150 euros.");
    liste_carte_chance.defausser(carte5);
    Carte* carte6 = new Carte(6, 0, 150, 0, 0, 0, -1, "Votre immeuble et votre pret rapportent. Vous devez toucher 150 euros.");
    liste_carte_chance.defausser(carte6);
    Carte* carte7 = new Carte(7, 0, 0, 0, 0, 0, 24, "Rendez-vous a l'Avenue Henri-Martin.");
    liste_carte_chance.defausser(carte7);
    Carte* carte8 = new Carte(8, 0, 0, 0, 0, 0, 30, "Allez en prison.");
    liste_carte_chance.defausser(carte8);
    Carte* carte9 = new Carte(9, 0, 0, 0, 0, 0, 0, "Avancez jusqu'a la case Depart.");
    liste_carte_chance.defausser(carte9);
    Carte* carte10 = new Carte(10, 0, 0, 0, 0, 0, 39, "Rendez-vous a la rue de la Paix.");
    liste_carte_chance.defausser(carte10);
    Carte* carte11 = new Carte(11, 0, 0, 0, 0, 0, 15, "Allez a la gare de Lyon.");
    liste_carte_chance.defausser(carte11);
    Carte* carte12 = new Carte(12, 0, 0, 0, 0, 0, 11, "Avancez au Boulevard de la Vilette.");
    liste_carte_chance.defausser(carte12);
    //liste_carte_chance.defausser(Carte(13, 0, 0, 0, 1, 0, -1, "Faites des réparations dans vos maisons. Versez pour chaque maison 25€ et versez pour chaque hôtel 100€."));
    //liste_carte_chance.defausser(Carte(14, 0, 0, 0, 0, 1, -1, "Faites des réparations dans vos maisons. Versez pour chaque maison 40€ et versez pour chaque hôtel 115€."));
    Carte* carte15 = new Carte(15, 1, 0, 0, 0, 0, -1, "Reculez de trois cases.");
    liste_carte_chance.defausser(carte15);
    Carte* carte16 = new Carte(16, 0, 0, 1, 0, 0, -1, "Vous etes libere de prison. Cette carte peut etre conservee jusqu'à ce qu'elle soit utilisee.");
    liste_carte_chance.defausser(carte16);
}

void Chance::arriverSur(Joueur& joueur, Banque& bank)
{
	std::cout << joueur.getPseudo() << " pioche une carte chance." << std::endl;
	Carte* carteTiree = liste_carte_chance.tirer();
    std::cout << "L'enonce de la carte dit :" << std::endl;
    std::cout << carteTiree->getConsigne() << std::endl;
    
    //Faire la fonction 'payer'

    if (carteTiree->getIdCasePlateau() >= 0) {
        joueur.setPosition(carteTiree->getIdCasePlateau());
    }

    if (carteTiree->getReculeDe3Cases()) {
        joueur.setPosition(joueur.getPosition() - 3);
    }

    if (carteTiree->getPrisonOuPas()) {
        joueur.addCarte(carteTiree, &liste_carte_chance);
    }
    else {
        liste_carte_chance.defausser(carteTiree);
    }
}
