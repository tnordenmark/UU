#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// person5.cpp
// Med strömvariabel (filvariabel) som parameter blir
// det lite mer flexibelt att använda.
// Många utskrifter efter varandra.
// Nu med open -close.
// Ändra ofstream till ostream så kan man
// anropa med ström av typen ofstream eller
// cout!
// Nu med inläsning på generellt sätt,
// ibland med cin, ibland från fil!

class Person 
{
private:
  string namn;     // personens namn
  int alder;       // personens ålder

public:
  Person ();
  Person ( string n, int a );
  void skriv( ostream &fout );
  void las( istream &fin ); 
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
void Person:: las( istream &fin )
{
  // Namn (för- och efternamn) på en rad
  // ålder på nästa rad.

  getline( fin, namn );
  fin >> alder;
  fin.get();   // bort med returtecknet...
} 

//----------------------------------------
int main()
{
  // Skapa en array med personer.
  const int MAX = 5;

  Person pers[MAX];

  cout << "Ge " << MAX << " st personer "
       << "(namn och ålder på olika rader)" << endl;


  ifstream indata("indatanamn.txt");

  // Testa med inläsning från tangentbord
  // eller fil genom att kommentera bort den ena. 

  for ( int i = 0; i < MAX; i++ )
    {
    //    pers[i].las( cin );         
    pers[i].las( indata );
    }
  
  cout << "Vilken fil skall vi skriva ut på?" << endl;
  string filnamnet;
  getline(cin, filnamnet);

  ofstream utfilen;
  utfilen.open ( filnamnet.c_str() );

  // Skriva ut på fil ibland och cout ibland, t.ex.
  // både och!

  for ( int i = 0; i < MAX; i++ )
    pers[i].skriv( utfilen );

  utfilen.close(); // Behövs ej, stängs automatiskt vid
                   // programmets slut...
                 // Men bra ha denna vana :-)

  for ( int i = 0; i < MAX; i++ )
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
