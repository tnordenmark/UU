// Filnamn : .../Bank2/Account.h

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
  double getBalance();             // Returnera saldo
  string getName();                // Returnera ägare
 protected:
  string name;
  double balance;
  friend class Bank;       // Ger banken fullständiga rättigheter
};
#endif



