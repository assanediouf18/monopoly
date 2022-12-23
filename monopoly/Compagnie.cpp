#include "Compagnie.h"
#include <string>
using namespace std;

Compagnie::Compagnie(string Nom, int p, int idCase):Propriete(Nom, p, idCase){
	int nb_case = idCase;
	string nom = Nom;
	int achat = p;
}
/**
void addCompagnie();
void setAutreCompagnie(Compagnie* &C1, Compagnie*& C2);**/