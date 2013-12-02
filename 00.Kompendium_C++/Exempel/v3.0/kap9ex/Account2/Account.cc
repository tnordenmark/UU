// Filnamn : .../Account2/Account.cc
// Implementation av metoderna i klassen Account

#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

void Account::input() {
  cout << "Ge namn : ";
  getline(cin, name);
  balance = 0;
}
  
void Account::deposit( double amount ) { balance += amount; }
  
void Account::withdraw( double amount ) {balance -= amount; }
  
void Account::print() {
  cout << name << " har " << balance 
       << " på sitt konto " << endl;
}
