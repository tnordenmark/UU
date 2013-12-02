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
const int ANTAL_BOKSTAVER = 26; //A-Z
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
    double histo_rel[ANTAL_BOKSTAVER];  // Array för det relativa histogrammet
    int numbok;                         // Variabel för det totala antalet bokstäver

public:
    Text();                             // Standardkonstruktor
    void setText(string nyText);        // Metod som sätter värdet på textsträngen
    bool beraknaHistogramAbs();         // Returnerar true om text finns, false om inte
    void skrivHistogramAbs();           // Skriver ut histogrammet i en tabell
    void absTillRel();                  // Beräknar ett relativt histogram
    void plottaHistogramRel();          // Plottar symboler för det relativa histogrammet
    void beraknaHistogram();            // Anropar de båda beräkningsfunktionerna ovan
    string tolka();                     // Jämför filen mot olika språks bokstavsfrekvenser
};
// -------------------------------------------------------

// Funktionsdeklarationer
// Läser in namnet på filen som ska bearbetas
string namn_pa_fil();

// Läser in innehållet i filen till en sträng
string inlasning(string &filnamn);

// -------------------------------------------------------
// Huvudprogram:

int main()
{
    // Deklarera variabler
    Text minText;  // Ett objekt av typen Text skapas
    string filnamn; // Textfilens namn
    string fil = "FILE_NOT_FOUND"; // Textfilens innehåll som en sträng
    string sprak;
    
    while(fil == "FILE_NOT_FOUND")
    {
        // Anropa funktionen namn_pa_fil för att bestämma vilket filnamn som ska
        // behandlas
        filnamn = namn_pa_fil();
        cout << endl;
    
        // Anropa funktionen inlasning för att läsa innehållet i angiven fil och lagra
        // innehållet i en sträng. Parameter är filnamnet från funktionennamn_pa_fil
        // (filnamn)
        fil = inlasning(filnamn);
    }

    // Skicka strängen text till objektet minText
    minText.setText(fil);

    // Beräkna histogrammet
    minText.beraknaHistogram();
    
    // Jämför filen med arrayen TOLK_HJALP och lagra resultatet i sprak
    sprak = minText.tolka();
    cout << sprak << " är det mest sannolika språket." << endl << endl;

    // Plotta det relatvia histogrammet
    minText.plottaHistogramRel();

    return 0;
}

// -------------------------------------------------------
// Här skriver du klassimplementationen

