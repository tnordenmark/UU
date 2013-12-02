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
int berakna_histogram_abs(string &fil, double freq[]);

//Funktionen abs_till_rel
void abs_till_rel(double freq[], int &numbok);

// Funktionen plotta_histogram
void plotta_histogram(double freq[]);

// Funktionen tolka
void tolka(double freq[], int &numbok);

// Funktionen namn_pa_fil
string namn_pa_fil();

// Funktionen inlasning
string inlasning(string &filnamn);

//--------------------------------------------------------
// Huvudprogram:

int main()
{
    string filnamn; // Textfilens namn
    string fil = "FILE_NOT_FOUND"; // Textfilens innehåll som en sträng
    double freq[antalbok]; // Array för att spara bokstavsfrekvenser
    int numbok = 0; // Variabel för att spara det totala antalet bokstäver
    
    // Loop som frågar efter fil på nytt om ett felaktigt filnamn angetts
    // (om funktionen filnamn() svarar FILE_NOT_FOUND)
    while(fil == "FILE_NOT_FOUND")
    {
        // Anropa funktionen namn_pa_fil för att bestämma vilket filnamn som ska
        // behandlas
        filnamn = namn_pa_fil();
        cout << endl;
    
        // Anropa funktionen inlasning för att läsa innehållet i angiven fil och
        // lagra innehållet i en sträng. Parameter är filnamnet från funktionen
        // namn_pa_fil (filnamn)
        fil = inlasning(filnamn);
    }
    
    // Anropa funktionen berakna_histogram_abs som beräknar histogrammet
    // och antalet bokstäver. Antalet bokstäver sparas i variabeln numbok
    // för framtida bruk. Parametrar är filens innehåll lagrat som en
    // sträng (fil), arrayen som ska innehålla bokstavsfrekvenserna (freq)
    // samt det totala antalet bokstäver som referens (numbok)
    numbok = berakna_histogram_abs(fil, freq);
    
    // Anropa funktionen abs_till_rel för att beräkna den relativa frekvensen
    // i procent. Parametrar är den modifierade arrayen med frekvenser (freq)
    // samt det totala antalet bokstäver (numbok)
    abs_till_rel(freq, numbok);

    // Anropa funktionen tolka för att jämföra datan i en fil med fyra olika
    // språks fördefinierade bokstavsfrekvenser. Parametrar är arrayen med de
    // relativa frekvenserna (freq) samt det totala antalet bokstäver (numbok)
    tolka(freq, numbok);

    // Anropa funktionen plotta_histogram som skriver ut den relativa
    // frekvensen med 2 st * per procentenhet. Parametrar är arrayen med den
    // relativa frekvensen (freq)
    plotta_histogram(freq);

    return 0;
}

//--------------------------------------------------------
// Funktionsdefinitioner:
int berakna_histogram_abs(string &fil, double freq[])
{
    int index;
    int numbok = 0;

    // Nollställ arrayen freq[]
    for(int i=0; i<antalbok; i++)
        freq[i]=0;

    // Loopa igenom strängen, tecken för tecken
    for(int i=0; i<fil.length(); i++)
    {
        // Konvertera strängens gemener till versaler, om ett tecken redan är
        // en versal lämnar toupper() den orörd
        char c = toupper(fil[i]);

        if(c>='A' && c<='Z')
        {
            // Räkna ut platsen i arrayen
            index = c - 'A';
            // Uppdatera frekvensräknaren på rätt plats
            freq[index]++;
            // Uppdatera räknaren för det totala antalet bokstäver
            numbok++;
        }
    }
    // Skicka tillbaka det totala antalet bokstäver till main()
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
        // decimaler samt lagra dem i arrayen freq[]
        freq[i] = ((double) freq[i] / (double) numbok) * 100;
    }
}

void plotta_histogram(double freq[])
{
    cout << "Bokstavsfördelning:" << endl << endl << endl << endl;

    // Loop för att skriva ut det relativa histogrammet med 2 st asterisker
    // per procentenhet
    for(int i=0; i<antalbok; i++)
    {
        // Skriv ut respektive bokstav
        char c = char (i+'A');
        cout << c << " ";

        // Inre loop för att skriva ut 2 st asterisker per procentenhet
        for(int j=0; j<freq[i]*2; j++)
            cout << "*";
        cout << endl;
    }
}

