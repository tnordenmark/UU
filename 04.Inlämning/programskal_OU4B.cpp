//
// Programskal till obluppg4 - deluppgift B
//
// Hanterar fallet med 26 bokstäver A-Z

#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Globala konstanter för antal bokstäver och antal språk
const int antalbok = 26; // A-Z
const int antalsprak = 4;

// 2d-arrayen tolk innehåller bokstavsfrekvensen i %
// för fyra språk. tolk[0][0] är frekvensen av
// bokstaven a för engelska.tolk[0][25] är frekvensen av
// bokstaven z för engelska.
// Arrayen är en GLOBAL KONSTANT och skall alltså ej skickas
// som parameter till den funktion som behöver den.
const double tolk[antalsprak][antalbok]=
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
// Funktionsdeklarationer:

// Funktionen berakna_histogram_abs
int berakna_histogram_abs(string &fil, double freq[], int &numbok);

//Funktionen abs_till_rel
void abs_till_rel(double freq[], int &numbok);

// Funktionen plotta_histogram
void plotta_histogram(double freq[]);

// Funktionen tolka
void tolka(double freq[], string &fil, int &numbok);

// Funktionen namn_pa_fil
string namn_pa_fil();

// Funktionen inlasning
string inlasning(string &filnamn);

//--------------------------------------------------------
// Huvudprogram:

int main()
{
    string str, filnamn;
    string fil = "FILE_NOT_FOUND";
    double freq[antalbok];
    int numbok = 0;

    // Anropa funktionen namn_pa_fil för att bestämma vilket filnamn som ska
    // behandlas
    while(fil == "FILE_NOT_FOUND")
    {
        filnamn = namn_pa_fil();
        cout << endl;
    
    // Anropa funktionen inlasning för att läsa innehållet i angiven fil och
    // lagra innehållet i en sträng
        fil = inlasning(filnamn);
    }
    
    // Anropa funktionen berakna_histogram_abs som beräknar histogrammet
    // och antalet bokstäver
    numbok = berakna_histogram_abs(fil, freq, numbok);
    
    // Anropa funktionen abs_till_rel för att beräkna den relativa frekvensen
    // i procent. Parametrar är den modifierade arrayen med frekvenser (freq)
    // samt det totala antalet bokstäver (numbok)
    abs_till_rel(freq, numbok);

    // Anropa funktionen tolka för att jämföra datan i en fil med fyra olika
    // språks fördefinierade bokstavsfrekvenser.
    tolka(freq, fil, numbok);

    // Anropa funktionen plotta_histogram som skriver ut den relativa
    // frekvensen med 2 st * per procentenhet
    plotta_histogram(freq);

    return 0;
}

//--------------------------------------------------------
// Funktionsdefinitioner:
int berakna_histogram_abs(string &fil, double freq[], int &numbok)
{
    int index;

    // Nollställ arrayen freq[]
    for(int i=0; i<antalbok; i++)
        freq[i]=0;

    // Loopa igenom strängen, tecken för tecken
    for(int i=0; i<fil.length(); i++)
    {
        // Konvertera strängens gemener till versaler, om ett tecken redan är
        // en versal lämnar toupper() den orörd
        fil[i] = toupper(fil[i]);

        if(fil.at(i)>='A' && fil.at(i)<='Z')
        {
            // Räkna ut platsen i arrayen
            index = fil.at(i) - 'A';
            // Uppdatera frekvensräknaren på rätt plats
            freq[index]++;
            // Uppdatera räknaren för det totala antalet bokstäver
            numbok++;
        }
    }
    return numbok;
}

void abs_till_rel(double freq[], int &numbok)
{
    for(int i=0; i<antalbok; i++)
    {
        // Konvertera platsen till ett teckenvärde
        char c = char (i+'A');

        // Gå igenom varje plats i arrayen, typecasta arrayen och totala
        // antalet bokstäver som double för att kunna beräkna procent med
        // decimaler samt trunkera resultatet och behåll en decimal
        freq[i] = trunc((double) freq[i] / (double) numbok * 1000) / 10;
    }
}

void plotta_histogram(double freq[])
{
    cout << "Bokstavsfördelning:" << endl << endl << endl << endl;

    for(int i=0; i<antalbok; i++)
    {
        char c = char (i+'A');
        cout << c << " ";

        for(int j=0; j<freq[i]*2; j++)
            cout << "*";
        cout << endl;
    }
}

