/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: VT/2013

Inlämningsuppgift nr: 6A

Namn: Thomas Nordenmark

Personummer: 810427-8257

Fyll i (alt. stryk det som INTE är relevant) av nedanstående:

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja
     Om Nej, beskriv vilka testdata som ger problem: -

Jag har använt kompilator/editor: GCC 4.8.1 / LLVM-GCC 4.2.1
                                  GVim 7.4 / MacVim 7.4

Jag har använt följande dator: PC / MacBook 3.1
      med operativsystemet: Arch Linux x64 / OS X Lion 10.7.5

Jag har arbetat ungefär 15 timmar med denna uppgift

================================================================================
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//---Globala konstanter---
const int MAX_KOMPISAR = 10;
const int MAX_PERSONER = 10;
const int MAX_TRANSAKTIONER = 30;

//---Deklaration av externa funktioner---
void visaMeny();
int menyVal();

//---Deklaration av programmets klasser---
// Lagrar en persons sammanlagda transaktionsdata
class Person
{
private:
    string namn;
    double betalat_andras;   // ligger ute med totalt
    double skyldig;          // skyldig totalt

public:
    Person();
    Person(string n, double b, double s);
    double haemta_betalat();
    double haemta_skyldig();
    string haemta_namn();
    void skrivUt();
};

// Håller ordning på personer som deltar i sammanhanget
class PersonLista
{
private:
    int antal_pers;
    Person pers[MAX_PERSONER];

public:
    PersonLista();
    ~PersonLista();
    void laggTillEn(Person pny);
    void skrivUtOchFixa();
    double summaSkyldig();
    double summaBetalat();
    bool finnsNamn(string namnet);
};

// Lagrar data om en viss transaktion
class Transaktion
{
private:
    string datum;
    string typ;
    string namn;
    double belopp;
    int ant_kompisar;
    string kompisar[MAX_KOMPISAR];

public:
    Transaktion();
    ~Transaktion();
    string haemta_namn();
    double haemta_belopp();
    int haemta_ant_kompisar();
    double haemta_skyldig(string namnet);
    bool finnsKompis(string namnet);
    bool laesEnTrans(istream &is);
    void skrivEnTrans(ostream &os);
};

// Lagrar data om samtliga transaktioner
class TransaktionsLista
{
private:
    Transaktion trans[MAX_TRANSAKTIONER];
    int antalTrans;

public:
    TransaktionsLista();
    ~TransaktionsLista();
    void laesin(istream &is);
    void skrivut(ostream &os);
    void laggTill(Transaktion &t);
    double totalkostnad();
    double liggerUteMed(string namnet);
    double aerSkyldig(string namnet);
    PersonLista FixaPersoner();
};

//---Huvudprogram---
int main()
{
    // Deklaration av variabler
    int menyval = -1; // Menyvalet för huvudmenyn
    int antal = 0; // Antal nya transaktioner för denna session
    string namnet; // Namnet på person för att ta reda på skuld, utlägg m.m
    
    // Skapa objekt
    Transaktion t;
    TransaktionsLista tlista;
    PersonLista perslista;
    Transaktion nya_trans[MAX_TRANSAKTIONER]; // Array för tillagda transaktioner
    
    // Skapa och öppna infilsobjekt
    ifstream infil("resa.txt");
    // Skapa och öppna utfilsobjekt
    ofstream utfil("resa.txt", ios_base::app);
    // Börja med att läsa in alla data från infil
    tlista.laesin(infil);
    // Stäng infil
    infil.close();

    // Så länge menyvalet inte är 0
    while(menyval != 0)
    {
        // Visa huvudmenyn
        visaMeny();
        // Hämta menyvalet
        menyval = menyVal();
        
        // Switch för huvudmenyns olika aktiviteter
        switch(menyval)
        {
            case 0: // Avsluta och skriv nya transaktioner på fil
                cout << "\nProgrammet avslutas. Nya transaktioner skrivs till fil."
                     << endl;

                for(int i = 0; i < antal; i++)
                {
                    nya_trans[i].skrivEnTrans(utfil);
                }

                // Stäng utfilen, behövs egentligen inte
                utfil.close();
                break;
            case 1: // Läs transaktion från tangentbord
                t.laesEnTrans(cin);
                tlista.laggTill(t);
                nya_trans[antal] = t;
                antal++;
                break;
            case 2: // Skriv info om samtliga transaktioner
                cout << "\nSkriver info om samtliga transaktioner:" << endl;
                tlista.skrivut(cout);
                cout << endl;
                break;
            case 3: // Skriv ut aktivitetens totalkostnad
                cout << "\nAktivitetens totalkostnad: " << tlista.totalkostnad()
                     << " kr." << endl << endl;
                break;
            case 4: // Kontrollera en given persons skuld
                cout << "Ange namn: "; cin >> namnet;
                cout << namnet << " är skyldig: " << tlista.aerSkyldig(namnet)
                     << " kr." << endl << endl;
                break;
            case 5: // Kontrollera en given persons utlägg
                cout << "Ange namn: "; cin >> namnet;
                cout << namnet << " ligger ute med: "
                     << tlista.liggerUteMed(namnet) << " kr." << endl << endl;
                break;
            case 6: // Skriv ut alla deltagare och beräkna slutresultat
                perslista = tlista.FixaPersoner();
                cout << endl;
                perslista.skrivUtOchFixa();
                cout << endl;
                break;
        }
    }

    return 0;
}