void tolka(double freq[], int &numbok)
{
    // Array med de aktuella språkens namn
    string spraknamn[antalsprak] = {"Engelska", "Franska", "Svenska", "Tyska"};
    double sum[antalsprak] = {0}; // Array med 4st platser för att lagra summan
    double skillnad; // Variabel för att utföra beräkningen av kvadratsumman
    double kvsumma = 999999999; // Variabel för att lagra hittils lägsta summa
    int sannolikt_sprak = 0; // Index för mest sannolikt språk

    cout << "Resultat för bokstäverna A-Z" << endl << endl;
    cout << "Totala antalet bokstäver: " << numbok << endl;
    
    // Radloop för respektive språk.
    for(int i=0; i<antalsprak; i++)
    {
        // Kolumnloop för respektive bokstav
        for(int j=0; j<antalbok; j++)
        {
            // Beräkna kvadratsumman för respektive jämfört språk
            skillnad = tolk[i][j] - freq[j];
            sum[i] = sum[i] + skillnad * skillnad;

        }
        // Om kvadratsumman är mindre än föregående, lagra den som kvsumma och
        // jämför med den nya kvsumman i nästa varv i radloopen. Sätt sannolikt
        // språk till hittills lägsta kvadratsumma.
        if(sum[i]<kvsumma)
        {
            kvsumma = sum[i];
            sannolikt_sprak = i;
        }
        // Skriv ut kvadratsumman för respektive språk varje varv i radloopen
        cout << spraknamn[i] << " har kvadratsumma: " << sum[i] << endl;
    }
    // Skriv ut indexet med namnet på det mest sannolika språket.
    cout << spraknamn[sannolikt_sprak] << " är det mest sannolika språket."
         << endl << endl;
}

string namn_pa_fil()
{
    string filnamn; // Variabel för att lagra filnamnet
    string efternamn = ".txt"; // Filens fördefinierade efternamn

    // Fråga användaren efter filnamn
    cout << "Ange fil att jämföra: ";
    getline(cin, filnamn);

    // Konstruera en söknyckel som söker efter .txt bakifrån i filnamnet
    size_t key = filnamn.rfind(efternamn);

    // Om filnamn sökts igenom till slutet och .txt ej hittats, lägg till .txt
    // sist i filnamnet
    if(key == string::npos)
    {
        filnamn.append(".txt");
    }
    
    // Skicka tillbaka filnamn till main()
    return filnamn;
}

