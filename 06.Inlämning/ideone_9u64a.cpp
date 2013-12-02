#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//GLOBAL CONSTANTS
const int MAX_KOMPISAR = 10;
const int MAX_TRANSAKTIONER = 11;
const int MAX_PERSONER = 10;

 class Person
 {
 private:
   string namn;
   double betalat_andras;   // ligger ute med totalt
   double skyldig;          // skyldig totalt

 public:
   Person();
   ~Person();
   Person( string n, double b, double s );
   double haemta_betalat();
   double haemta_skyldig();
   string haemta_namn();
   void skrivUt();
 };

 class PersonLista
 {
 private:
   int antal_pers;
   Person pers[MAX_PERSONER];

 public:
   PersonLista();
   ~PersonLista();
   void laggTillEn( Person pny );
   void skrivUtOchFixa();
   double summaSkyldig();
   double summaBetalat();
   bool finns(string namn);
 };
//Class Transaktion's aim is to save information of one "receipt". Transaktion will be used by class TransaktionsLista.
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
        Transaktion(string inDatum, string inTyp, string inNamn, double inBelopp, int inAnt_kompisar, string inKompisNamnen[]);
        ~Transaktion();
        string haemta_namn();
        double haemta_belopp();
        int haemta_ant_kompisar();
        //bool finnsKompis(string namnet);
        bool laesEnTrans(istream &is);
        void skrivEnTrans(ostream &os);
        double haemta_skyldig(string persNamn);
};

//Class TransaktionsLista stores all the transactions (class Transaktion) and does the number crushing.
class TransaktionsLista
{
 private:
   Transaktion trans[MAX_TRANSAKTIONER];
   Transaktion nyTrans;
   int antalTrans;

 public:
   TransaktionsLista();
   ~TransaktionsLista();
   void laesin( istream &is );
   void skrivut( ostream &os );
   void laggTill( Transaktion & nyTrans );
   double totalkostnad();
   double liggerUteMed( string namnet );
   double aerSkyldig( string namnet );
   PersonLista FixaPersoner();
 };

int main()
{

    Transaktion nyTrans;

    TransaktionsLista nyTransLista;
    PersonLista nyPersLista;

    ifstream transFile_in("inkvitto.txt");
    nyTransLista.laesin(transFile_in);

    nyPersLista = nyTransLista.FixaPersoner();

    nyPersLista.skrivUtOchFixa();

    cout << "Summa till potten: " << nyPersLista.summaBetalat() << " och summa fran potten: " << nyPersLista.summaSkyldig() << endl;

    ofstream transFile_out("utkvitto.txt");
    nyTransLista.skrivut(transFile_out);

return 0;
}

//CLASS Person

//Standard Constructor for Person
Person::Person()
{
    namn = "";
    betalat_andras = 0.0;   // ligger ute med totalt
    skyldig = 0.0;          // skyldig totalt
}

//Overloaded Constructor for Person
Person::Person(string n, double b, double s)
{
namn = n;
betalat_andras = b;
skyldig = s;
}

//Destructor for Person
Person::~Person()
{
}

void Person::skrivUt()
{
    if(betalat_andras > skyldig)
        cout << namn << " har betalat " << betalat_andras << " och ar skyldig " << skyldig << ". Skall ha " << betalat_andras - skyldig << " fran potten!" << endl;
    else
        cout << namn << " har betalat " << betalat_andras << " och ar skyldig " << skyldig << ". Skall lagga " << skyldig - betalat_andras << " till potten!" << endl;
}

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
//CLASS PersonLista

//Standard Constructor for PersonLista
PersonLista::PersonLista()
{
   antal_pers = 0;
}

//Destructor for PersonLista
PersonLista::~PersonLista()
{
}

void PersonLista::laggTillEn(Person pny)
{
    pers[antal_pers] = pny;
    antal_pers++;
}

void PersonLista::skrivUtOchFixa()
{
    for (int i = 0; i < antal_pers; i++)
        pers[i].skrivUt();
}

double PersonLista::summaSkyldig()
{
    double skuldSaldo = 0.0;

    for (int i = 0; i < antal_pers; i++)
        skuldSaldo = skuldSaldo + pers[i].haemta_skyldig();

return skuldSaldo;
}

double PersonLista::summaBetalat()
{
    double betalatSaldo = 0.0;

    for (int i = 0; i < antal_pers; i++)
        betalatSaldo = betalatSaldo + pers[i].haemta_betalat();

return betalatSaldo;
}

bool PersonLista::finns(string namn)
{
    string namnet = namn;
    for(int i = 0; i < MAX_PERSONER; i++)
    {
        if (pers[i].haemta_namn() == namnet)
            return true;
    }

    return false;
}
//CLASS Transaktion

//Standard Constructor for Transaktion
Transaktion::Transaktion()
{
    datum = "";
    typ = "";
    namn = "";
    belopp = 0.0;
    ant_kompisar = 0;

    for (int i=0; i < MAX_KOMPISAR; i++)
        kompisar[i] = "";
}

