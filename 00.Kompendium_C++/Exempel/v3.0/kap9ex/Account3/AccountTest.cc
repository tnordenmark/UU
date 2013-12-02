// Filnamn .../Account3/AccountTest.cc
// Testprogram för klassen Account

#include <iostream>
#include "Account.h"

int main() {  
  // Deklaration av 2 objekt av klassen Account
  Account x, y;
  double dep;

  x.input();
  cout << "Insättning för " << x.getName() << ": ";
  cin >> dep;
  cin.get();
  x.deposit(dep);
  
  y.input();
  cout << "Insättning för " << y.getName() << ": ";
  cin >> dep;
  cin.get();
  y.deposit(dep);

  if ( x.getBalance() > y.getBalance() )
    cout << x.getName() << " har mer pengar än " << y.getName() << endl;
  return 0;
}
