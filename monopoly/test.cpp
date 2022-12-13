#include "test.h"
#include "Prison.h"

using namespace std;

void testerPrison()
{
	cout << "Test de la classe Prison" << endl;
	Joueur J, B;
	Prison prison("Prison");
	prison.getSuivant(J);

	J.has_a_double(1);
	prison.getSuivant(J);

	prison.getSuivant(B);
	prison.getSuivant(B);
	prison.getSuivant(B);
}