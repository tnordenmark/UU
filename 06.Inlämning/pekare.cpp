#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Globala variabler
const int MAX_KOMPISAR = 10;
const int MAX_TRANSAKTIONER = 30;
const int MAX_PERSONER = 10;

class Person
{
private:
	string namn;
	double betalat_andras;
	double skyldig;

public:
	Person();
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
	Person *pers;
public:
	PersonLista();
	~PersonLista();
	PersonLista(const PersonLista &p);
	void laggTillEn( Person pny );
	void skrivUtOchFixa();
	double summaSkyldig();
	double summaBetalat();
	bool existerar(string namn);
};

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
	Transaktion& operator=( const Transaktion& t);
	string haemta_namn();
	double haemta_belopp();
	double haemta_skuld(string persNamn);
	int haemta_ant_kompisar ();
	bool finnsKompis ( string namn );
	bool laesEnTrans ( istream &is );
	void skrivEnTrans ( ostream &os );
	void laggtillkompis(string namn );
};

class TransaktionsLista
{
private:
	Transaktion *trans;
	int antalTrans;
	Transaktion t;
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

    //Funktionsdeklaration av programmets meny
	void meny(TransaktionsLista &nyTransLista,PersonLista &persList);

	int main()
	{
	    cout << "---Transaktionsprogrammet---" << endl;

	    //Skapa objekten
		TransaktionsLista nyTransLista;
		PersonLista persList;

		//Läs in filen med transaktioner
		ifstream fil("resa.txt");
		nyTransLista.laesin(fil);
		fil.close();

		//Anropa menyn
		meny(nyTransLista,persList);

		return 0;
	}

	void meny(TransaktionsLista &nyTransLista, PersonLista &persList)
	{
	    Transaktion nyTrans;
	    Person pers;
		string personNamn;
		int val = -1;

		ifstream is("resa.txt");
		ofstream os("resa.txt");

        //Menyn fortsätter att visas sålänge användaren inte matar in bokstäver eller 0
		while(val != 0)
		{
			cout << "\n0. Avsluta. Alla transaktioner sparas pa fil." << endl;
            cout << "1. Läs in en transaktion fran tangentbordet." << endl;
            cout << "2. Skriv ut information om alla transaktioner." << endl;
            cout << "3. Berakna totala kostnaden." << endl;
            cout << "4. Hur mycket ar en viss person skyldig?" << endl;
            cout << "5. Hur mycket ligger en viss person ute med?" << endl;
            cout << "6. Lista alla personer mm och FIXA!!!" << endl;

			cin >> val;

            //Programmet måste alltid avslutas genom att mata in 0, annars töms resa.txt på innehåll
			if (val == 0)
            {
                nyTransLista.skrivut(os);
            }

            if (val == 1)
            {
                cout << "\nMata in en efter en datum, utgiftstyp, betalarens namn, belopp, antal och kompisarnas namn" << endl;
                nyTrans.laesEnTrans (cin);
				nyTransLista.laeggTill(nyTrans);
            }

            if (val == 2)
            {
                nyTransLista.skrivut(cout);
            }

            if (val == 3)
            {
                cout << "\nTotal skuld: " << nyTransLista.totalkostnad() << endl;
            }

            if (val == 4)
            {
                cout << "\nAnge namn: " << endl;
				cin >> personNamn;
				cout << personNamn << " ar skyldig " << nyTransLista.aerSkyldig(personNamn) << endl;
            }

            if (val == 5)
            {
                cout << "\nAnge namn: " << endl;
				cin >> personNamn;
				cout << personNamn << " ligger ute med " << nyTransLista.liggerUteMed(personNamn) << endl;
            }

            if (val == 6)
            {
                cout << "Nu skapar vi en personarray och reder ut det hela!\n" << endl;
                persList = nyTransLista.FixaPersoner();
                persList.skrivUtOchFixa();
            }
		}
	}

	//***********************************Medlemsfunktioner transaktion**************************************

	Transaktion::Transaktion ()
	{
	    kompisar = NULL;
		datum = "";
		namn = "";
		typ = "";
		belopp = 0.0;
		ant_kompisar = 0;
	}

	Transaktion& Transaktion::operator=( const Transaktion& t)
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

	Transaktion::~Transaktion ()
	{
	    delete[] kompisar;
	}

	string Transaktion::haemta_namn ()
	{
		return namn;
	}

	double Transaktion::haemta_belopp ()
	{
		return belopp;
	}

