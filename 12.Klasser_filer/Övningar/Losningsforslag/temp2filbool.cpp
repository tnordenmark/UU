#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Svar1: temp2fil.cpp

// Deklaration av klassen:

class  temperatur
{
private:
  double grader;        // gradtal
  string typ;           // "Celsius" eller "Fahrenheit".

public:
  temperatur();            // default-konstruktor
  temperatur( double t, string typen ); // överlagrad konstruktor 
  void lasin();            // inläsning av grader
  void skriv();            // utskrift av grader
  double haemta_grader();  // selektor: returnerar grader
  string haemta_typ();     // selektor, returnerar typ.
  double skillnad( temperatur t ); // skillnaden mellan 2 temperaturer
  double fahrenheit();             // returnerar grader i Fahrenheit
  void rapport( int nedre, int oevre ); // skriver "rapport"

  // Nya metoder:
  bool lasin( istream &in );    // inläsning av grader från fil
  void skriv( ostream &ut );    // utskrift av grader till fil
};
//------------------------------------------------------
// Huvudprogram:

int main()
{
  temperatur t1, t2;
  temperatur t3(35,"Celsius"), t4(100,"Fahrenheit");
  
  cout << "Ge grader och typ på samma rad:" << endl;

  if ( !t2.lasin(cin) )   
    {
      cout << "Programmet slutar." << endl;
      return 0;
    }

  temperatur arr[] = {t1, t2, t3, t4};

  cout << "Testar litegrand...." << endl;

  for ( int i = 0; i < 4; i++ )
    {
      arr[i].skriv( cout );
    }
  cout << endl;

  // Öppna filen för skrivning.

  ofstream fout("minfil.dat");

  // Skriv ut arrayens värden på filen.

  for ( int i = 0; i < 4; i++ )
    {
      arr[i].skriv( fout );
    }
  fout << endl;

  // Nu vill vi läsa filen med inläsningsmetoden,
  // men först måste man stänga filen och sedan
  // öppna den för läsning.
  // Vi kan låtsas att vi ej vet vad den innehåller....

  fout.close();
  ifstream fin("minfil.dat");
  
  if ( fin )
    {
      // Läs till end of file. Kan göras på olika sätt,
      // men om nu "lasin"-metoden från filer
      // är av typen _bool_, så
      // kanske detta är bäst:

      const int MAX = 25;
      temperatur x[MAX];

      int antal = 0;
      temperatur enTemp;  // Temporär temperatur :-)

      while ( enTemp.lasin( fin ) )
	{
	  if ( antal < MAX )
	    {
	      x[antal] = enTemp;
	      antal++;
	    }
	}
      
      fin.close();

      // Skriv ut vad vi har i x-arrayen (surprise):
      
      for ( int i = 0; i < antal; i++ )
	{
	  x[i].skriv(cout); 
	}
      cout << endl;

      for ( int i = 0; i < antal; i++ )
	{
	  x[i].skriv();
	}
      cout << endl;
    }
  else
    cout << "Filen kanske ej fanns..." << endl;

  return 0;
}

//------------------------------------------------------
// Implementation av klassens metoder:

// ---Konstruktorer---

temperatur::temperatur() // default-konstruktor
{ 
  grader = 28;  
  typ = "Celsius";
}

temperatur::temperatur( double t, string typen )
{ 
  grader = t;
  typ = typen;
}

// ---Medlemsfunktioner--- 

void temperatur::lasin()
{
  cout << "Ange grader: ";
  cin >> grader;
  cin.get();  //Läs förbi returntecknet.

  cout << "Ange typen: ";
  getline( cin, typ );
}

void temperatur::skriv()
{ 
  cout << "Temperaturen är "<< grader << " grader "
       << typ << "." << endl;
}
  
double temperatur::haemta_grader()
{ 
  return grader;
}

string temperatur::haemta_typ()
{
  return typ;
}

double temperatur::skillnad( temperatur t )
{ 
  // Kolla att samma enheter mäts!
  if ( typ == t.typ )
    return (grader - t.grader);
  else
    {
      cout << "Olika enheter!!!" << endl;
      return -99999;
    }
}

double temperatur::fahrenheit()
{
  if ( typ == "Celsius" )        // Om Celsius, så konvertera.
    return ( 32 + 1.8*grader );
  else
    return grader;             // Annars, låt vara.
}
 
void temperatur::rapport( int nedre, int oevre )
{ 
  string s1 = "Oh! Vad varmt det är idag.";
  string s2 = "Oh! Vad kallt det är idag.";
  string s3 = "Det är lagom varmt idag.";
	
  if ( grader < nedre ) 
    cout << s2;
  else if ( grader < oevre ) 
    cout << s3;
  else 
    cout << s1;

  cout << endl;
}

  // Nya metoder:

bool temperatur:: lasin( istream &in )
{
  // Inläsning av grader från fil (kompakt format).

  in >> grader >> typ;
  return in;           // konvertera ström till bool    
}


void temperatur:: skriv( ostream &ut )
{
  // Utskrift av grader till fil (kompakt format).

  ut << "\n" << grader << "  " << typ << endl;
}

     

/*
Ge grader och typ på samma rad:
22 Celsius
Testar litegrand....

28  Celsius

22  Celsius

35  Celsius

100  Fahrenheit


28  Celsius

22  Celsius

35  Celsius

100  Fahrenheit

Temperaturen är 28 grader Celsius.
Temperaturen är 22 grader Celsius.
Temperaturen är 35 grader Celsius.
Temperaturen är 100 grader Fahrenheit.
*/
