// Filnamn .../Account2/AccountTest.cc
// Testprogram för klassen Account

#include <iostream>
#include "Account.h"

int main() {  
  // Deklaration av 2 objekt av klassen Account
  Account lisa;
  Account olle;

  lisa.input();
  olle.input();
  lisa.print();
  olle.print();
  lisa.deposit( 500 );
  lisa.withdraw( 350 );
  lisa.print();
  return 0;
}
