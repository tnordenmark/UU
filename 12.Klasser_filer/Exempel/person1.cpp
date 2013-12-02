#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// person1.cpp
// Med strömvariabel (filvariabel) som parameter blir
// det lite mer flexibelt att använda.

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
  Person p("Kalle Anka", 39);
  cout << "Vilken fil skall vi skriva ut på?" << endl;
  string filnamnet;
  getline(cin, filnamnet);

  ofstream utfilen( filnamnet.c_str() );
  p.skriv( utfilen );

  //
  p.skriv( filnamnet );

  return 0;
}

/*
Körningsexempel:

Vilken fil skall vi skriva ut på?
b.txt

Innehållet i "b.txt" är:
Personen Kalle Anka med ålder 39

*/
