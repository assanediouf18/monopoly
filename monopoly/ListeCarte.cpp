#include "ListeCarte.h"

ListeCarte::ListeCarte()
{
	//Création des cartes chances
liste_carte_chance[0]=Carte(1,0,50,0,0,0,-1,"La Banque vous verse une dividende de 50€.");
liste_carte_chance[1]=Carte(2,0,-20,0,0,0,-1,"Amende pour ivresse : 20€.");
liste_carte_chance[2]=Carte(3,0,-15,0,0,0,-1,"Amende pour excès de vitesse : 15€.");
liste_carte_chance[3]=Carte(4,0,100,0,0,0,-1,"Vous avez gagné le prix de mots croisés. Recevez 100€.");
liste_carte_chance[4]=Carte(5,0,-150,0,0,0,-1,"Payez pour frais de scolarité 150€.");
liste_carte_chance[5]=Carte(6,0,150,0,0,0,-1,"Votre immeuble et votre prêt rapportent. Vous devez toucher 150€.");
liste_carte_chance[6]=Carte(7,0,0,0,0,0,24,"Rendez-vous à l'Avenue Henri-Martin.");
liste_carte_chance[7]=Carte(8,0,0,0,0,0,30,"Allez en prison.");
liste_carte_chance[8]=Carte(9,0,0,0,0,0,0,"Avancez jusqu'à la case Départ.");
liste_carte_chance[9]=Carte(10,0,0,0,0,0,39,"Rendez-vous à la rue de la Paix.");
liste_carte_chance[10]=Carte(11,0,0,0,0,0,15,"Allez à la gare de Lyon.");
liste_carte_chance[11]=Carte(12,0,0,0,0,0,11,"Avancez au Boulevard de la Vilette.");
liste_carte_chance[12]=Carte(13,0,0,0,1,0,-1,"Faites des réparations dans vos maisons. Versez pour chaque maison 25€ et versez pour chaque hôtel 100€.");
liste_carte_chance[13]=Carte(14,0,0,0,0,1,-1,"Faites des réparations dans vos maisons. Versez pour chaque maison 40€ et versez pour chaque hôtel 115€.");
liste_carte_chance[14]=Carte(15,1,0,0,0,0,-1,"Reculez de trois cases.");
liste_carte_chance[15]=Carte(16,0,0,1,0,0,-1,"Vous êtes libéré de prison. Cette carte peut être conservée jusqu'à ce qu'elle soit utilisée.");

// Création des cartes caisse de communauté
liste_carte_communaute[0]=Carte(1,0,100,0,0,0,-1,"Recevez votre revenu annuel 100€.");
liste_carte_communaute[1]=Carte(2,0,50,0,0,0,-1,"La vente de votre stock vous rapporte 50€.");
liste_carte_communaute[2]=Carte(3,0,-100,0,0,0,-1,"Payez à l'Hôpital 100€.");
liste_carte_communaute[3]=Carte(4,0,25,0,0,0,-1,"Recevez votre intérêt sur l'emprunt à 7%, 25€.");
liste_carte_communaute[4]=Carte(5,0,20,0,0,0,-1,"Les Contributions vous remboursent la somme de 20€.");
liste_carte_communaute[5]=Carte(6,0,200,0,0,0,-1,"Erreur de la Banque en votre faveur. Recevez 200€.");
liste_carte_communaute[6]=Carte(7,0,-50,0,0,0,-1,"Payez la note du Médecin 50€.");
liste_carte_communaute[7]=Carte(8,0,100,0,0,0,-1,"Vous héritez 100€.");
liste_carte_communaute[8]=Carte(9,0,-50,0,0,0,-1,"Payez votre police d'assurance s'élevant à 50€.");
liste_carte_communaute[9]=Carte(10,0,10,0,0,0,-1,"Vous avez gagné le deuxième Prix de Beauté. Recevez 10€.");
liste_carte_communaute[10]=Carte(11,0,0,0,0,0,30,"Allez en prison.");
liste_carte_communaute[11]=Carte(12,0,0,0,0,0,0,"Avancez jusqu'à la case Départ.");
liste_carte_communaute[12]=Carte(13,0,0,0,0,0,1,"Retournez à Belleville.");
liste_carte_communaute[13]=Carte(14,0,0,1,0,0,-1,"Vous êtes libéré de prison. Cette carte peut être conservée jusqu'à ce qu'elle
}

void ListeCarte::tirer()
{
}

void ListeCarte::melanger()
{
}

void ListeCarte::defausser(Carte* carte)
{
}
