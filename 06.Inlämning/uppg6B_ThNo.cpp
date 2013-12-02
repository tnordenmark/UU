/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: VT/2013

Inlämningsuppgift nr: 6B

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

Jag har arbetat ungefär 6 timmar med denna uppgift

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
    Person *pers;

public:
    PersonLista();
    PersonLista(const PersonLista &p);
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
    string *kompisar;

public:
    Transaktion();
    ~Transaktion();
    Transaktion& operator=(const Transaktion &t);
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
    Transaktion *trans;
    int antalTrans;
    Transaktion t;

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

//---Deklaration av externa funktioner---
void huvudMeny(TransaktionsLista &tlista, PersonLista &perslista);
void visaMeny();
int menyVal();

//---Huvudprogram---
int main()
{
    // Skapa objekt
    TransaktionsLista tlista;
    PersonLista perslista;

    // Skapa och öppna infilsobjekt
    ifstream infil("resa.txt");
    // Börja med att läsa in alla data från infil
    tlista.laesin(infil);
    // Stäng infil
    infil.close();

    // Visa huvudmenyn
    huvudMeny(tlista, perslista);

    return 0;
}

//---Definition av externa funktioner---
// Funktion för att hantera huvudmenyn
void huvudMeny(TransaktionsLista &tlista, PersonLista &perslista)
{
    // Skapa objekt
    Transaktion t;
    Person pers;

    // Deklarera variabler
    string namnet; // Personnamn för att hämta skuld, utlägg mm
    int menyval = -1; // Menyvalet
    
    // Skapa infilsobjektet
    ifstream infil("resa.txt");
    // Öppna utfilsobjektet
    ofstream utfil("resa.txt");

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
                tlista.skrivut(utfil);
                utfil.close();
                break;
            case 1: // Läs transaktion från tangentbord
                cout << "Mata in datum, typ, betalarens namn, belopp, antal och";
                cout << " deltagares namn " << endl;
                cout << "en på varje rad." << endl;
                t.laesEnTrans(cin);
                tlista.laggTill(t);
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
                cout << "Summerar och beräknar slutresultatet: " << endl;
                perslista = tlista.FixaPersoner();
                //cout << endl;
                perslista.skrivUtOchFixa();
                cout << endl;
                break;
        }
    }
}

// Visa grafiken för huvudmenyn
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
    pers = 0;
}

// Destruktor
PersonLista::~PersonLista()
{
    delete[] pers;
    pers = 0;
}

PersonLista::PersonLista(const PersonLista &p)
    :   antal_pers(p.antal_pers)
{
    if(antal_pers > 0)
    {
        pers = new Person[antal_pers];
        
        for(int i = 0; i < antal_pers; i++)
        {
            pers[i] = p.pers[i];
	}
    }
    else
    {
        pers = 0;
    }
}

// Lägger till en ny person till arrayen pers[]
void PersonLista::laggTillEn(Person pny)
{
    Person *temp_pers = 0;
    temp_pers = new Person[antal_pers +1];

    for(int i = 0; i < antal_pers; i++)
    {
        temp_pers[i] = pers[i];
    }
    
    delete[] pers;

    pers = temp_pers;
    antal_pers++;
    pers[antal_pers -1] = pny;
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
    for(int i = 0; i < antal_pers; i++)
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
    kompisar = 0;
}

Transaktion& Transaktion::operator=(const Transaktion& t)
{
    if (this != &t)
    {
        delete[] kompisar;
        datum = t.datum;
        typ = t.typ;
        namn = t.namn;
        belopp = t.belopp;
        ant_kompisar = t.ant_kompisar;
        kompisar = new string[ant_kompisar];
        for (int i=0; i < ant_kompisar; i++)
        {
            kompisar[i] = t.kompisar[i];
        }
    }

    return *this;
}

// Destruktor
Transaktion::~Transaktion()
{
    delete[] kompisar;
    kompisar = 0;
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
            skuld = belopp / (ant_kompisar +1);
        }
    }

    return skuld;
}

// Returnerar true om namnet finns i arrayen kompisar
bool Transaktion::finnsKompis(string namnet)
{
    for(int i = 0; i < ant_kompisar; i++)
    {
        if(namnet == kompisar[i])
        {
            return true;
        }
    }

    return false;
}

// Läser en transaktion
bool Transaktion::laesEnTrans(istream &is)
{
    delete[] kompisar;

    is >> datum >> typ >> namn >> belopp >> ant_kompisar;

    kompisar = new string[ant_kompisar];

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
    {
        os << kompisar[i] << "\t";
    }

    os << endl;
}

//---Metoder i klassen TransaktionsLista---
// Konstruktor
TransaktionsLista::TransaktionsLista()
{
    antalTrans = 0;
    trans = 0;
}

// Destruktor
TransaktionsLista::~TransaktionsLista()
{
    cout << "Nu körs ~TransaktionsLista" << endl;
    delete[] trans;
    trans = 0;
}

