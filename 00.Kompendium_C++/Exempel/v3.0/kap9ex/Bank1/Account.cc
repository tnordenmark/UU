// Filnamn : .../Bank1/Account.cc

#include <iostream>
#include <string>
#include "Account.h"
using namespace std;


Account::Account() {
  balance = 0;
  name    = "Arne Anonym";
}

Account::Account(string n, double b) {
  balance = b;
  name    = n;
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




