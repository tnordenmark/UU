#include <iostream>
using namespace std;

int main()
{
	const int MAXTEMP = 51;
	int frekvens[MAXTEMP]; // har index 0, 1, 2, ..., MAXTEMP-1
	int temp, max, min, maxind, antal = 0;

	cout << "Ge min- och maxtemperatur"
		 << " (så att max-min+1 <= " << MAXTEMP << " ): ";
	cin >> min >> max;
	maxind = max - min;

	// Nollställ index i arrayen frekvens
	for(int i = 0; i <= maxind; i++)
		frekvens[i] = 0;

	cout << "Ge temperaturer (heltal)," << endl;
	cout << "avsluta med mindre än " << min
		 << " eller större än " << max << endl;

	cin >> temp;

	// Läs in temperatur och lägg till på rätt plats i arrayen
	while(min <= temp && temp <= max)
	{
		frekvens[temp - min]++; // Lägg till 1 till elementet på plats "temp-min".
		antal++; // Öka på antal temperaturer.
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

		for(int i = 0; i <= maxind; i++)
		{
			cout << i+min << "\t" << frekvens[i] << "\t"
			<< 100.0*frekvens[i]/antal << endl;
		}
	}

	return 0;
}