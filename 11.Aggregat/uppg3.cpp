#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

// Konstant för däckens mönsterdjup och axeltyp
const double MAXdjup = 20.00; // 20 mm
const int framhjulsdriven = 1;
const int bakhjulsdriven = 0;

// --- Externa funktioner ---
double slump(double tal);

// --- Klassen daeck representerar ett bildäck ---
class daeck
{
private:
    double djup;                        // Mönsterdjup = antal mm gummi.

public:
    daeck();
    daeck(double indjup);
    double haemta_djup();
    int slitage(double slitdjup);     // Slit på däcken om det går.
    void skriv();
};

//--- Klassen bil ---
class bil
{
private:
    string typ;            // Biltyp, t.ex. "Volvo"
    int framhjuls;         // Framhjuls-bakhjulsdriven?
    bensintank tank;       // Bensintanken.
    daeck hf, vf, hb, vb;  // Fyra st hjul.
    double xpos;           // x-position, 0=startlinjen.

public:
    bil();                                  // Konstruktorer.
    bil(string nytyp,  int nyfram);
    string haemta_typ();                    // Vilken typ?
    int tom();                              // 1=tom tank, 0 annars. 
    double haemta_x ();                     // Var är bilen?
    void gaspaadrag(double d, double b);    // Gör gaspådrag.
    void skriv();                           // Skriv bilinfo.
};

//--- Klassen besintank ---
class bensintank
{
private:
    double liter; // Antal liter bensin i tanken.
    double volym; // Max antal liter, dvs tankens "volym".

public:
    bensintank();
    bensintank( double lit );                   // Full tank (volym=liter).
    bensintank( double lit, double vol );
    double haemta_liter();
    void foerbruka( double & lit );             // Bensinen minskar om det går.
    void skriv();    
};

//--- Huvudprogram ---
int main()
{
    int seed = long(time(NULL));
    srand48(seed);

    bil Volvo("Volvo");
    bil Saab("Saab");

    Volvo.skriv(); cout << endl;
    Saab.skriv();  cout << endl;
    
    int antVolvo = 0;
    int antSaab = 0;

    cout << "\n---Nu startar tävlingen---" << endl << endl;

    // Tävlingen slutar då Volvo eller Saab har slut på alla däck
    do
    {
        antVolvo = Volvo.gaspaadrag(slump(4));
        antSaab = Saab.gaspaadrag(slump(4));

        Volvo.skriv(); cout << endl;
        Saab.skriv();  cout << endl;

        cout << "Liten paus innan nästa gaspådrag... (tryck enter)." << endl;
        cin.get();
    }while(antVolvo < 4 && antSaab < 4);

    cout << "\n---Slutresultat---" << endl;
    cout << "Vinnare är den som har däck kvar: " << endl;

    if(antVolvo + antSaab == 8)
    {
        cout << "Ingen vinnare, alla har slut på däck." << endl;
    }
    else if(antVolvo == 4)
    {
        Saab.skriv(); cout << endl;
    }
    else if(antSaab == 4)
    {
        Volvo.skriv(); cout << endl;
    }

    cout << "Tack och hej!" << endl;

    return 0;
}

//--- Implementation av däckmetoder ---

//--- Konstruktorer:

daeck::daeck()
    : djup(MAXdjup)
{}

daeck::daeck(double indjup)
    : djup(indjup)
{}

//--- Selektorer:

double daeck::haemta_djup()
{
    return djup;
}

//--- Andra metoder:

int daeck::slitage(double slitdjup)
{
    // Slit ned "slitdjup" mycket av
    // gummit (om det går).
    // Returnera 1 om allt gummi slut,
    // annars 0.

    int slutgummi = 0;

    if (djup - slitdjup < 0)
    {
        djup = 0;
        slutgummi = 1;
    }
    else
        djup -= slitdjup;

    return slutgummi;
}

void daeck::skriv()
{
    cout.setf( ios::fixed );
    cout << " däck = " << setprecision(1) << djup;
}

//--- Implementation av bilmetoder ---

bil::bil()
    : typ("Ingen") 
{
    // Här kommer standardkonstruktorn för daeck
    // att anropas automatiskt fyra ggr (hf,vf,hb,vb).
}

bil::bil( string nytyp )
   : typ(nytyp)
{}

bil::bil(double nyhf, double nyvf, 
         double nyhb, double nyvb)
  : hf(daeck(nyhf)), vf(daeck(nyvf)),
    hb(daeck(nyhb)), vb(daeck(nyvb)), typ("--")
{}

bil::bil(daeck inhf, daeck invf,
         daeck inhb, daeck invb)
  //  : hf(inhf), vf(invf), hb(inhb), vb(invb)
{
    hf = inhf; vf = invf;
    hb = inhb; vb = invb;
}

string bil::haemta_typ()
{
    return typ;
}

int bil::gaspaadrag(double d)
{
    // Däcken slits och bensin går åt 
    // vid en rivstart.
    // Parametrar: d = däckslitage,
    // b = bensinminskning.
    // Beroende på om bilen är framhjuls-
    // eller bakhjulsdriven, så slits
    // den på lite olika sätt...
    //
    // Dessutom, man kan köra på helslitna däck, 
    // men då går det åt mycket mer bensin!
    //
    // Antag att däcken i varje däckpar
    // (höger/vänster) slits lika mycket.

    // Diverse vetenskapligt framtagna konstanter...
    const double framslit = 2.0;
    const double bakslit = 2.5;
    const double framliter = 1.75;
    const double bakliter = 1.5;
    double fram, bak, lit;

    if(framhjuls)
    {
        fram = d*framslit;
        bak  = d;
        lit  = b*framliter;
    }
    else
    {
        fram = d;
        bak  = d*bakslit;
        lit  = b*bakliter;
    }

    double daeckminus = 2*fram + 2*bak;
    double hur_mycket_soppa = tank.haemta_liter(); // init=innan.
    int sum; // sum = antal däck som är helt utslitna

    if (hur_mycket_soppa > 0)
    {
        //***Här saknas det kod***
        // * bygg upp sum genom att slita på däcken.
        // * förbruka rätt mängd bensin.
        // * fixa nya x-positionen.
    }
}

void bil::skriv()
{
    cout.setf(ios::fixed); // Får lite snyggare utskrifter då...

    cout << "Bil av typen = " << typ << "\t har ";
    hf.skriv(); // Skriver bara ut ena i fram och ena i bak.
    hb.skriv(); 
}

//---Implementation av externa funktioner.---
// Funktion för att generera slumptal
double slump(double tal)
{
    // För att få tal i intervallet 0-tal på SUN:
    // return drand48()*tal;
    // För att få tal i intervallet 0-tal på PC:
    // return tal*rand()/double(RAND_MAX);

    return drand48()*tal;  //Vi kör på SUN nu
}

/* Körningsexempel:
Bil av typen = Volvo     har  däck = 20.0 däck = 20.0
Bil av typen = Saab      har  däck = 20.0 däck = 20.0
Antal slutslitna Volvodäck: 0
Bil av typen = Volvo     har  däck = 8.0 däck = 6.0
Antal slutslitna Saabdäck: 0
Bil av typen = Saab      har  däck = 8.0 däck = 6.0
 */
