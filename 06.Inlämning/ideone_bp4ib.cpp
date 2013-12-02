#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_KOMPISAR = 10;
const int MAX_TRANSAKTIONER = 25;
const int MAX_PERSONER = 10;

// CLASS TRANSACTION
class Transaktion
{
private:
	string datum ;
	string typ;
	string namn;
	double belopp;
	int ant_kompisar;
	string *kompisar;
public:
	Transaktion();
	~Transaktion();
	Transaktion(const Transaktion & t);
	string haemta_namn ();
	double haemta_belopp ();
	double haemta_personSkuld(string persNamn);
	int haemta_ant_kompisar ();
	bool finnsKompis ( string namn );
	bool laesEnTrans ( istream &is );
	void skrivEnTrans ( ostream &os );
};

// CLASS TRANSACTIONLIST
class TransaktionsLista
{
private:
	Transaktion *trans;
	Transaktion t;
	int antalTrans;
public:
	TransaktionsLista ();
	~TransaktionsLista ();
	void laesin ( istream &is );
	void skrivut ( ostream &os );
	void laeggTill ( Transaktion &t );
	double totalkostnad ();
	double liggerUteMed ( string namnet );
	double aerSkyldig ( string namnet );
	PersonLista FixaPersoner();

};

int main()
	{
		Transaktion nyTrans; // Skapa objekt
		TransaktionsLista nyTransLista; // Skapa objekt
		Person pers; // Skapa objekt
		PersonLista persList; // Skapa objekt
		Transaktion trans[MAX_TRANSAKTIONER];
		
		ifstream readInTrans("resa.txt");     
		nyTransLista.laesin(readInTrans);
		readInTrans.close();

		return 0;

	}

Transaktion::Transaktion ()
	{

		datum = ""; // date
		namn = ""; // name
		typ = ""; // type
		belopp = 0.0; // sum
		ant_kompisar = 0; // amount of friends

	}

	// Copy constructor
	Transaktion::Transaktion(const Transaktion & t)
		: datum(t.datum), typ(t.typ), namn(t.namn),
		belopp(t.belopp), ant_kompisar(t.ant_kompisar)
	{

		if(ant_kompisar > 0)
		{
			kompisar = new string[ant_kompisar]
			for(int i = 0; i < ant_kompisar; i++)
			{
				kompisar[i] = t.kompisar[i];
			}
		} else {

			kompisar = 0; // NULL

		}

	}
	// Destructor
	Transaktion::~Transaktion ()
	{
		delete[] trans;
		trans = 0;
	}

TransaktionsLista::TransaktionsLista ()
	{
		antalTrans = 0;
	}

	TransaktionsLista::~TransaktionsLista ()
	{	
		
	}

	// This kills my program
	// Function is suppose to add a new transactionobject at the last position
	// in the dynamic array trans declared at TransaktionsLista under private
	void TransaktionsLista::laeggTill ( Transaktion &t )
	{

		if(antalTrans > 0)
		{

			Transaktion *temp = 0;
			temp = new Transaktion[antalTrans+1];

			for (int i = 0; i < antalTrans; i++)
			{
				temp[i] = trans[i];
				trans[antalTrans] = t;
				delete [] trans;
				trans = temp;
				antalTrans++;
			}

		} else {

			trans = new Transaktion[1];
			trans[0] = t;
			antalTrans++;

		}

	}

// ERRORS
/*

First-chance exception at 0x0021ca58 in Uppg6.exe: 0xC0000005: Access violation writing location 0xabababab.
Unhandled exception at 0x776f15de in Uppg6.exe: 0xC0000005: Access violation writing location 0xabababab.
First-chance exception at 0x776e016e in Uppg6.exe: 0x00000000: The operation completed successfully.
Unhandled exception at 0x776f15de in Uppg6.exe: 0x00000000: The operation completed successfully.
First-chance exception at 0x776e016e in Uppg6.exe: 0x00000000: The operation completed successfully.
Unhandled exception at 0x776f15de in Uppg6.exe: 0x00000000: The operation completed successfully.

*/