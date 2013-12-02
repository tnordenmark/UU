//
// Programskal till obluppg5A
//
// Hanterar fallet med 26 bokstäver A-Z

#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Globala konstanter:

// Tips: Använd de globala konstanterna ANTAL_BOKSTAVER och ANTAL_SPRAK 
// istället för värdena 26 och 4 i programmet.
const int ANTAL_BOKSTAVER = 26;  //A-Z
const int ANTAL_SPRAK = 4;

// 2d-arrayen TOLK_HJALP innehåller bokstavsfrekvensen i %
// för fyra språk. TOLK_HJALP[0][0] är frekvensen av
// bokstaven a för engelska.TOLK_HJALP[0][25] är frekvensen av
// bokstaven z för engelska.
// Arrayen är en GLOBAL KONSTANT och skall alltså ej skickas 
// som parameter till den funktion som behöver den.
const double TOLK_HJALP[ANTAL_SPRAK][ANTAL_BOKSTAVER]=
       {{8.27,1.48,2.94,4.03,11.78,2.22,1.72,6.77, //engelska
         7.39,0.12,0.81,3.76,2.85,6.71,7.79,1.54,
         0.05,5.95,6.69,9.07,2.66,1.13,2.14,0.19,
         1.89,0.03},
        {7.97,1.40,3.55,3.79,16.89,1.02,1.00,0.75, //franska
         7.08,0.38,0.04,5.51,2.82,8.11,5.19,2.78,
         1.01,6.69,8.35,7.22,6.09,1.35,0.02,0.54,
         0.30,0.15},
        {9.50,1.11,1.53,5.30,8.94,1.74,3.57,3.94,  //svenska
         3.98,0.89,3.26,4.93,3.41,8.46,5.01,1.77,
         0.00,6.73,5.56,9.20,1.94,2.42,0.00,0.05,
         0.45,0.00},
        {5.12,1.95,3.57,5.07,16.87,1.35,3.00,5.79, //tyska
         8.63,0.19,1.14,3.68,3.12,10.64,1.74,0.42,
         0.01,6.30,6.99,5.19,3.92,0.77,1.79,0.01,
         0.69,1.24}};

// Globala variabler är ej tillåtna

//--------------------------------------------------------
// Här kommer klassdeklarationen 
class Text
{
private:
    string analystext;                  // Sträng för att lagra analystexten
    int histo_abs[ANTAL_BOKSTAVER];     // Array för det absoluta histogrammet
    int numbok;                         // Variabel för det totala antalet bokstäver

public:
    Text();                             // Standardkonstruktor
    void setText(string nyText);        // Metod som sätter värdet på textsträngen
    bool beraknaHistogramAbs();         // Returnerar true om text finns, false om inte
    void skrivHistogramAbs();           // Skriver ut histogrammet i en tabell
};
// -------------------------------------------------------

// Huvudprogram:

int main()
{
    // Deklarera variabler
    string text;
    bool histOK;
    Text minText;  // Ett objekt av typen Text skapas

    // Läs in en rad med text från tangentbordet
    cout <<"Ge en rad med text:" << endl;
    getline(cin,text);

    // Skicka strängen text till objektet minText
    minText.setText(text);

    // Beräkna och skriv ut histogrammet
    histOK = minText.beraknaHistogramAbs();
    
    // Utskrift av histogrammet
    minText.skrivHistogramAbs( );

    return 0;
}

// -------------------------------------------------------
// Här skriver du klassimplementationen

// Standardkonstruktor
Text::Text()
{
    // Sätt attributet analystext till en tom sträng
    analystext = "";
    // Initialisera arrayen histo_abs med ANTAL_BOKSTAVER platser
    histo_abs[ANTAL_BOKSTAVER];
    // Sätt bokstavsräknaren till 0
    numbok = 0;
}
//--------------------------------------------------------
// Funktionsdefinitioner:

// Sätt attributet Text.analystext till den sträng användaren matar in
void Text::setText(string nyText)
{
    analystext = nyText;
}

// Beräkna histogrammet från strängen användaren matat in och lagra bokstavsfrekvensen i
// arrayen
bool Text::beraknaHistogramAbs()
{
    // Räknare för att hålla ordning på platsen i arrayen histo_abs[]
    int index;

    // Nollställ arrayen histo_abs[]
    for(int i = 0; i < ANTAL_BOKSTAVER; i++)
        histo_abs[i] = 0;

    // Loopa igenom strängen, tecken för tecken
    for(int i = 0; i < analystext.length(); i++)
    {
        // Konvertera strängens gemener till versaler och lagra dessa i en temporär char-
        // variabel, om ett tecken redan är en versal lämnar toupper() den orörd
        char ch = toupper(analystext[i]);

        if(ch >= 'A' && ch <= 'Z')
        {
            // Räkna ut platsen i arrayen
            index = ch - 'A';
            // Uppdatera frekvensräknaren på rätt plats
            histo_abs[index]++;
            // Uppdatera räknaren för det totala antalet bokstäver
            numbok++;
        }
    }
    // Om antalet bokstäver är större än 0, returnera true, annars false
    if(numbok > 0)
        return true;
    else
        return false;
}

