// Filnamn : .../Bank1/Account.h

#ifndef __ACCOUNT__
#define __ACCOUNT__

#include <string>
using namespace std;

// Klassdefinition för hantering av bankkonton.

class Account {

 public:
  Account();                       // Standardkonstruktor.
  Account( string n, double b );   // Konstruktor med parametrar
  
  void input();                    // Läs in data.
  void deposit( double amount );   // Sätt in pengar. 
  void withdraw( double amount );  // Ta ut pengar.
  void print();                    // Skriv saldobesked.

 protected:
  string name;
  double balance;
};
#endif