//---Definition av externa funktioner---
// Funktion för att skriva ut huvudmenyn
void visaMeny()
{
    cout << "*************Välj i menyn nedan*************" << endl << endl;
    cout << "0. Avsluta. Alla transaktioner sparas på fil." << endl;
    cout << "1. Läs in en transaktion från tangentbordet." << endl;
    cout << "2. Skriv ut information om alla transaktioner." << endl;
    cout << "3. Beräkna totala kostnaden." << endl;
    cout << "4. Hur mycket är en viss person skyldig?" << endl;
    cout << "5. Hur mycket ligger en viss person ute med?" << endl;
    cout << "6. Lista alla personer mm och FIXA!" << endl << endl;
}

// Funktion för att hantera valet i huvudmenyn
int menyVal()
{
    int menyval;
    
    cout << "Menyval: ";
    cin >> menyval;
    
    return menyval;
}

//---Definition av metoder i klasser---
//---Metoder i klassen Person---
// Konstruktor
Person::Person()
{
    namn = "";
    betalat_andras = 0.0;
    skyldig = 0.0;
}

// Överlagrad konstruktor
Person::Person(string n, double b, double s)
{
    namn = n;
    betalat_andras = b;
    skyldig = s;
}

// Selektorer
double Person::haemta_betalat()
{
    return betalat_andras;
}

double Person::haemta_skyldig()
{
    return skyldig;
}

string Person::haemta_namn()
{
    return namn;
}

// Skriver information om en given persons betalningar och skulder
void Person::skrivUt()
{
    if(betalat_andras > skyldig)
    {
        cout << namn << " ligger ute med " << setiosflags(ios::fixed)
             << setprecision(0) << betalat_andras << ", är skyldig "
             << setiosflags(ios::fixed) << setprecision(0) << skyldig
             << " och ska ha " << setiosflags(ios::fixed) << setprecision(0)
             << betalat_andras - skyldig << " från potten." << endl;
    }
    else
    {
        cout << namn << " ligger ute med " << setiosflags(ios::fixed)
             << setprecision(0) << betalat_andras << ", är skyldig "
             << setiosflags(ios::fixed) << setprecision(0) << skyldig
             << " och ska betala " << setiosflags(ios::fixed) << setprecision(0)
             << skyldig - betalat_andras << " till potten." << endl;
    }
}

//---Metoder i klassen PersonLista---
// Konstruktor
PersonLista::PersonLista()
{
    antal_pers = 0;
}

// Destruktor
PersonLista::~PersonLista()
{
}

// Lägger till en ny person till arrayen pers[]
void PersonLista::laggTillEn(Person pny)
{
    pers[antal_pers] = pny;
    antal_pers++;
}

// Skriver ut information om varje personobjekt i arrayen pers[]
void PersonLista::skrivUtOchFixa()
{
    for(int i = 0; i < antal_pers; i++)
    {
        pers[i].skrivUt();
    }
}