// Använder Transaktion::laesEnTrans och TransaktionsLista::laggTill för att läsa
// in data till arrayen trans[]
void TransaktionsLista::laesin(istream &is)
{
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
    Transaktion *temp_trans = 0;
    temp_trans = new Transaktion[antalTrans +1];

    for(int i = 0; i < antalTrans; i++)
    {
        temp_trans[i] = trans[i];
    }
    
    delete[] trans;

    trans = temp_trans;
    antalTrans++;
    trans[antalTrans -1] = t;
}

// Summerar aktivitetens totala kostnader
double TransaktionsLista::totalkostnad()
{
    double totalkostnad = 0.0;

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
        {
            betalat += (trans[i].haemta_belopp() - (trans[i].haemta_belopp() / (trans[i].haemta_ant_kompisar() + 1)));
        }
    }
    
    return betalat;
}

// Beräknar hur mycket en given person är skyldig
double TransaktionsLista::aerSkyldig(string namnet)
{
    double skyldig = 0.0;
    
    for(int i = 0; i < antalTrans; i++) 
    {
        skyldig += trans[i].haemta_skyldig(namnet);
    }
    
    return skyldig;
}

// Skapar ett PersonListe-objekt med data om en persons transaktioner
PersonLista TransaktionsLista::FixaPersoner()
{
    PersonLista perslista = PersonLista();
    string persnamn = "";

    for(int i = 0; i < antalTrans; i++)
    {
        if(!perslista.finnsNamn(trans[i].haemta_namn()))
        {
            persnamn = trans[i].haemta_namn();
            Person nypers = Person(persnamn, liggerUteMed(persnamn), aerSkyldig(persnamn));
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

$ ./uppg6B_ThNo
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

==============================================
Testdata 2:
==============================================

$ ./uppg6B_ThNo
*************Välj i menyn nedan*************

0. Avsluta. Alla transaktioner sparas på fil.
1. Läs in en transaktion från tangentbordet.
2. Skriv ut information om alla transaktioner.
3. Beräkna totala kostnaden.
4. Hur mycket är en viss person skyldig?
5. Hur mycket ligger en viss person ute med?
6. Lista alla personer mm och FIXA!

Menyval: 6
Summerar och beräknar slutresultatet:

Eva ligger ute med 5850, är skyldig 1350 och ska ha 4500 från potten.
Paul ligger ute med 367, är skyldig 2500 och ska betala 2133 till potten.
Bosse ligger ute med 3750, är skyldig 1350 och ska ha 2400 från potten.
Stina ligger ute med 2500, är skyldig 1333 och ska ha 1167 från potten.
Kristin ligger ute med 100, är skyldig 2600 och ska betala 2500 till potten.
Torsten ligger ute med 200, är skyldig 3633 och ska betala 3433 till potten.

==============================================
Testdata 3 (Bonus):
==============================================

 *************Välj i menyn nedan*************

0. Avsluta. Alla transaktioner sparas på fil.
1. Läs in en transaktion från tangentbordet.
2. Skriv ut information om alla transaktioner.
3. Beräkna totala kostnaden.
4. Hur mycket är en viss person skyldig?
5. Hur mycket ligger en viss person ute med?
6. Lista alla personer mm och FIXA!

Menyval: 1
Mata in datum, typ, betalarens namn, belopp, antal och deltagares namn
en på varje rad.
080606
transp
Bosse
8000
3
Eva Kristin Paul
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
080606	transp	Bosse	8000	3	Eva	Kristin	Paul

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
080606	transp	Bosse	8000	3	Eva	Kristin	Paul

================================================================================
Rapport om uppgiften:
==============================================

Uppgiften går ut på att konstruera ett program som beräknar en aktivitets
deltagares utlägg, skulder och betalningsskyldighet. Den här gången med hjälp
av dynamiska arrayer.

Det klurigaste i den här uppgiften var i vanlig ordning funktionen FixaPersoner()
som jag fick arbeta några timmar med att få till på nytt. Andra klurigheter var
att skriva om funktionerna för dynamiska arrayer samt att jag gick vilse bland
destruktorerna ett tag och gjorde det för komplicerat för mig.
Jag har även varit tvungen att möblera om lite i programmet, flytta några
funktionsdeklarationer samt ändrat upplägg på huvudmenyn för att få det att
fungera. Hade säkert gått bra med ungefär samma struktur som innan men passade på
att rensa i huvudprogrammet lite.

Problemlösningsmetoden jag använt mig av har varit att metodiskt arbeta av
metod för metod. När väl den första metoden fungerade var de andra betydligt
enklare att få att fungera. Åter igen är det poletten som ska trilla ned.

================================================================================
Uppgiftens frågor:
==============================================

Varför behövs tilldelningsoperatorn i klassen Transaktion och exakt när i din kod
används den?

Jag är inte 100% säker på den här frågan men jag tror att tilldelningsoperatorn
krävs för s.k djupkopiering eller deep copy. Den används då objekts attribut ska
kopieras in i en dynamisk array. Om ingen tilldelningsoperator fanns skulle
i vissa fall destruktorn kunna försöka ta bort objekt som en annan destruktor
redan avallokerat med minneskorrumpering som resultat.


Vad betyder "if (this != &t)" i tilldelningsoperatorn?

Jag misstänker att det betyder "om aktuell pekaradress inte är
lika med Transaktionsobjektetparameterns minnesadress". Även här är jag inte helt
säker.
*/