// Standardkonstruktor
Text::Text()
{
    // Sätt attributet analystext till en tom sträng
    analystext = "";
    // Sätt bokstavsräknaren till 0
    numbok = 0;
}
//--------------------------------------------------------
// Metoddefinitioner:
// Sätt attributet Text.analystext till den sträng användaren matar in
void Text::setText(string fil)
{
    analystext = fil;
}
// Beräkna histogrammet från strängen användaren matat in och lagra bokstavsfrekvensen i
// arrayen
bool Text::beraknaHistogramAbs()
{
    // Räknare för att hålla ordning på platsen i arrayen histo_abs[]
    int index;

    // Nollställ bokstavsräknaren
    numbok = 0;

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
// Beräkna det relativa histogrammet
void Text::absTillRel()
{
    for(int i=0; i<ANTAL_BOKSTAVER; i++)
    {
        // Nollställ arrayen histo_rel[]
        histo_rel[i] = 0;

        // Konvertera platsen till ett teckenvärde
        char ch = char (i+'A');

        // Gå igenom varje plats i arrayen, typecasta arrayen och totala
        // antalet bokstäver som double för att kunna beräkna procent med
        // decimaler samt lagra dem i arrayen histo_rel[]
        histo_rel[i] = ((double) histo_abs[i] / (double) numbok) * 100;
    }
}
// Plotta symboler för det relativa histogrammet
void Text::plottaHistogramRel()
{
    cout << "Bokstavsfördelning:" << endl << endl << endl << endl;

    // Loop för att skriva ut det relativa histogrammet med 2 st asterisker
    // per procentenhet
    for(int i = 0; i < ANTAL_BOKSTAVER; i++)
    {
        // Skriv ut respektive bokstav
        char c = char (i + 'A');
        cout << c << " ";

        // Inre loop för att skriva ut 2 st asterisker per procentenhet
        for(int j = 0; j < histo_rel[i] * 2; j++)
            cout << "*";
        cout << endl;
    }
}
// Metod för att kalla på de två beräkningsmetoderna
void Text::beraknaHistogram()
{
    // Boolean för att sätta villkor för while-repetitionen
    bool histOK = false;
    // Om histOK inte får true tillbaka, repetera funktionsanropet
    while(histOK == false)
    {
        histOK = beraknaHistogramAbs();
    }
    // Anropa funktionen för att beräkna det relativa histogrammet
    absTillRel();
}
// Tolka och jämför den angivna filens bokstavsfrekvenser mot olika språks frekvenser
// och returnera det mest sannolika språket som en sträng
string Text::tolka()
{
    // Array med de aktuella språkens namn
    string spraknamn[ANTAL_SPRAK] = {"Engelska", "Franska", "Svenska", "Tyska"};
    // Array med 4st platser för att lagra summan, deklarationen kräver C++11
    double sum[ANTAL_SPRAK] = {0};
    // Variabel för att utföra beräkningen av kvadratsumman
    double skillnad;
    // Variabel för att lagra hittils lägsta summa
    double kvsumma = 999999999;
    // Index för mest sannolikt språk
    int sannolikt_sprak = 0;

    // Radloop för respektive språk.
    for(int i = 0; i < ANTAL_SPRAK; i++)
    {
        // Kolumnloop för respektive bokstav
        for(int j = 0; j < ANTAL_BOKSTAVER; j++)
        {
            // Beräkna kvadratsumman för respektive jämfört språk
            skillnad = TOLK_HJALP[i][j] - histo_rel[j];
            sum[i] = sum[i] + skillnad * skillnad;
        }
        // Om kvadratsumman är mindre än föregående, lagra den som kvsumma och
        // jämför med den nya kvsumman i nästa varv i radloopen. Sätt sannolikt
        // språk till hittills lägsta kvadratsumma.
        if(sum[i] < kvsumma)
        {
            kvsumma = sum[i];
            sannolikt_sprak = i;
        }
        // Skriv ut kvadratsumman för respektive språk varje varv i radloopen
        cout << spraknamn[i] << " har kvadratsumma: " << sum[i] << endl;
    }
    // Returnera indexet med namnet på det mest sannolika språket till main()
    return spraknamn[sannolikt_sprak];
}
//--------------------------------------------------------
// Funktionsdefinitioner (utanför klassen):
// Ange filnamnet som ska bearbetas
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
// Läs in filen till en sträng
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
// Rapport om uppgiften
// OU5 - Deluppgift B
// -------------------------------------------------------
//
// Deluppgift B har flytit på fint utan några särskilda problem värda att nämna. Jag har
// här, liksom i uppgift 4, valt att repetera förfrågan om filnamn om man matar in ett
// felaktigt filnamn istället för att avsluta programmet då jag personligen tycker att
// det är ett mer förväntat förfarande ur användarsynpunkt. Programmet kan ju avslutas
// närhelst man vill med t.ex. CTRL+C.
//
// Jag har använt mig av en PC med Arch Linux x64, GVIM 7.3.918 samt GCC 4.8.0.
//
// -------------------------------------------------------
// Uppgiftens frågor 
// -------------------------------------------------------
// Finns det någon anledning till varför vi beräknar både det absoluta och det relativa
// histogrammet i samma funktionsanrop?
//
// Jag skulle kunna tänka mig att det är för att hålla main() så liten och okomplicerad
// som möjligt samt att villkoren för exekveringen då hamnar i anropsfunktionen istället
// för i huvudprogrammet och koden blir mer återanvändningsbar.
//
// 
// Tänk dig att vi lägger till en rad sist i huvudprogrammet som anropar funktionen
// setText med en ny text, då får vi resultatet att attributet text ändras, men
// histogrammen fortfarande är desamma och alltså inte hör ihop med den aktuella texten.
// Finns det något sätt att lösa det problemet? Du behöver bara svara med ord, inte
// programmera något nytt.
//
// Skapa ett nytt objekt, t.ex. Text minAndraText och anropa funktionerna på det objektet
// istället (minAndraText.beraknaHistogram()).
//
//
// Skulle man kunna inkludera funktionerna namn_pa_fil och inlasning i klassen? Skulle
// det göra någon skillnad på resultatet? Finns det några fördelar med att använda samma
// funktioner som tidigare?
//
// Funderade lite på varför dessa inte skulle inkluderas i klassen och kan inte komma på
// någon bra anledning till varför det inte skulle gå. Det borde gå att arbeta på
// variablerna direkt istället för att skicka parametrar till externa funktioner.
// Fördelen med att använda samma funktioner som tidigare är dels att man redan skrivit
// koden och slipper uppfinna hjulet på nytt, och dels att den koden redan är testad och
// fungerar.
// -------------------------------------------------------
// Testdata 1 
// -------------------------------------------------------
// $ ./uppg5B_ThNo
// Ange fil att jämföra: doyle
// 
// Engelska har kvadratsumma: 1.75771
// Franska har kvadratsumma: 96.1956
// Svenska har kvadratsumma: 73.3371
// Tyska har kvadratsumma: 116.072
// Engelska är det mest sannolika språket.
// 
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
// -------------------------------------------------------
// Testdata 2 
// -------------------------------------------------------
// $ ./uppg5B_ThNo 
// Ange fil att jämföra: goete.txt
// 
// Engelska har kvadratsumma: 107.856
// Franska har kvadratsumma: 85.205
// Svenska har kvadratsumma: 160.318
// Tyska har kvadratsumma: 1.04313
// Tyska är det mest sannolika språket.
// 
// Bokstavsfördelning:
// 
// 
// 
// A ***********
// B ****
// C ********
// D **********
// E **********************************
// F ***
// G *******
// H ************
// I ******************
// J *
// K ***
// L *******
// M *******
// N **********************
// O *****
// P *
// Q *
// R *************
// S **************
// T ************
// U ********
// V **
// W ****
// X 
// Y **
// Z *** 
// -------------------------------------------------------
// Testdata 3 
// -------------------------------------------------------
// $ ./uppg5B_ThNo 
// Ange fil att jämföra: lagerlof
// 
// Engelska har kvadratsumma: 86.6804
// Franska har kvadratsumma: 145.722
// Svenska har kvadratsumma: 8.88258
// Tyska har kvadratsumma: 170.223
// Svenska är det mest sannolika språket.
// 
// Bokstavsfördelning:
// 
// 
// 
// A ***********************
// B **
// C ***
// D ************
// E ********************
// F *****
// G *********
// H ********
// I *********
// J ***
// K *******
// L ***********
// M ********
// N *******************
// O *********
// P ***
// Q 
// R ***************
// S **************
// T ******************
// U ****
// V *******
// W 
// X *
// Y *
// Z 
// -------------------------------------------------------
// Testdata 4 
// -------------------------------------------------------
// $ ./uppg5B_ThNo 
// Ange fil att jämföra: verne
// 
// Engelska har kvadratsumma: 112.425
// Franska har kvadratsumma: 0.885142
// Svenska har kvadratsumma: 149.256
// Tyska har kvadratsumma: 90.491
// Franska är det mest sannolika språket.
// 
// Bokstavsfördelning:
// 
// 
// 
// A *****************
// B ***
// C ********
// D *********
// E ***********************************
// F **
// G ***
// H **
// I **************
// J *
// K *
// L ***********
// M ******
// N ****************
// O ***********
// P ******
// Q **
// R **************
// S *****************
// T **************
// U ************
// V ***
// W *
// X **
// Y *
// Z *
// -------------------------------------------------------
// Testdata 5 
// -------------------------------------------------------
// $ ./uppg5B_ThNo 
// Ange fil att jämföra: kartofel.txt

// kartofel.txt existerar inte, kontrollera filnamnet.
// Ange fil att jämföra:
