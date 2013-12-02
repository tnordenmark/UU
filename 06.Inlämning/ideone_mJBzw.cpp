#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const int MAX_KOMPISAR = 20 ;       
const int MAX_TRANSAKTIONER = 50 ;  

class Transaktion
{
private:
	string datum ;                     
	string typ ;                       
	string namn ;                      
	double belopp ;                    
	int ant_kompisar ;                 
	string kompisar [MAX_KOMPISAR] ;   
public:
	Transaktion() ;                    
	~Transaktion() ;                  
	string haemta_namn () ;          
	double haemta_belopp () ;       
	int haemta_ant_kompisar () ;       
	bool finnsKompis ( string namnet ) ; 
	bool laesEnTrans ( istream &is) ;  
	void skrivEnTrans ( ostream &os ) ; 
};

class TransaktionsLista
{
private:
	Transaktion trans[MAX_TRANSAKTIONER] ; 
	int antalTrans ;                      
public:
	TransaktionsLista () ;                  
	~TransaktionsLista () ;                
	void laesin ( istream &is ) ;          
	void skrivut ( ostream &os ) ;          
	void laeggTill ( Transaktion &t ) ;     
	double totalkostnad ( int belopp ) ;  
	double liggerUteMed ( string namnet ) ; 
	double aerSkyldig ( string namnet ) ;   };
	// ==================================================================

	//Funktionsdeklaration
	int printInstruction();
	
	int main()
	{
		Transaktion nyTrans;
		int menyVal, antal = 0;
		bool x;

		ifstream is("resa.txt");

		// Skriv ut instruktioner
		menyVal = printInstruction();

		switch(menyVal) {

		case 0:
			break;
		case 1: 
				x = nyTrans.laesEnTrans(is);
			break;
		case 2: 
				// skrivUt();
		default:
			break;
		}



	}
	// ==================================================================

	int printInstruction()
	{
		int x;
		string textRad;

		ifstream fil("instruktion.txt", ifstream::in);
		while(!fil.eof())
		{
			getline(fil, textRad);
			cout << textRad << endl;
		}

		fil.close();
		cin >> x;
		if(!(x < 0 || x > 6))
		{
			return x;
		} else { printInstruction(); }

	}

	Transaktion::Transaktion ()
	{
		datum = "" ;
		typ = "" ;
		namn = "" ;
		belopp = 0.0 ;
		ant_kompisar = 0 ;
		{
			for ( int i = 0; i < ant_kompisar; i++ )
				kompisar[i] ;
		}
	}
	// ------------------------------------------------------------------
	Transaktion::~Transaktion ()
	{ }
	// ------------------------------------------------------------------
	string Transaktion::haemta_namn ()
	{
		return namn ;
	}
	// ------------------------------------------------------------------
	double Transaktion::haemta_belopp ()
	{
		return belopp ;
	}
	// ------------------------------------------------------------------
	int Transaktion::haemta_ant_kompisar ()
	{
		return ant_kompisar ;
	}
	// ------------------------------------------------------------------
	bool Transaktion::finnsKompis ( string namnet )
	{

		return false ;
	}
	// ------------------------------------------------------------------
	bool Transaktion::laesEnTrans (istream &is)
	{   

		// Fråga efter uppgifter
		cout << "Skriv in transaktionesuppgifter: " << endl;
		cout << "Datum: "; cin >> datum;
		cout << "Typ: "; cin >> typ;
		cout << "Namn: "; cin >> namn;
		cout << "Belopp: "; cin >> belopp;
		cout << "Antal komisar: "; cin >> ant_kompisar;
		cout << "Medverkande kompisar(Seperera med knapptryck Enter): " << endl;
		for(int i = 0; i < ant_kompisar; i++)
		{
			cin >> kompisar[i];
		}

		// Skriv till fil
		is << datum << typ <<  namn <<  belopp << ant_kompisar;
		for(int i = 0; i < ant_kompisar; i++)
		{
			is << kompisar[i];
		}

		// Om filen inte existerar
		if(!is)
		{
			cout << "File could not be opened!" << endl;
			return false;
		}

		return true;

	}
	// ------------------------------------------------------------------
	void Transaktion::skrivEnTrans ( ostream &os )
	{

	}