#include <iostream>
#include <string>
using namespace std;

const int antalbok=26;

// Deklaration av funktion som beräknar och skriver ut
// frekvensen av bokstäverna i strängen rad. Även värde-
// anrop fungerar, void histo(string rad);
void histo(const string &rad);

int main()
{
    string rad;

    cout << "Mata in en rad text: ";
    getline(cin, rad);

    // Anrop av funktion som beräknar och skriver ut
    // frekvensen av bokstäver i strängen rad
    histo(rad);

    return 0;
}

void histo(const string &rad)
{
    // En array f att lagra frekvensen i
    // Antal platser är lika med antalet olika bokstäver
    int f[antalbok];

    // Nollställ arrayen f
    for(int i=0; i<antalbok; i++)
        f[i]=0;

    // Loopa igenom hela strängen, tecken för tecken
    for(int i=0; i<(int) rad.length(); i++)
    {
        int index;
        // Om tecknet är en gemen
        if(rad.at(i)>='a' && rad.at(i)<='z')
        {
            // Räkna ut platsen i arrayen
            index = rad.at(i) - 'a';
            // Uppdatera räknaren på rätt plats
            f[index]++;
        }
        // Om tecknet är en versal
        if(rad.at(i)>='A' && rad.at(i)<='Z')
        {
            {
                // Räkna ut platsen i arrayen
                index = rad.at(i) - 'A';
                // Uppdatera räknaren på rätt plats
                f[index]++;
            }
        }
    }

    // Skriv ut frekvensen i en tabell
    cout << "\nBokstav\tFrekvens\n";
    // Gå igenom alla platser i arrayen
    for(int i=0; i<antalbok; i++)
    {
        // Konvertera platsen till ett teckenvärde
        char b = char (i+'A');
        if(f[i]>0)
            cout << b << "\t" << f[i] << endl;
    }
}

