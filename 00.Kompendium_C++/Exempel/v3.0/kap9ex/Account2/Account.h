// Filnamn : .../Account2/Account.h

#ifndef __ACCOUNT__
#define __ACCOUNT__

#include <string>
using namespace std;

// Klassdefinition för hantering av bankkonton.

class Account {
 public:            // Publika metoder
  void input();
  void deposit( double amount );
  void withdraw( double amount );
  void print();
  
 protected:         // Skyddade datafält
  string name;
  double balance;
};
#endif
