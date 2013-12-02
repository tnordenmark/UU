//
// Programskal till obluppg4 - deluppgift A
//
// Hanterar fallet med 26 bokstäver A-Z

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;


// Global konstant för 26 bokstäver (A - Z)
const int antalbok = 26;

// Funktionsdeklarationer:

// Funktionen berakna_histogram_abs
int berakna_histogram_abs(string &str, int freq[], int &numbok);

// Funktionen skriv_histogram_abs
void skriv_histogram_abs(int freq[], int &numbok);

//--------------------------------------------------------
// Huvudprogram:

int main()
{
    // Deklarera variabler
    string str;
    int freq[antalbok];
    int numbok;

    // Läs in en str med text från tangentbordet
    cout << "Mata in en rad text: ";
    getline(cin, str);
    cout << endl;

    // Anropa funktionen berakna_histogram_abs som beräknar histogrammet
    // och antalet bokstäver
    berakna_histogram_abs(str, freq, numbok);

    // Anropa funktionen skriv_histogram_abs som skriver ut histogrammet
    skriv_histogram_abs(freq, numbok);

    return 0;
}

//--------------------------------------------------------
// Funktionsdefinitioner:
int berakna_histogram_abs(string &str, int freq[], int &numbok)
{
    // Räknare för att hålla ordning på platsen i arrayen freq
    int index;

    // Nollställ arrayen freq[]
    for(int i=0; i<antalbok; i++)
        freq[i]=0;

    // Loopa igenom strängen, tecken för tecken
    for(int i=0; i<str.length(); i++)
    {
        // Konvertera strängens gemener till versaler, om ett tecken redan är
        // en versal lämnar toupper() den orörd
        str[i] = toupper(str[i]);

        if(str.at(i)>='A' && str.at(i)<='Z')
        {
            // Räkna ut platsen i arrayen
            index = str.at(i) - 'A';
            // Uppdatera frekvensräknaren på rätt plats
            freq[index]++;
            // Uppdatera räknaren för det totala antalet bokstäver
            numbok++;
        }
    }
    // Ge tillbaka det totala antalet bokstäver
    return numbok;
}

void skriv_histogram_abs(int freq[], int &numbok)
{
    cout << "Resultat för bokstäverna A-Z" << endl << endl;
    cout << "Totalt antal bokstäver: " << numbok << endl;
    cout << "Bokstavsfördelning:" << endl << endl << endl << endl;
    
    // Skriv ut frekvensen i en förenklad tabell
    // Gå igenom alla platser i arrayen
    for(int i=0; i<antalbok; i++)
    {
        // Konvertera platsen till ett teckenvärde
        char c = char (i+'A');
        cout << c << ": " << freq[i] << endl;
    }
}
// -------------------------------------------------------
// Redovisning av uppgiften i ord.
// OU4 - Deluppgift A
// -------------------------------------------------------
//
// Angående deluppgift A finns inte särskilt mycket att tillägga. Arbetet
// flöt på utan problem och gick att lösa med samma metoder som i övningarna i
// de tre föregående avsnitten i kursen. Jag har även försökt att kommentera
// koden väl så att mer ingående förklaringar ska vara överflödiga.
// Frågorna kommer att besvaras i filen som innehåller deluppgift B.
//
// Jag har använt mig av en PC med Arch Linux x64, GVIM 7.3.918 samt GCC 4.8.0.
