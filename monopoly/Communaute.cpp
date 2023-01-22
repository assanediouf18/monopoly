#include "Communaute.h"

Communaute::Communaute(std::string nom) : Case(nom)
{// Création des cartes caisse de communauté
    Carte* carte1 = new Carte(1, 0, 100, 0, 0, 0, -1, "Recevez votre revenu annuel 100 euros.");
    liste_carte_communaute.defausser(carte1);
    Carte* carte2 = new Carte(2, 0, 50, 0, 0, 0, -1, "La vente de votre stock vous rapporte 50 euros.");
    liste_carte_communaute.defausser(carte2);
    Carte* carte3 = new Carte(3, 0, -100, 0, 0, 0, -1, "Payez a l'Hopital 100 euros.");
    liste_carte_communaute.defausser(carte3);
    Carte* carte4 = new Carte(4, 0, 25, 0, 0, 0, -1, "Recevez votre interet sur l'emprunt a 7%, 25 euros.");
    liste_carte_communaute.defausser(carte4);
    Carte* carte5 = new Carte(5, 0, 20, 0, 0, 0, -1, "Les Contributions vous remboursent la somme de 20 euros.");
    liste_carte_communaute.defausser(carte5);
    Carte* carte6 = new Carte(6, 0, 200, 0, 0, 0, -1, "Erreur de la Banque en votre faveur. Recevez 200 euros.");
    liste_carte_communaute.defausser(carte6);
    Carte* carte7 = new Carte(7, 0, -50, 0, 0, 0, -1, "Payez la note du Medecin 50 euros.");
    liste_carte_communaute.defausser(carte7);
    Carte* carte8 = new Carte(8, 0, 100, 0, 0, 0, -1, "Vous heritez 100 euros.");
    liste_carte_communaute.defausser(carte8);
    Carte* carte9 = new Carte(9, 0, -50, 0, 0, 0, -1, "Payez votre police d'assurance s'elevant a 50 euros.");
    liste_carte_communaute.defausser(carte9);
    Carte* carte10 = new Carte(10, 0, 10, 0, 0, 0, -1, "Vous avez gagne le deuxième Prix de Beaute. Recevez 10 euros.");
    liste_carte_communaute.defausser(carte10);
    Carte* carte11 = new Carte(11, 0, 0, 0, 0, 0, 30, "Allez en prison.");
    liste_carte_communaute.defausser(carte11);
    Carte* carte12 = new Carte(12, 0, 0, 0, 0, 0, 0, "Avancez jusqu'a la case Depart.");
    liste_carte_communaute.defausser(carte12);
    Carte* carte13 = new Carte(13, 0, 0, 0, 0, 0, 1, "Retournez a Belleville.");
    liste_carte_communaute.defausser(carte13);
    Carte* carte14 = new Carte(14, 0, 0, 1, 0, 0, -1, "Vous etes libere de prison. Cette carte peut etre conservee jusqu'a ce qu'elle soit utilisee.");
    liste_carte_communaute.defausser(carte14);
}

void Communaute::arriverSur(Joueur& joueur, Banque& bank)
{
	std::cout << joueur.getPseudo() << " pioche une carte communaute." << std::endl;
    Carte* carteTiree = liste_carte_communaute.tirer();
    std::cout << "L'enonce de la carte dit :" << std::endl;
    std::cout << carteTiree->getConsigne() << std::endl;
    
    bank.payer(carteTiree->getImpact(), joueur);

    if (carteTiree->getIdCasePlateau() >= 0) {
        joueur.setPosition(carteTiree->getIdCasePlateau());
    }

    if (carteTiree->getPrisonOuPas()) {
        joueur.addCarte(carteTiree, &liste_carte_communaute);
    }
    else {
        liste_carte_communaute.defausser(carteTiree);
    }
}