void tolka(double freq[], string &fil, int &numbok)
{
    string spraknamn[4] = {"Engelska", "Franska", "Svenska", "Tyska"};
    double sum[4] = {0};
    double skillnad;
    
    cout << "Resultat för bokstäverna A-Z" << endl << endl;
    cout << "Total antalet bokstäver: " << numbok << endl;
    
    // 1d-array för Engelska
    double engelska[antalbok];

    // Fyll på arrayen engelska med värden från tolk
    for(int i=0; i<antalbok; i++)
    {
        for(int j=0; j<1; j++)
        {
            engelska[i] = tolk[j][i];
        }
    }
    
    // Jämför freq med engelska
    for(int i=0; i<antalbok; i++)
    {
            skillnad = engelska[i]-freq[i];
            sum[0] = sum[0] + skillnad * skillnad;
    }
    cout << spraknamn[0] << " har kvadratsumma: " << sum[0] << endl;

    // 1d-arrayen för Franska
    double franska[antalbok];

    // Fyll på arrayen franska med värden från tolk
    for(int i=0; i<antalbok; i++)
    {
        for(int j=1; j<2; j++)
        {
            franska[i] = tolk[j][i];
        }
    }
    
    // Jämför freq med franska
    for(int i=0; i<antalbok; i++)
    {
            skillnad = franska[i]-freq[i];
            sum[1] = sum[1] + skillnad * skillnad;
    }
    cout << spraknamn[1] << " har kvadratsumma: " << sum[1] << endl;

    // 1d-arrayen för Svenska
    double svenska[antalbok];

    // Fyll på arrayen svenska med världen från tolk
    for(int i=0; i<antalbok; i++)
    {
        for(int j=2; j<3; j++)
        {
            svenska[i] = tolk[j][i];
        }
    }
    
    // Jämför freq med svenska
    for(int i=0; i<antalbok; i++)
    {
            skillnad = svenska[i]-freq[i];
            sum[2] = sum[2] + skillnad * skillnad;
    }
    cout << spraknamn[2] << " har kvadratsumma: " << sum[2] << endl;

    // 1d-array för Tyska
    double tyska[antalbok];

    // Fyll på arrayen tyska med värden från tolk
    for(int i=0; i<antalbok; i++)
    {
        for(int j=3; j<4; j++)
        {
            tyska[i] = tolk[j][i];
        }
    }

    // Jämför freq med tyska
    for(int i=0; i<antalbok; i++)
    {
            skillnad = tyska[i]-freq[i];
            sum[3] = sum[3] + skillnad * skillnad;
    }
    cout << spraknamn[3] << " har kvadratsumma: " << sum[3] << endl;

    if(sum[0] < sum[1] && sum[0] < sum[2] && sum[0] < sum[3])
        cout << spraknamn[0] << " är det mest sannolika språket." << endl << endl;
    else if(sum[1] < sum[0] && sum[1] < sum[2] && sum[1] < sum[3])
        cout << spraknamn[1] << " är det mest sannolika språket." << endl << endl;
    else if(sum[2] < sum[0] && sum[2] < sum[1] && sum[2] < sum[3])
        cout << spraknamn[2] << " är det mest sannolika språket." << endl << endl;
    else
        cout << spraknamn[3] << " är det mest sannolika språket." << endl << endl;
}

string namn_pa_fil()
{
    string filnamn;
    string efternamn = ".txt";

    cout << "Ange fil att jämföra: ";
    getline(cin, filnamn);

    size_t key = filnamn.rfind(efternamn);

    if(key == string::npos)
    {
        filnamn.append(".txt");
    }
    
    return filnamn;
}

string inlasning(string &filnamn)
{
    string fil;

    ifstream infil(filnamn.c_str());

    if(!infil.good())
    {
        cout << filnamn << " existerar inte, kontrollera filnamnet." << endl;
        return "FILE_NOT_FOUND";
    }

    while(infil.good())
    {
        char c = infil.get();
        if(infil.good())
            fil += c;
    }

    infil.close();
    
    return fil;
}
// -------------------------------------------------------
// Rapport om uppgiften
// OU4 - Deluppgift B
// ------------------
//
// Deluppgift B var rejält mycket klurigare än deluppgift A. Jag funderade
// en hel del på hur jag skulle lösa skickandet av alla arrayer mellan
// funktionerna och trasslade till det rejält för mig själv genom att
// konstruera egna datatyper (struct) innan jag kom ihåg att arrayer
// som parametrar till funktioner alltid är referenser och således kan
// modifieras fritt så länge man anropar funktionerna i rätt ordning.
