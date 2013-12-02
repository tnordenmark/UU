// Filnamn : .../Account4/Account.cc

#include <iostream>
#include <string>
#include "Account.h"
using namespace std;


Account::Account() {
  balance = 0;
  name    = "Arne Anonym";
  cout << "Hello default: " << name 
       << "  "  << balance << endl;
}

Account::Account(string n, double b) {
  balance = b;
  name    = n;
  cout << "Hello : " << name 
       << "  "  << balance << endl;
}

Account::~Account() {
  cout << "Bye-bye " << name 
       << " med saldot: "  << balance << endl;
}

void Account::input() {
  cout << "Ge namn : ";
  getline(cin, name);
  balance = 0;
}

void Account::deposit( double amount ) {
  balance += amount;
}

void Account::withdraw( double amount ) {
  balance -= amount;
}

void Account::print() {
  cout << name << " har " << balance 
       << " på sitt konto " << endl;
}