string inlasning(string &filnamn)
{
    string fil; // Sträng för att lagra filens innehåll

    // Öppna filen för läsning
    ifstream infil(filnamn.c_str());

    // Kontrollera att filen kunde öppnas, om ej skicka tillbaka FILE_NOT_FOUND
    // till loopen i main()
    if(!infil.good())
    {
        cout << filnamn << " existerar inte, kontrollera filnamnet." << endl;
        return "FILE_NOT_FOUND";
    }

    // Om infilen kunde öppnas utan problem, läs in filen tecken för tecken till
    // och lagra den i strängen fil
    while(infil.good())
    {
        char c = infil.get();
        if(infil.good())
            fil += c;
    }
    
    // Stäng filen
    infil.close();
    
    // Skicka tillbaka filens innehåll som strängen fil till main()
    return fil;
}
// -------------------------------------------------------
// Uppdatering rest
// -------------------------------------------------------
//
// Funktionen tolka() använder nu 2d-arrayen tolka direkt och procenturäkningen
// i abs_till_rel() trunkeras inte längre utan (double) behålls i ursprunglig
// form. Även plotta_histogram() är uppdaterad och använder en temporär char
// istället för att direkt arbeta på strängen vid konvertering till versaler.
//
// -------------------------------------------------------
// Rapport om uppgiften
// OU4 - Deluppgift B
// -------------------------------------------------------
//
// Deluppgift B var rejält mycket klurigare än deluppgift A. Jag funderade
// en hel del på hur jag skulle lösa skickandet av alla arrayer mellan
// funktionerna och trasslade till det rejält för mig själv genom att
// konstruera egna datatyper (struct) innan jag kom ihåg att arrayer
// som parametrar till funktioner alltid är referenser och således kan
// modifieras fritt så länge man anropar funktionerna i rätt ordning.
//
// När det gäller funktionen tolka så har jag tagit mig friheten att döpa om
// den från TOLK_HJALP. Detta påverkar dock inte programmets funktion. Jag har
// också döpt om de globala konstanterna, men inte heller detta påverkar
// programmets funktion. 
//
// I vissa funktioner har jag först skrivit förenklad pseudokod i form av
// kommentarer för att sen fylla på med kod under respektive kommentar. Ett
// arbetssätt som jag personligen tycker fungerar bra.
//
// Jag har också valt att fråga efter ett nytt filnamn om användaren skrivit in
// ett filnamn som inte existerar istället för att avsluta programmet omgående.
// Programmet kan ju avslutas när som helst med t.ex. CTRL+C.
//
// Jag har använt mig av en PC med Arch Linux x64, GVIM 7.3.918 samt GCC 4.8.0.
//
// -------------------------------------------------------
// Uppgiftens frågor
// -------------------------------------------------------
//
// 1) I lösningsförslagen tipsar vi om att man ska skapa/ladda hem en fil med
//    bara lite innehåll medan man testar sitt program. Varför, tror du?
//
// En fördel är att det blir lättare att kontrollera att beräkningarna i
// programmet ger de förväntade resultaten (t.ex. manuellt med hjälp av
// en kalkylator) om man bara har 100 bokstäver istället för tusentals.
// En annan fördel är att det är lättare att anpassa innehållet efter
// den funktion eller beräkning man vill testköra.
//
//
// 2) Texten i filen lagerlof.txt innehåller de svenska bokstäverna å, ä och ö.
// Som programet fungerar nu räknas inte dessa bokstäver alls. Hur skulle man
// gå tillväga för att också inkludera å, ä och ö i histogrammet? Du behöver
// inte ge en program-lösning, men resonera kring hur man skulle kunna göra.
//
// Först och främst måste naturligtvis arrayerna utökas dels med frekvenser
// för Å, Ä och Ö men även med fler platser för att dessa extra bokstäver ska
// få plats. Eftersom å, ä och ö har ascii-värden som är högre än 127 kan
// eventuellt problemet lösa genom att deklarera om alla char till unsigned
// char som rymmer värdena 0 - 255 istället för -128 - 127 som en vanlig char.
// Om inte detta skulle fungera skulle det kanske gå att lösa genom att
// inkludera wchar.h och använda sig av wchar_t. Detta är dock inte särskilt
// felsäkert om koden kompileras/körs på en C++-implementering med en annan
// locale än den programmets skapare använt.
// En tredje metod (och troligtvis den mest felsäkra idag) är att använda sig
// uteslutande av UTF-8 både som indata och utdata. Detta skiljer sig mycket
// åt beroende på plattform och verkar vara mer komplicerat under Windows 
// (som använder UTF-16 som standard) än UNIX-liknande system som Apple OS X
// eller Linux. Det finns ett flertal bibliotek att ta till hjälp för att
// hantera unicode, bl.a. libiconv och utfcpp. C++11 innehåller även en del
// datatyper som hanterar unicode.
//
// -------------------------------------------------------
// Körningsexempel 1
// -------------------------------------------------------
// $ ./uppg4B_ThNo_rest 
// Ange fil att jämföra: doyle

// Resultat för bokstäverna A-Z

// Totala antalet bokstäver: 12885
// Engelska har kvadratsumma: 1.75771
// Franska har kvadratsumma: 96.1956
// Svenska har kvadratsumma: 73.3371
// Tyska har kvadratsumma: 116.072
// Engelska är det mest sannolika språket.

// Bokstavsfördelning:
//
//
//
// A *****************
// B ***
// C *******
// D ********
// E *************************
// F *****
// G ***
// H *************
// I ****************
// J *
// K **
// L ********
// M ******
// N *************
// O ****************
// P ****
// Q *
// R ************
// S *************
// T *******************
// U ******
// V ***
// W *****
// X *
// Y *****
// Z *
// 
// -------------------------------------------------------
// Körningsexempel 2
// -------------------------------------------------------
// $ ./uppg4B_ThNo_rest 
// Ange fil att jämföra: kartofel
//
// kartofel.txt existerar inte, kontrollera filnamnet.
// Ange fil att jämföra:
