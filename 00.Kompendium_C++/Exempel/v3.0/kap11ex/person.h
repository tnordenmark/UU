// Filnamn : .../person.h
#ifndef __person__
#define __person__

#include<string>
using namespace std;

class person {
 public:
  person();               // defaultkonstruktor
  person(string fn, string ln); // överlagrad konstruktor
  ~person();              // destruktor

  void report();          // Skriv all
  void writeName();       // Skriv namnet
  void input();           // Läs in person

 protected:
  string fname; 
  string lname; 
};
#endif
