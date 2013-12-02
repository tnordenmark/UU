#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// person0.cpp
// Med filnamn som parameter.

class Person 
{
private:
  string namn;     // personens namn
  int alder;       // personens ålder

public:
  Person ();
  Person ( string n, int a );
  void skriv( string filnamn );
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
int main()
{
  Person p("Kalle Anka", 39);
  cout << "Vilken fil skall vi skriva ut på?" << endl;
  string filnamnet;
  getline(cin, filnamnet);
  p.skriv( filnamnet );

  return 0;
}

/*
Körningsexempel:

Vilken fil skall vi skriva ut på?
a.txt

Innehållet i "a.txt" är:
Personen Kalle Anka med ålder 39

*/
