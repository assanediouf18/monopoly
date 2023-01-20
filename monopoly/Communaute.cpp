#include "Communaute.h"

Communaute::Communaute(std::string nom) : Case(nom)
{// Cr�ation des cartes caisse de communaut�
    liste_carte_communaute.defausser(Carte(1, 0, 100, 0, 0, 0, -1, "Recevez votre revenu annuel 100�."));
    liste_carte_communaute.defausser(Carte(2, 0, 50, 0, 0, 0, -1, "La vente de votre stock vous rapporte 50�."));
    liste_carte_communaute.defausser(Carte(3, 0, -100, 0, 0, 0, -1, "Payez � l'H�pital 100�."));
    liste_carte_communaute.defausser(Carte(4, 0, 25, 0, 0, 0, -1, "Recevez votre int�r�t sur l'emprunt � 7%, 25�."));
    liste_carte_communaute.defausser(Carte(5, 0, 20, 0, 0, 0, -1, "Les Contributions vous remboursent la somme de 20�."));
    liste_carte_communaute.defausser(Carte(6, 0, 200, 0, 0, 0, -1, "Erreur de la Banque en votre faveur. Recevez 200�."));
    liste_carte_communaute.defausser(Carte(7, 0, -50, 0, 0, 0, -1, "Payez la note du M�decin 50�."));
    liste_carte_communaute.defausser(Carte(8, 0, 100, 0, 0, 0, -1, "Vous h�ritez 100�."));
    liste_carte_communaute.defausser(Carte(9, 0, -50, 0, 0, 0, -1, "Payez votre police d'assurance s'�levant � 50�."));
    liste_carte_communaute.defausser(Carte(10, 0, 10, 0, 0, 0, -1, "Vous avez gagn� le deuxi�me Prix de Beaut�. Recevez 10�."));
    liste_carte_communaute.defausser(Carte(11, 0, 0, 0, 0, 0, 30, "Allez en prison."));
    liste_carte_communaute.defausser(Carte(12, 0, 0, 0, 0, 0, 0, "Avancez jusqu'� la case D�part."));
    liste_carte_communaute.defausser(Carte(13, 0, 0, 0, 0, 0, 1, "Retournez � Belleville."));
    liste_carte_communaute.defausser(Carte(14, 0, 0, 1, 0, 0, -1, "Vous �tes lib�r� de prison. Cette carte peut �tre conserv�e jusqu'� ce qu'elle soit utilis�e."));
}

void Communaute::arriverSur(Joueur& joueur)
{
	std::cout << joueur.getPseudo() << " pioche une carte communaut�." << std::endl;
    Carte carteTiree = liste_carte_communaute.tirer();
    std::cout << carteTiree.getConsigne() << std::endl;
    
    //Faire la fonction 'payer'

    if (carteTiree.getIdCasePlateau() >= 0) {
        joueur.setPosition(carteTiree.getIdCasePlateau());
    };

    if (carteTiree.getPrisonOuPas()) {
        joueur.addCarte(carteTiree, liste_carte_communaute);
    };
}
