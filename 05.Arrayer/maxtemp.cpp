#include <iostream>
using namespace std;

int main()
{
	const int MAXTEMP = 51;
	int frekvens[MAXTEMP]; // har index 0, 1, 2, ..., MAXTEMP-1
	int temp, max, antal = 0;

	cout << "Ge maxtemperatur (mellan 0 och " << MAXTEMP-1 << "): ";
	cin >> max;

	// Nollställ index i arrayen frekvens
	for(int i = 0; i <= max; i++)
		frekvens[i] = 0;

	cout << "Ge temperaturer (heltal)," << endl;
	cout << "avsluta med negativt tal eller större än "
	<< max <<": " << endl;
	cin >> temp;

	// Läs in temperatur och lägg till på rätt plats i arrayen
	while(0 <= temp && temp <= max)
	{
		frekvens[temp]++;
		antal++;
		cin >> temp;
	}

	if(antal == 0)
	{
		cout << "Inga temperaturer givna!" << endl;
	}
	else
	{
		cout << "Frekvenstabell:" << endl;
		cout << "Temp.\t Antal \t Procent" << endl;

		for(int i = 0; i <= max; i++)
		{
			cout << i << "\t" << frekvens[i] << "\t"
			<< 100.0*frekvens[i]/antal << endl;
		}
	}

	return 0;
}