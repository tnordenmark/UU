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
        bool finnsKompis(string namnet);
        bool laesEnTrans(istream &is);
        void skrivEnTrans(ostream &os);
        string haemta_skyldiga(Transaktion trans[MAX_KOMPISAR]);
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
    /*
    //Main for reading just one transaction, not using TransaktionsLista
    ifstream transFile_in("inkvitto.txt");
    nyTrans.laesEnTrans(transFile_in);

    ofstream transFile_out("utkvitto.txt");
    nyTrans.skrivEnTrans(transFile_out);
    */

    TransaktionsLista nyTransLista;
    PersonLista nyPersLista;

    ifstream transFile_in("inkvitto.txt");
    nyTransLista.laesin(transFile_in);

    nyPersLista = nyTransLista.FixaPersoner();

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
    cout << "Person DESTROYED" << endl;
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
    cout << "PersonLista DESTROYED" << endl;
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

    cout << "Transaktion constructed" << endl;
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

    cout << "Transaktion constructed" << endl;

}

//Destructor for Transaktion
Transaktion::~Transaktion()
{
    cout << "Transaktion DESTROYED" <<endl;
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

bool Transaktion::finnsKompis(string namnet)
{
    cout << "Checking if there's new friends on the row (Transaktion::finnsKompis)" << endl;
    string kompisNamn = namnet;
    bool foundFriend = false;
    int index = 0;

    while (index < MAX_KOMPISAR && !foundFriend)
    {
        if ( kompisar[index] == kompisNamn )
        {
            foundFriend = true;
            cout << "Found new friend: " << foundFriend << " " << kompisNamn << endl;
            //cout << "kompisnamn = " << kompisNamn << " and kompisar[index] = " << kompisar[index] << endl;
        }
        else
        {
            index++;
            foundFriend = false;
            cout << "foundFriend = " << foundFriend << endl;
        }

    }

return foundFriend;
}
//Transaktion::laesEnTrans reads transactions from a txt-file
bool Transaktion::laesEnTrans(istream &is)
{
    cout << "Reading transaction" << endl << endl;

    string kompisNamn;

    //Take an istream from a txt-file and read them into the object
    is >> datum >> typ >> namn  >> belopp >> ant_kompisar;

    //Friends that were the 'receiving part' in the transaction are listed last on a row in the file, so this
    //code snippet takes the information of how many friends were involved and read the correct amount of strings
    //from the end of the row and saves them into an array inside an object of Transaktion-class
    for(int i = 0; i < ant_kompisar; i++)
    {
        is >> kompisNamn;

        //The following omitted code was here to check if the friend's already accounted for, but it's in the wrong place methinks. kompisar[i] is supposed to have all the friends anyway o_o
        //Remove it from here and put it where it belongs when you actually find it out :D
        //if (!finnsKompis(kompisNamn))
        kompisar[i] = kompisNamn;
    }

    //For debugging / understanding the program flow purposes:
    //cout << "Transaction read as follows:" << endl;
    //cout << "datum: " << datum << " namn: " << namn << " belopp: "<< belopp << " ant_kompisar: " << ant_kompisar << endl << "kompisar: ";
    //for (int a = 0; a < ant_kompisar; a++)
    //    cout << kompisar[a] << " ";

    //cout << endl << endl;

return is;
}

void Transaktion::skrivEnTrans(ostream &os)
{
    cout << "Writing transaction to file" << endl;

    os << datum << "\t"  << typ << "\t" << namn << "\t" << belopp << "\t" << ant_kompisar << "\t";

    for(int i=0; i < ant_kompisar; i++)
        os << kompisar[i] << "\t";

    os << endl;
}

string haemta_skyldiga()
{

}

//Class TransaktionsLista

//Standard Constructor
TransaktionsLista::TransaktionsLista()
{
    antalTrans = 0;
    cout << "TransakationsLista constructed" << endl;
}

//Destructor for TransaktionsLista
TransaktionsLista::~TransaktionsLista()
{
    cout << "TransaktionsLista DESTROYED" << endl;
}

void TransaktionsLista::laggTill(Transaktion & nyTrans)
{
    trans[antalTrans] = nyTrans;
    antalTrans++;
    cout << "Read " << antalTrans << " transactions" << endl;
    //antalTrans-1 is a correction for the fact that laesIn doesn't return EOF (is=false) before it's one line too late :D
    //This might be a reaaaaally bad way to correct for it, but it seems to work in this context and inkvitto.txt and utkvitto.txt match so far
    cout << "Saving in kompisar[" << antalTrans-1 << "]" << endl;
}

void TransaktionsLista::laesin(istream &is)
{
    cout << "Reading a list of transactions from istream (TransaktionsLista::laesin" << endl;
    //While a transaction-line from the file has been read, add it to the array trans. Problem here is, because of while(!EOF)
    //there's one transaction too much, namely the last line is read (and as such, saved) as double... PERKELE!
    //For the moment this is corrected in TransaktionLista::laggTill with a really awkward method.
    while (nyTrans.laesEnTrans(is))
    {
        cout << "Transaction found" << endl;
        laggTill(nyTrans);
    }


cout << "No more transactions" << endl;
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

PersonLista TransaktionsLista::FixaPersoner()
{


    cout << "Calculating Persons' transaction data" << endl;
    cout << "antalTrans = " << antalTrans << endl;

    PersonLista nyPersLista;

    //Build an array of unique friend names

    string inArrayNamn;
    string arrayUnikaNamn[MAX_KOMPISAR];
    int index_a = 0;
    int index_b = 0;
    bool redanIArrayen = false;

    for(int a = 0; a < antalTrans; a++)
    {
        inArrayNamn = trans[a].haemta_namn();
        cout << "Transaction " << a << " payer = " << inArrayNamn << endl;

        bool redanIArrayen = false;
        while(!redanIArrayen && index_a < MAX_KOMPISAR)
        {
            if(arrayUnikaNamn[index_a] == inArrayNamn)
                redanIArrayen = true;

            else
                index_a++;
        }

        //index_b placeholds where in the array the name is supposed to be put.
        //If a name is not found during the run of the while-loop, insert the name in index index_b in the array and
        //add one to index_b
        if(!redanIArrayen)
        {
            arrayUnikaNamn[index_b] = inArrayNamn;
            index_b++;
        }

        //Reset index_a to 0 to allow the while-loop to run again
        index_a = 0;
    }




return nyPersLista;
}