// Summan av alla skulder för en given person
double PersonLista::summaSkyldig()
{
    double skyldig = 0.0;
    
    for(int i = 0; i < antal_pers; i++)
    {
        skyldig += pers[i].haemta_skyldig();
    }
    
    return skyldig;
}

// Summan av alla utlägg för en given person
double PersonLista::summaBetalat()
{
    double betalat = 0.0;

    for(int i = 0; i < antal_pers; i++)
    {
        betalat += pers[i].haemta_betalat();
    }

    return betalat;
}

// Finns det givna namnet i personarrayen?
bool PersonLista::finnsNamn(string namnet)
{
    for(int i = 0; i < MAX_PERSONER; i++)
    {
        if(pers[i].haemta_namn() == namnet)
        {
            return true;
	}
    }

    return false;
}

//---Metoder i klassen Transaktion---
// Konstruktor
Transaktion::Transaktion()
{
    datum = "";
    typ = "";
    namn = "";
    belopp = 0.0;
    ant_kompisar = 0;

    for(int i = 0; i < MAX_KOMPISAR; i++)
    {
        kompisar[i] = "";
    }
}

// Destruktor
Transaktion::~Transaktion()
{
}

// Selektorer
string Transaktion::haemta_namn()
{
    return namn;
}

double Transaktion::haemta_belopp()
{
    return belopp;
}

int Transaktion::haemta_ant_kompisar()
{
    return ant_kompisar;
}

double Transaktion::haemta_skyldig(string namnet)
{
    double skuld = 0.0;

    for(int i = 0; i < ant_kompisar; i++)
    {
        if(kompisar[i] == namnet)
        {
            skuld = belopp / (ant_kompisar + 1);
        }
    }

    return skuld;
}

// Returnerar true om namnet finns i arrayen kompisar
bool Transaktion::finnsKompis(string namnet)
{
    for(int i = 0; i < MAX_KOMPISAR; i++)
    {
        if(kompisar[i].find(namnet, 0) != std::string::npos)
            return true;
    }
}

// Läser en transaktion
bool Transaktion::laesEnTrans(istream &is)
{
    is >> datum >> typ >> namn >> belopp >> ant_kompisar;
    for(int i = 0; i < ant_kompisar; i++)
        is >> kompisar[i];

    return !is.eof();
}

// Skriver info om ett transaktionsobjekt
void Transaktion::skrivEnTrans(ostream &os)
{
    os << datum << "\t" << typ << "\t" << namn << "\t" << belopp << "\t" << ant_kompisar
        << "\t";
    for(int i = 0; i < ant_kompisar; i++)
        os << kompisar[i] << "\t";
     
    os << endl;
}

//---Metoder i klassen TransaktionsLista---
// Konstruktor
TransaktionsLista::TransaktionsLista()
{
    antalTrans = 0;
}

// Destruktor
TransaktionsLista::~TransaktionsLista()
{
}

// Använder Transaktion::laesEnTrans och TransaktionsLista::laggTill för att läsa
// in data till arrayen trans[]
void TransaktionsLista::laesin(istream &is)
{
    Transaktion t;
    
    // Så länge det finns rader kvar att läsa i infil
    while(t.laesEnTrans(is))
    {
        laggTill(t);
    }
}

// Använder Transaktion::skrivEnTrans för att skriva ut info om samtliga
// transaktionsobjekt i arrayen trans[]
void TransaktionsLista::skrivut(ostream &os)
{
    for(int i = 0; i < antalTrans; i++)
    {
        trans[i].skrivEnTrans(os);
    }
}

// Lägger till aktuellt objekt sist i arrayen trans[]
void TransaktionsLista::laggTill(Transaktion &t)
{
    trans[antalTrans] = t;
    antalTrans++;
}

// Summerar aktivitetens totala kostnader
double TransaktionsLista::totalkostnad()
{
    double totalkostnad = 0;

    for(int i = 0; i < antalTrans; i++)
    {
        totalkostnad += trans[i].haemta_belopp();
    }
    
    return totalkostnad;
}

// Beräknar hur mycket pengar en given person ligger ute med
double TransaktionsLista::liggerUteMed(string namnet)
{
    double betalat = 0.0;
    
    for(int i = 0; i < antalTrans; i++)
    {
        if(trans[i].haemta_namn() == namnet)
            betalat += (trans[i].haemta_belopp() - (trans[i].haemta_belopp() /
                       (trans[i].haemta_ant_kompisar() + 1)));
    }
    
    return betalat;
}