//Overloaded Constructor for Transaktion
Transaktion::Transaktion(string inDatum, string inTyp, string inNamn, double inBelopp, int inAnt_kompisar, string inKompisNamnen[])
{
    datum = inDatum;
    typ = inTyp;
    namn = inNamn;
    belopp = inBelopp;
    ant_kompisar = inAnt_kompisar;

    for(int i = 0; i < ant_kompisar; i++)
    {
        kompisar[i] = inKompisNamnen[i];
    }
}

//Destructor for Transaktion
Transaktion::~Transaktion()
{
}

//Getter for Transaktion - namn
string Transaktion::haemta_namn()
{
    return namn;
}

//Getter for Transaktion - belopp
double Transaktion::haemta_belopp()
{
    return belopp;
}

//Getter for Transaktion - ant_kompisar
int Transaktion::haemta_ant_kompisar()
{
    return ant_kompisar;
}

//Transaktion::laesEnTrans reads transactions from a txt-file
bool Transaktion::laesEnTrans(istream &is)
{
    //Take an istream from a txt-file and read them into the object
    is >> datum >> typ >> namn  >> belopp >> ant_kompisar;

    //Friends that were the 'receiving part' in the transaction are listed last on a row in the file, so this
    //code snippet takes the information of how many friends were involved and read the correct amount of strings
    //from the end of the row and saves them into an array inside an object of Transaktion-class
    string kompisNamn;
    for(int i = 0; i < ant_kompisar; i++)
    {
        is >> kompisNamn;
        kompisar[i] = kompisNamn;
    }

return is;
}

void Transaktion::skrivEnTrans(ostream &os)
{
    os << datum << "\t"  << typ << "\t" << namn << "\t" << belopp << "\t" << ant_kompisar << "\t";

    for(int i=0; i < ant_kompisar; i++)
        os << kompisar[i] << "\t";

    os << endl;
}

double Transaktion::haemta_skyldig(string persNamn)
{
    double skuld = 0.0;

    for(int i = 0; i < ant_kompisar; i++)
    {
        if(kompisar[i] == persNamn)
            skuld = belopp / (ant_kompisar+1);
    }

    return skuld;
}

//Class TransaktionsLista

//Standard Constructor
TransaktionsLista::TransaktionsLista()
{
    antalTrans = 0;
}

//Destructor for TransaktionsLista
TransaktionsLista::~TransaktionsLista()
{
}

void TransaktionsLista::laggTill(Transaktion & nyTrans)
{
    trans[antalTrans] = nyTrans;
    antalTrans++;
}

void TransaktionsLista::laesin(istream &is)
{
    while (nyTrans.laesEnTrans(is))
        laggTill(nyTrans);
}

void TransaktionsLista::skrivut(ostream &os)
{
        //antalTrans-1 is a correction for the fact that laesIn doesn't return EOF (is=false) before it's one line too late :D
        //This might be a reaaaaally bad way to correct for it, but it seems to work in this context and inkvitto.txt and utkvitto.txt match so far
        for(int i = 0; i <= antalTrans-1; i++)
        {
            trans[i].skrivEnTrans(os);
        }

}

double TransaktionsLista::totalkostnad()
{
    double totalKostnad = 0.0;
    for (int i = 0; i < antalTrans; i++)
        totalKostnad = totalKostnad + trans[i].haemta_belopp();

    return totalKostnad;
}

double TransaktionsLista::liggerUteMed( string namnet )
{
    double liggerUte = 0.0;

    for(int i = 0; i < antalTrans; i++)
        {
            if(trans[i].haemta_namn() == namnet)
                //Person also paid for his/herself, so belopp has to be divided with amount friends marked to be involved
                //in the transaction plus one. That's what this monstrosity of expression does.
                liggerUte = liggerUte + (trans[i].haemta_belopp() - (trans[i].haemta_belopp() / (trans[i].haemta_ant_kompisar() + 1)));
        }

    return liggerUte;
}

double TransaktionsLista::aerSkyldig(string namnet)
{
    double skuldsaldo = 0.0;

    for(int i = 0; i < antalTrans; i++)
        skuldsaldo = skuldsaldo + trans[i].haemta_skyldig(namnet);

    return skuldsaldo;
}

PersonLista TransaktionsLista::FixaPersoner()
{
    PersonLista nyPersLista;
    string inPersNamn;
    double inPersSkyldig;
    double inPersLiggerUte;

    for (int i = 0; i < antalTrans; i++)
    {
        if(!nyPersLista.finns(trans[i].haemta_namn()))
        {
            inPersNamn = trans[i].haemta_namn();
            inPersSkyldig =+ aerSkyldig(inPersNamn);
            inPersLiggerUte =+ liggerUteMed(inPersNamn);

            Person nyPers(inPersNamn, inPersLiggerUte, inPersSkyldig);
            nyPersLista.laggTillEn(nyPers);
        }
    }

    return nyPersLista;
}
