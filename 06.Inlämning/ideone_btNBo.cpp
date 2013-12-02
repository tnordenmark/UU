#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// GLOBALA VARIABLER
const int MAX_KOMPISAR = 10;
const int MAX_TRANSAKTIONER = 25;
const int MAX_PERSONER = 10;

// CLASS PERSON
class Person
{
private:
	string namn;
	double betalat_andras; 
	double skyldig;

public:
	Person();
	Person( string n, double b, double s );
	~Person();
	double haemta_betalat();
	double haemta_skyldig();
	string haemta_namn();
	void skrivUt();
}; 

// CLASS PERSONLIST
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
	bool finns(string & name);
}; 

// CLASS TRANSAKTION
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

// CLASS TRANSAKTIONSLISTA
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

	// Funktionsdeklarationer

	/* Funktionen haemta_varden gör nästan ALLT.
	Utifrån användarens val så körs en switch som 
	bestämmer vilka anrop som ska utföras.
	Använder sig av haemtyMenyVal. Samt den håller mainprogrammet rent */
	void haemta_varden( Transaktion &nyTrans,
		TransaktionsLista & nyTransLista, 
		Person & pers, 
		PersonLista & persList, 
		Transaktion trans[MAX_TRANSAKTIONER]);

	// Funktionen haemtaMenyVal hanterar meny- & val.
	int haemtaMenyVal();


	/////////////////////////////////////////
	///////////// HUVUDPROGRAM///////////////
	/////////////////////////////////////////


	int main()
	{
		Transaktion nyTrans; // Skapa objekt
		TransaktionsLista nyTransLista; // Skapa objekt
		Person pers; // Skapa objekt
		PersonLista persList; // Skapa objekt
		Transaktion trans[MAX_TRANSAKTIONER];

		
		ifstream readInTrans("resa.txt");     
		nyTransLista.laesin(readInTrans); // Läs in transaktioner
		readInTrans.close();

		// haemta_varden sköter menyval samt alla anrop
		haemta_varden(nyTrans, 
			nyTransLista, 
			pers, 
			persList, 
			trans);
		// haemta_varden slut

		return 0;

	}


	// Funktionsdefinitioner

	// Funktionen haemtaMenyVal skriver ut meny och skickar tillbaka
	// användarens menyval.
	int haemtaMenyVal() 
	{

		int val = 0;
		ifstream rf("instruktion.txt");
		if(!rf) // Filen hittades inte
		{
			cout << "Could not open file!" << endl;
			exit(1);
		}

		string line;
		while( getline(rf, line) )
		{
			cout << line << endl; // Skriv ut innehållet
		}

		cin >> val;
		if(!(val < 0 || val > 6))
		{
			return val;
		}

		return 0;

	}

	// Funktionen haemta_varden
	// Utifrån användarens menyval så körs en switch som 
	// bestämmer vilka anrop som ska utföras.
	void haemta_varden(Transaktion &nyTrans,
		TransaktionsLista & nyTransLista, Person & pers, PersonLista & persList, 
		Transaktion trans[MAX_TRANSAKTIONER])
	{

		string personNamn;
		int menyVal = -1, 
			antalNya = 0,	// räknar nya transaktioner denna session
			antalRader = 0; // räknar gamla transaktioner sparade på fil


		/* ofstream behöver inte deklarerars i main, inte heller den ifstream som används
		   endast i funktionen haemta_varden */
		ifstream is("resa.txt");				// skicka ny fil till haemta_varden
		ofstream os("resa.txt", ios_base::app); // app flaggan(append) kör inte över innehållet.

		while (nyTrans.laesEnTrans (is)) // Räkna antalet rader(Transaktioner) i textfil
		{
			antalRader++; 
		}

		while(menyVal != 0) // Sålänge menyvalet inte är 0
		{

			menyVal = haemtaMenyVal(); // Hämtar menyvalet & skriver ut menyn

			switch(menyVal)
			{
			case 0: // Fall noll - skriv transaktioner till fil

				for(int i = 0; i < antalNya; i++)
				{
					trans[i].skrivEnTrans(os);
				}

				break;
			case 1: // Fall ett - låt användaren mata in transaktion

				nyTrans.laesEnTrans (cin);
				nyTransLista.laeggTill(nyTrans);
				trans[antalNya] = nyTrans;
				antalNya++;

				break;
			case 2: // Fall två - lista alla transaktioner

				if(antalRader != 0)
				{
					cout << "\n" << "Listing all transactions (" << antalRader + antalNya << "): " << endl;
					nyTransLista.skrivut(cout);
				}
				else	// ingen transaktion hittades
				{		cout << "No transactions found." << endl;	}

				break;
			case 3: // Fall tre - skriver ut totala kostnaden/skulden

				cout << "\n" << "The total debt is: " << nyTransLista.totalkostnad() << " SEK." << endl;

				break;
			case 4: // Fall fyra - hur mycket är en viss person skyldig?

				cout << "Enter person name: " << endl;
				cin >> personNamn;
				cout << personNamn << " owes " 
					<< nyTransLista.aerSkyldig(personNamn) << " SEK." << endl;

				break;
			case 5: // Fall fem - hur mycket är en viss person ute med?

				cout << "Enter person name: " << endl;
				cin >> personNamn;
				cout << personNamn << " is out with "
					<< nyTransLista.liggerUteMed(personNamn) << " SEK." << "\n" << endl;

				break;
			case 6: // Fall sex - Lista alla personer, vilka som ska ge eller ta från potten!
				
				if(antalRader != 0)
				{
					persList = nyTransLista.FixaPersoner();
					persList.skrivUtOchFixa();
				} else { cout << "No transactions found." << endl; }

				break;
				
			}
		}

	}

	/////////////////////////////////////////
	///// TRANSAKTION MEDLEMSFUNKTIONER /////
	/////////////////////////////////////////


	Transaktion::Transaktion ()
	{

		datum = "";
		namn = "";
		typ = "";
		belopp = 0.0;
		ant_kompisar = 0;

	}

	Transaktion::Transaktion(const Transaktion & t)
		: datum(t.datum), typ(t.typ), namn(t.namn),
		belopp(t.belopp), ant_kompisar(t.ant_kompisar)
	{

		if(ant_kompisar > 0)
		{
			kompisar = new string[ant_kompisar]; // Allkolera nytt minne
			for(int i = 0; i < ant_kompisar; i++)
			{
				kompisar[i] = t.kompisar[i];
			}
		} else {

			kompisar = 0; // NULL

		}

	}

	Transaktion::~Transaktion ()
	{
		delete[] kompisar;
		kompisar = 0;
	}

	string Transaktion::haemta_namn ()
	{
		return namn;
	}

	double Transaktion::haemta_belopp ()
	{
		return belopp;
	}

	// Funktionen haemta_personSkuld(string persNamn) hämtar en persons
	// aktuella skuld. Denna funktion är viktig för TransaktionsLista::aerSkyldig
	// och framförallt för slutresultatet.
	double Transaktion::haemta_personSkuld(string persNamn)
	{
		double persSkuld = 0.0;

		for(int i = 0; i < ant_kompisar; i++)
		{
			if(kompisar[i] == persNamn)
			{
				// Farligt läge om ant_kompisar = 0, addera alltid med 1.
				persSkuld = (belopp / (ant_kompisar+1));
			}
		}

		return persSkuld;
	}

	int Transaktion::haemta_ant_kompisar ()
	{
		return ant_kompisar;
	}

	bool Transaktion::finnsKompis ( string persNamn )
	{

		for ( int i = 0; i < MAX_KOMPISAR; i++ ) 
		{
			if ( persNamn == kompisar[i] ) 
			{
				return true; // Person hittad i kompislistan
			}
		}

		return false;
	}

	bool Transaktion::laesEnTrans ( istream &is )
	{   
		
		is >> datum // Läs in transaktioner från resa.txt
		   >> typ 
		   >> namn 
		   >> belopp 
		   >> ant_kompisar;

		string s; // skräpsträng
		kompisar = new string[ant_kompisar];

		for ( int i = 0; i < ant_kompisar; i++ )
		{
			is >> s;
			kompisar[i] = s;     
		}

		return is;
	}

	void Transaktion::skrivEnTrans ( ostream &os )
	{
	
		os  << datum << "\t" // Skriv nya transaktioner till resa.txt
			<< typ << "\t"
			<< namn << "\t"
			<< belopp << "\t" 
			<< ant_kompisar;

		for ( int i = 0; i < ant_kompisar; i++ )
		{
			os << " " << kompisar[i];
		}
		os << endl ;

	}



	/////////////////////////////////////////
	// TRANSAKTIONSLISTA MEDLEMSFUNKTIONER //
	/////////////////////////////////////////



	TransaktionsLista::TransaktionsLista ()
	{
		antalTrans = 0;
	}

	TransaktionsLista::~TransaktionsLista ()
	{	
		delete[] trans;
		trans = 0;
	}

	void TransaktionsLista::laeggTill ( Transaktion &t )
	{

		int i = 0;
		Transaktion *temp; 
		temp = new Transaktion[antalTrans+1]; 
		for (i = 0; i < antalTrans; i++) /* Om trans ar 0 gar vi inte in i loopen */ 
		{ 
			temp[i] = trans[i]; 
		} 

		if(antalTrans > 0)
		{
			delete [] trans;
		}

		trans[antalTrans] = t; 
		trans = temp; 
		antalTrans++; 

	}

	void TransaktionsLista::laesin ( istream &is )
	{

		while (t.laesEnTrans(is))
		{ 
			laeggTill(t);
		}

	}

	void TransaktionsLista::skrivut ( ostream &os)
	{

		for(int i = 0; i < antalTrans; i++)
		{
			trans[i].skrivEnTrans(os);
		}

	}

	double TransaktionsLista::totalkostnad ()
	{
		double totalkostnad = 0.0;
		for(int i = 0; i < antalTrans; i++)
		{
			totalkostnad += trans[i].haemta_belopp();
		}

		return totalkostnad;
	}

	double TransaktionsLista::liggerUteMed ( string personName ) 
	{
		double liggerUteMedSum = 0.0;
		for(int i = 0; i < antalTrans; i++)
		{
			if(trans[i].haemta_namn() == personName)
			{
				// Farligt läge om ant_kompisar = 0, addera alltid med 1.
				liggerUteMedSum += (trans[i].haemta_belopp() - (trans[i].haemta_belopp() / (trans[i].haemta_ant_kompisar()+1)));
			}	
		}

		return liggerUteMedSum;

	}

	double TransaktionsLista::aerSkyldig(string persNamn)
	{
		double skuld = 0.0;

		for(int i = 0; i < antalTrans; i++)
		{
			skuld += trans[i].haemta_personSkuld(persNamn);
		}

		return skuld;
	}

	PersonLista TransaktionsLista::FixaPersoner()
	{

		PersonLista persList = PersonLista();
		string persNamn = "";

		for(int i = 0; i < antalTrans; i++)
		{
						
			if(!(persList.finns(trans[i].haemta_namn())))
			{

				persNamn = trans[i].haemta_namn();
				Person newPers = Person(persNamn, liggerUteMed(persNamn), aerSkyldig(persNamn));
				persList.laggTillEn(newPers);
			
			}

		}

		cout << "\n" << endl;
		return persList;

	}



	//////////////////////////////////////////
	//////// PERSON MEDLEMSFUNKTIONER/////////
	//////////////////////////////////////////



	Person::Person()
	{
		namn = "";
		skyldig = 0.0;
		betalat_andras = 0.0;

	}

	Person::Person(string n, double b, double s)
	{
		namn = n;
		betalat_andras = b;
		skyldig = s;
	}

	Person::~Person()
	{ }

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

	void Person::skrivUt()
	{

		// Eftersom 50-öringen inte längre existerar, avrunda till närmsta heltal.

		if(betalat_andras > skyldig)
		{
			cout << namn 
				<< " has payed "                       
				<< setiosflags(ios::fixed)		<<  setprecision (0)
				<< betalat_andras << ". Debt for " << namn << " is "     
				<< setiosflags(ios::fixed)		<<  setprecision (0)
				<< skyldig  << ". Should recieve "                 
				<< setiosflags(ios::fixed)		<<  setprecision (0)
				<< betalat_andras - skyldig << " from the pot." 
				<< endl;
		} 
			else
		{
			cout << namn << " has payed " 
				<< setiosflags(ios::fixed)		<<  setprecision (0)
				<< betalat_andras << ". Debt for " << namn << " is " 
				<< setiosflags(ios::fixed)		<<  setprecision (0)
				<< skyldig << ". Should contribute " 
				<< setiosflags(ios::fixed)		<<  setprecision (0) 
				<< skyldig - betalat_andras << " to the pot." 
				<< endl;
		}

	}


	///////////////////////////////////////////
	////// PERSONLISTA MEDLEMSFUNKTIONER //////
	///////////////////////////////////////////


	PersonLista::PersonLista()
	{
		antal_pers = 0;
	}

	PersonLista::~PersonLista()
	{ }

	void PersonLista::laggTillEn(Person pny)
	{

		pers[antal_pers] = pny;
		antal_pers++;
	}

	void PersonLista::skrivUtOchFixa()
	{

		for(int i = 0; i < antal_pers; i++)
		{
			pers[i].skrivUt();
		}

	}

	double PersonLista::summaBetalat()
	{

		double betalat = 0.0;

		for(int i = 0; i < antal_pers; i++)
		{
			betalat += pers[i].haemta_betalat();
		}

		return betalat;

	}

	double PersonLista::summaSkyldig()
	{

		double skyldig = 0.0;

		for(int i = 0; i < antal_pers; i++)
		{
			skyldig += pers[i].haemta_skyldig();
		}

		return skyldig;

	}

	bool PersonLista::finns(string & name)
	{

		for(int i = 0; i < MAX_PERSONER; i++)
		{
			if(pers[i].haemta_namn() == name)
			{
				return true;
			}
		}

		// Annars false
		return false;
	}