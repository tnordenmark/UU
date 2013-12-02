#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// person6.cpp
// Med strömvariabel (filvariabel) som parameter blir
// det lite mer flexibelt att använda.
// Många utskrifter efter varandra.
// Nu med open -close.
// Ändra ofstream till ostream så kan man
// anropa med ström av typen ofstream eller
// cout!
// Nu med inläsning på generellt sätt,
// ibland med cin, ibland från fil!
// Låt inläsningsmetoden returnera bool.

class Person 
{
private:
  string namn;     // personens namn
  int alder;       // personens ålder

public:
  Person ();
  Person ( string n, int a );
  void skriv( ostream &fout );
  bool las( istream &fin ); 
};

//----------------------------------------
Person::Person()
{
  namn = "Inget";
  alder = 0;
}
//----------------------------------------
Person::Person( string n, int a ) 
{
  namn = n;
  alder = a;
}
//----------------------------------------
void Person:: skriv( ostream &fout )
{
  // Filen förväntas vara öppnad i anropande
  // programmet, här=main.

  fout << "Personen " << namn 
       << " med ålder " << alder << endl;
}
//----------------------------------------
bool Person:: las( istream &fin )
{
  // Namn (för- och efternamn) på en rad
  // ålder på nästa rad.
  // Returnera filströmmen omvandlad till bool, eller
  // returnera "icke end of file", så kan huvudprogrammet
  // loopa på vettigare sätt.

  getline( fin, namn );
  fin >> alder;
  fin.get();   // bort med returtecknet...

  //    return fin;          // Antingen denna...
  return !fin.eof();   // eller denna.
} 

//----------------------------------------
int main()
{
  // Skapa en array med personer.
  const int MAX = 5;

  Person pers[MAX];

  cout << "Ge " << MAX << " st personer "
       << "(namn och ålder på olika trader)" << endl;


  ifstream indata("indatanamn.txt");

  // Testa med inläsning från tangentbord
  // eller fil genom att kommentera bort den ena. 

  // Läs till filen är slut eller inmantning från
  // tangentbord tar slut (ctrl-D = eof).

  Person p;
  int antal = 0;


  //  while ( p.las( cin ) )
  while ( p.las( indata ) )
    {
      if ( antal < MAX )
	{
	  pers[antal] = p;
	  antal++;
	}
    }


  cout << "Vilken fil skall vi skriva ut på?" << endl;
  string filnamnet;
  getline(cin, filnamnet);

  ofstream utfilen;
  utfilen.open ( filnamnet.c_str() );

  // Skriva ut på fil ibland och cout ibland, t.ex.
  // både och!

  for ( int i = 0; i < antal; i++ ) // Nu med "antal"
    pers[i].skriv( utfilen );

  utfilen.close(); // Behövs ej, stängs automatiskt vid
                   // programmets slut...
                  // Men bra ha denna vana :-)

  for ( int i = 0; i < antal; i++ ) // Nu med "antal"
    pers[i].skriv( cout );

  return 0;
}

/*
Körningsexempel:

Ge 5 st personer (namn och ålder på olika trader)
Nisse Anka
23
Olle Korp
34
Allan Jönsson
21
Stina Salomonsson
45
Oskar Oskarsson
67
Vilken fil skall vi skriva ut på?
f.txt
Personen Nisse Anka med ålder 23
Personen Olle Korp med ålder 34
Personen Allan Jönsson med ålder 21
Personen Stina Salomonsson med ålder 45
Personen Oskar Oskarsson med ålder 67


Innehållet i "f.txt" är:
...


*/