// Skriv ut histogrammet i en enkel tabell med lite ledtext
void Text::skrivHistogramAbs()
{
    cout << endl << "Resultat för bokstäverna A-Z" << endl << endl;
    cout << "Totalt antal bokstäver: " << numbok << endl;
    cout << "Bokstavsfördelning:" << endl << endl;
    
    // Gå igenom alla platser i arrayen
    for(int i = 0; i < ANTAL_BOKSTAVER; i++)
    {
        // Konvertera platsen till ett teckenvärde
        char ch = char (i + 'A');
        cout << ch << ": " << histo_abs[i] << endl;
    }
}
// -------------------------------------------------------
// Rapport om uppgiften
// OU5 - Deluppgift A
// -------------------------------------------------------
//
// I uppgift 5A har jag använt mig av i stort sett samma kod som i uppgift 4A med endast
// lite omstruktureringar för att fungera objektorienterat. En del funderingar dök upp om
// hur man skulle använda standardkonstruktorn tillsammans med en array, men jag tror att
// jag fick ordning på det till slut. Jag funderade även för krångligt angående hur man
// kollar om arrayen innehåller några bokstäver eller ej, men kom sedan på att jag ju
// räknar dem med räknaren numbok.
//
// Jag har använt mig av en PC med Arch Linux x64, GVIM 7.3.918 samt GCC 4.8.0.
//
// -------------------------------------------------------
// Testdata 1 
// -------------------------------------------------------
//
// $ ./uppg5A_ThNo 
// Ge en rad med text:
// AbCdNNooPPwXyZ
//
// Resultat för bokstäverna A-Z
//
// Totalt antal bokstäver: 14
// Bokstavsfördelning:
//
// A: 1
// B: 1
// C: 1
// D: 1
// E: 0
// F: 0
// G: 0
// H: 0
// I: 0
// J: 0
// K: 0
// L: 0
// M: 0
// N: 2
// O: 2
// P: 2
// Q: 0
// R: 0
// S: 0
// T: 0
// U: 0
// V: 0
// W: 1
// X: 1
// Y: 1
// Z: 1
// 
// -------------------------------------------------------
// Testdata 2 
// -------------------------------------------------------
//
// $ ./uppg5A_ThNo 
// Ge en rad med text:
// 1234ddddacccbb!?
//
// Resultat för bokstäverna A-Z
//
// Totalt antal bokstäver: 10
// Bokstavsfördelning:
//
// A: 1
// B: 2
// C: 3
// D: 4
// E: 0
// F: 0
// G: 0
// H: 0
// I: 0
// J: 0
// K: 0
// L: 0
// M: 0
// N: 0
// O: 0
// P: 0
// Q: 0
// R: 0
// S: 0
// T: 0
// U: 0
// V: 0
// W: 0
// X: 0
// Y: 0
// Z: 0
//
// -------------------------------------------------------
// Testdata 3 
// -------------------------------------------------------
//
// $ ./uppg5A_ThNo 
// Ge en rad med text:
// Denna rad innehåller ett å!
//
// Resultat för bokstäverna A-Z
//
// Totalt antal bokstäver: 20
// Bokstavsfördelning:
//
// A: 2
// B: 0
// C: 0
// D: 2
// E: 4
// F: 0
// G: 0
// H: 1
// I: 1
// J: 0
// K: 0
// L: 2
// M: 0
// N: 4
// O: 0
// P: 0
// Q: 0
// R: 2
// S: 0
// T: 2
// U: 0
// V: 0
// W: 0
// X: 0
// Y: 0
// Z: 0
//
// -------------------------------------------------------
// Testdata 4 
// -------------------------------------------------------
//
// $ ./uppg5A_ThNo 
// Ge en rad med text:
//
//
// Resultat för bokstäverna A-Z
//
// Totalt antal bokstäver: 0
// Bokstavsfördelning:
//
// A: 0
// B: 0
// C: 0
// D: 0
// E: 0
// F: 0
// G: 0
// H: 0
// I: 0
// J: 0
// K: 0
// L: 0
// M: 0
// N: 0
// O: 0
// P: 0
// Q: 0
// R: 0
// S: 0
// T: 0
// U: 0
// V: 0
// W: 0
// X: 0
// Y: 0
// Z: 0
