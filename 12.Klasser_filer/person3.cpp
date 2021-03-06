#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// person3.cpp
// Med strömvariabel (filvariabel) som parameter blir
// det lite mer flexibelt att använda.
// Många utskrifter efter varandra.
// Nu med open -close.

class Person 
{
private:
  string namn;     // personens namn
  int alder;       // personens ålder

public:
  Person ();
  Person ( string n, int a );
  void skriv( string filnamn );
  void skriv( ofstream &fout );
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
void Person::skriv( string filnamn )
{
  ofstream fout(filnamn.c_str());
  fout << "Personen " << namn 
       << " med ålder " << alder << endl;
}
//----------------------------------------
void Person:: skriv( ofstream &fout )
{
  // Filen förväntas vara öppnad i anropande
  // programmet, här=main.

  fout << "Personen " << namn 
       << " med ålder " << alder << endl;
}
//----------------------------------------
int main()
{
  // Skapa en array med personer.
  const int MAX = 5;

  Person pers[MAX] = {Person("Kalle Anka", 39),
		      Person("Kajsa Anka", 35),
		      Person("Mimmi Pigg", 25),
		      Person("Musse Pigg", 24),
		      Person("Spöket Laban", 3)};
    
  cout << "Vilken fil skall vi skriva ut på?" << endl;
  string filnamnet;
  getline(cin, filnamnet);

  ofstream utfilen;
  utfilen.open ( filnamnet.c_str() );

  for ( int i = 0; i < MAX; i++ )
    pers[i].skriv( utfilen );

  utfilen.close(); // Behövs ej, stängs automatiskt vid
                   // programmets slut...
                 // Men bra ha denna vana :-)
  return 0;
}

/*
Körningsexempel:

Vilken fil skall vi skriva ut på?
d.txt

Innehållet i "d.txt" är:
Personen Kalle Anka med ålder 39
Personen Kajsa Anka med ålder 35
Personen Kajsa Anka med ålder 35
Personen Mimmi Pigg med ålder 25
Personen Musse Pigg med ålder 24
Personen Spöket Laban med ålder 3


*/
