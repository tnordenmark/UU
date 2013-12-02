#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Uppgift 2: temperatur2.cpp

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
  bool lasin(istream &in);   // Läs in med input stream
  void skriv();            // utskrift av grader
  void skriv(ostream &ut);   // skriv med output stream
  double haemta_grader();  // selektor: returnerar grader
  string haemta_typ();     // selektor, returnerar typ.
  double skillnad( temperatur t ); // skillnaden mellan 2 temperaturer
  double fahrenheit();             // returnerar grader i Fahrenheit
  void rapport( int nedre, int oevre ); // skriver "rapport"
};
//------------------------------------------------------
// Huvudprogram:

int main()
{
  temperatur t1, t2;
  temperatur t3(35,"Celsius"), t4(100,"Fahrenheit");

  cout << "Ge några grader och typ på samma rad:" << endl;
  t1.lasin(cin);
  t2.lasin(cin);

  temperatur arr[] = {t1, t2, t3, t4};

  cout << "Testar lite..." << endl;

  for(int i = 0; i < 4; i++)
  {
      arr[i].skriv(cout);
  }
  cout << endl;

  // Öppna filen för skrivning.
  ofstream fout("minfil.dat");

  // Skriv ut arrayens värden på fil.
  
  for(int i = 0; i < 4; i++)
  {
      arr[i].skriv(fout);
  }
  fout << endl;

  // Nu vill vi läsa filen med inläsningsmetoden,
  // men först måste man stänga filen och sedan
  // öppna den för läsning.
  // Vi kan låtsas att vi ej vet vad den innehåller....
  
  fout.close();
  ifstream fin("minfil.dat");

  if(fin)
  {
      // Läs till end of file. Kan göras på olika sätt,
      // men om nu "lasin"-metoden från filer
      // är av typen _void_, så
      // kanske detta är bäst:
      
      const int MAX = 25;
      temperatur x[MAX];

      int antal = 0;
      temperatur enTemp; // Temporär temperatur

      while(enTemp.lasin(fin))
      {
          if(antal < MAX)
          {
              x[antal] = enTemp;
              antal++;
          }
      }

      fin.close();
      
      // Skriv ut vad vi har i x-arrayen (surprise):
      for(int i = 0; i < antal; i++)
      {
          x[i].skriv(cout);
      }
      cout << endl;

      for(int i = 0; i < antal; i++)
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

bool temperatur::lasin(istream &in)
{
    in >> grader >> typ;
    return in;
}

void temperatur::skriv()
{ 
  cout << "Temperaturen är "<< grader << " grader "
       << typ << "." << endl;
}

void temperatur::skriv(ostream &ut)
{
    ut << "\n" << grader << "  " << typ << endl;
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
     

/* Körningsresultat:
Ange grader: 25
Ange typen: Celsius
Temperaturen är 28 grader Celsius.
Temperaturen är 25 grader Celsius.
Temperaturen är 35 grader Celsius.
Temperaturen är 100 grader Fahrenheit.
Oh! Vad varmt det är idag.
Oh! Vad varmt det är idag.
Default-objekt: 28 Celsius
28 grader Celsius motsvaras av 82.4 grader Fahrenheit.
Skillnaden mellan 25 och 35 = -10


Ange grader: 99
Ange typen: Fahrenheit
Temperaturen är 28 grader Celsius.
Temperaturen är 99 grader Fahrenheit.
Temperaturen är 35 grader Celsius.
Temperaturen är 100 grader Fahrenheit.
Oh! Vad varmt det är idag.
Oh! Vad varmt det är idag.
Default-objekt: 28 Celsius
28 grader Celsius motsvaras av 82.4 grader Fahrenheit.
Olika enheter!!!
Skillnaden mellan 99 och 35 = -99999
 */
