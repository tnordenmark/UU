#include <iostream>
using namespace std;

long ant_sek(int tim, int min, int sek);

int main()
{
	int tim, min, sek, resultat;

	cout << "Skriv in antal timmar, minuter och "
	<< "sekunder separerade med mellanslag:" << endl;
	cin >> tim >> min >> sek;

	resultat = ant_sek(tim, min, sek);

	cout << "Resultatet är " << resultat << " sekunder." << endl;
}

long ant_sek(int tim, int min, int sek)
{
	int total_sek;

	total_sek = (tim * 3600) + (min * 60) + sek;

	return total_sek;
}