// Beräknar hur mycket en given person är skyldig
double TransaktionsLista::aerSkyldig(string namnet)
{
    double skyldig = 0.0;
    
    for(int i = 0; i < antalTrans; i++) 
    {
        if (trans[i].finnsKompis(namnet))
            skyldig += trans[i].haemta_skyldig(namnet);
    }
    
    return skyldig ;
}

// Skapar ett PersonListe-objekt med data om en persons transaktioner
PersonLista TransaktionsLista::FixaPersoner()
{
    PersonLista perslista;
    string persnamn;
    double persskuld;
    double persbetalat;

    for(int i = 0; i < antalTrans; i++)
    {
        if(!perslista.finnsNamn(trans[i].haemta_namn()))
        {
            persnamn = trans[i].haemta_namn();
            persskuld =+ aerSkyldig(persnamn);
            persbetalat =+ liggerUteMed(persnamn);

            Person nypers = Person(persnamn, persbetalat, persskuld);
            perslista.laggTillEn(nypers);
        }
    }
    
    return perslista;
}
/*
================================================================================
Här följer programkörningar för alla testdata:
==============================================
Testdata 1:
==============================================

$ ./uppg6A_ThNo
*************Välj i menyn nedan*************

0. Avsluta. Alla transaktioner sparas på fil.
1. Läs in en transaktion från tangentbordet.
2. Skriv ut information om alla transaktioner.
3. Beräkna totala kostnaden.
4. Hur mycket är en viss person skyldig?
5. Hur mycket ligger en viss person ute med?
6. Lista alla personer mm och FIXA!

Menyval: 2

Skriver info om samtliga transaktioner:
050615	transp	Eva	6000	5	Bosse	Kristin	Paul	Torsten	Stina
050721	mat	Eva	300	2	Bosse	Kristin
050721	mat	Paul	400	2	Torsten	Stina
050721	transp	Bosse	5000	3	Eva	Kristin	Paul
050721	transp	Stina	5000	1	Torsten
050722	boende	Kristin	200	1	Eva
050722	mat	Eva	300	2	Kristin	Bosse
050723	mat	Torsten	300	2	Paul	Stina
050724	mat	Paul	200	1	Stina
050725	transp	Eva	600	3	Bosse	Kristin	Paul...

*************Välj i menyn nedan*************

0. Avsluta. Alla transaktioner sparas på fil.
1. Läs in en transaktion från tangentbordet.
2. Skriv ut information om alla transaktioner.
3. Beräkna totala kostnaden.
4. Hur mycket är en viss person skyldig?
5. Hur mycket ligger en viss person ute med?
6. Lista alla personer mm och FIXA!

Menyval: 6

Eva ligger ute med 5850, är skyldig 1350 och ska ha 4500 från potten.
Paul ligger ute med 367, är skyldig 2500 och ska betala 2133 till potten.
Bosse ligger ute med 3750, är skyldig 1350 och ska ha 2400 från potten.
Stina ligger ute med 2500, är skyldig 1333 och ska ha 1167 från potten.
Kristin ligger ute med 100, är skyldig 2600 och ska betala 2500 till potten.
Torsten ligger ute med 200, är skyldig 3633 och ska betala 3433 till potten.

==============================================
Testdata 2:
==============================================

$ ./uppg6A_ThNo
*************Välj i menyn nedan*************

0. Avsluta. Alla transaktioner sparas på fil.
1. Läs in en transaktion från tangentbordet.
2. Skriv ut information om alla transaktioner.
3. Beräkna totala kostnaden.
4. Hur mycket är en viss person skyldig?
5. Hur mycket ligger en viss person ute med?
6. Lista alla personer mm och FIXA!

Menyval: 2

Skriver info om samtliga transaktioner:
050721	mat	Eva	200	1	Bosse
050722	mat	Eva	400	1	Bosse
050725	transp	Eva	600	1	Bosse
050725	mat	Bosse	200	1	Eva

*************Välj i menyn nedan*************

0. Avsluta. Alla transaktioner sparas på fil.
1. Läs in en transaktion från tangentbordet.
2. Skriv ut information om alla transaktioner.
3. Beräkna totala kostnaden.
4. Hur mycket är en viss person skyldig?
5. Hur mycket ligger en viss person ute med?
6. Lista alla personer mm och FIXA!

Menyval: 6

Eva ligger ute med 600, är skyldig 100 och ska ha 500 från potten.
Bosse ligger ute med 100, är skyldig 600 och ska betala 500 till potten.

==============================================
Testdata 3 (Bonus):
==============================================
$ ./uppg6A_ThNo
*************Välj i menyn nedan*************

0. Avsluta. Alla transaktioner sparas på fil.
1. Läs in en transaktion från tangentbordet.
2. Skriv ut information om alla transaktioner.
3. Beräkna totala kostnaden.
4. Hur mycket är en viss person skyldig?
5. Hur mycket ligger en viss person ute med?
6. Lista alla personer mm och FIXA!

Menyval: 1
080606
transp
Stina
8000
5
Eva Bosse Kristin Paul Torsten
*************Välj i menyn nedan*************

0. Avsluta. Alla transaktioner sparas på fil.
1. Läs in en transaktion från tangentbordet.
2. Skriv ut information om alla transaktioner.
3. Beräkna totala kostnaden.
4. Hur mycket är en viss person skyldig?
5. Hur mycket ligger en viss person ute med?
6. Lista alla personer mm och FIXA!

Menyval: 2

Skriver info om samtliga transaktioner:
050615	transp	Eva	6000	5	Bosse	Kristin	Paul	Torsten	Stina
050721	mat	Eva	300	2	Bosse	Kristin
050721	mat	Paul	400	2	Torsten	Stina
050721	transp	Bosse	5000	3	Eva	Kristin	Paul
050721	transp	Stina	5000	1	Torsten
050722	boende	Kristin	200	1	Eva
050722	mat	Eva	300	2	Kristin	Bosse
050723	mat	Torsten	300	2	Paul	Stina
050724	mat	Paul	200	1	Stina
050725	transp	Eva	600	3	Bosse	Kristin	Paul
080606	transp	Stina	8000	5	Eva	Bosse	Kristin	Paul	Torsten

*************Välj i menyn nedan*************

0. Avsluta. Alla transaktioner sparas på fil.
1. Läs in en transaktion från tangentbordet.
2. Skriv ut information om alla transaktioner.
3. Beräkna totala kostnaden.
4. Hur mycket är en viss person skyldig?
5. Hur mycket ligger en viss person ute med?
6. Lista alla personer mm och FIXA!

Menyval: 0

Programmet avslutas. Nya transaktioner skrivs till fil.

==============================================
Innehållet i resa.txt efter programkörning 3
==============================================

$ cat resa.txt
050615  transp  Eva     6000    5       Bosse   Kristin Paul    Torsten Stina
050721  mat     Eva     300     2       Bosse   Kristin
050721  mat     Paul    400     2       Torsten Stina
050721  transp  Bosse   5000    3       Eva     Kristin  Paul
050721  transp  Stina   5000    1       Torsten
050722  boende  Kristin 200     1       Eva
050722  mat     Eva     300     2       Kristin Bosse
050723  mat     Torsten 300     2       Paul    Stina
050724  mat     Paul    200     1       Stina
050725  transp  Eva     600     3       Bosse   Kristin Paul
080606	transp	Stina	8000	5	Eva	Bosse	Kristin	Paul	Torsten

================================================================================
Rapport om uppgiften:
==============================================

Uppgiften går ut på att konstruera ett program som beräknar en aktivitets
deltagares utlägg, skulder och betalningsskyldighet.

Det svåraste i uppgiften var att komma igång. Innan poletten trillade ned så att
säga. När jag väl var underförstådd med principen om objekt uppstod ingen större
problematik på vägen.

PersonLista TransaktionsLista::FixaPersoner() var den klurigaste funktionen att få
att fungera korrekt.

Problemlösningsmetoden jag använt mig av har varit att skriva de viktigaste
metoderna för den första funktionen, sen den andra funktionen osv. Jag har använt
mig av en del pseudokod samt ett enkelt huvudprogram utan meny tills alla metoder
var på plats.
*/