	double Transaktion::haemta_skuld(string persNamn)
	{
		double skuld = 0.0;

		for(int i = 0; i < ant_kompisar; i++)
		{
			if(kompisar[i] == persNamn)
			{
				//Antal kompisar får inte vara 0
				skuld = belopp / (ant_kompisar+1);
			}
		}
		return skuld;
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
				return true;
			}
		}
		return false;
	}

	bool Transaktion::laesEnTrans ( istream &is )
	{
        delete[] kompisar;

		is >> datum >> typ >> namn >> belopp >> ant_kompisar;

		string strang;
		kompisar = new string[ant_kompisar];

		for ( int i = 0; i < ant_kompisar; i++ )
		{
			is >> strang;
			kompisar[i] = strang;
		}
		return is;
	}

	void Transaktion::skrivEnTrans ( ostream &os )
	{
		os  << datum << "\t" << typ << "\t" << namn << "\t" << belopp << "\t" << ant_kompisar;

		for ( int i = 0; i < ant_kompisar; i++ )
		{
			os << " " << kompisar[i];
		}
		os << endl ;
	}

	//***********************************Medlemsfunktioner transaktionslista**************************************

	TransaktionsLista::TransaktionsLista ()
	{
		antalTrans = 0;
		trans = NULL;
	}

	TransaktionsLista::~TransaktionsLista ()
	{
	    delete[] trans;
	}

	void TransaktionsLista::laeggTill ( Transaktion &t )
	{
		Transaktion *temp = 0;
		temp = new Transaktion[antalTrans+1];

		for (int i = 0; i < antalTrans; i++)
		{
			temp[i] = trans[i];
		}

		if(antalTrans > 0)
		{
			delete [] trans;
		}

		trans = temp;
		antalTrans++;
		trans[antalTrans-1] = t;
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
	    cout << "Antal transaktioner: " << antalTrans << endl;
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

	double TransaktionsLista::liggerUteMed ( string namn )
	{
		double liggerUteMedSum = 0.0;
		for(int i = 0; i < antalTrans; i++)
		{
			if(trans[i].haemta_namn() == namn)
			{
				//Antal kompisar får inte vara 0
				liggerUteMedSum += (trans[i].haemta_belopp() - (trans[i].haemta_belopp() / (trans[i].haemta_ant_kompisar()+1)));
			}
		}
		return liggerUteMedSum;
	}

	double TransaktionsLista::aerSkyldig(string namn)
	{
		double skuld = 0.0;

		for(int i = 0; i < antalTrans; i++)
		{
			skuld += trans[i].haemta_skuld(namn);
		}
		return skuld;
	}

	PersonLista TransaktionsLista::FixaPersoner()
	{
		PersonLista nyPersLista = PersonLista();
		string persNamn = "";

		for(int i = 0; i < antalTrans; i++)
		{
		    if(!nyPersLista.existerar(trans[i].haemta_namn()))
            {
                persNamn = trans[i].haemta_namn();
				Person nyPers = Person(persNamn, liggerUteMed(persNamn), aerSkyldig(persNamn));
				nyPersLista.laggTillEn(nyPers);
            }
		}
		return nyPersLista;
	}

    //***********************************Medlemsfunktioner person**************************************

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
        if(betalat_andras > skyldig)
        {
            cout << namn << " ligger ute med " << betalat_andras << " och ar skyldig " << skyldig << ". Skall ha " << betalat_andras - skyldig << " fran potten!" << endl;
        }
        else
        {
            cout << namn << " ligger ute med " << betalat_andras << " och ar skyldig " << skyldig << ". Skall lagga " << skyldig - betalat_andras << " till potten!" << endl;
        }
	}

	//***********************************Medlemsfunktioner personlista**************************************

	PersonLista::PersonLista()
	{
		antal_pers = 0;
		pers = NULL;
	}

	PersonLista::~PersonLista()
	{
	    delete[] pers;
	}

	PersonLista::PersonLista(const PersonLista & p) : antal_pers(p.antal_pers)
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

	void PersonLista::laggTillEn(Person pny)
	{
		Person *tempPers = 0;
		tempPers = new Person[antal_pers+1];

		for (int i = 0; i < antal_pers; i++)
		{
			tempPers[i] = pers[i];
		}
		if(antal_pers > 0)
		{
			delete[] pers;
		}

		pers = tempPers;
		antal_pers++;
		pers[antal_pers-1] = pny;
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

	bool PersonLista::existerar(string namn)
	{
		for(int i = 0; i < antal_pers; i++)
		{
			if(pers[i].haemta_namn() == namn)
			{
				return true;
			}
		}
		return false;
	}