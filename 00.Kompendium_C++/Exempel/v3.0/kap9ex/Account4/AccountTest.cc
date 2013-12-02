// Filnamn : ...Account4/AccountTest.cc

//   Ett litet huvudprogram som testar 
//   konstruktorerna och metoderna.

#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

int main() {
  string name = "Ford Prefect";  // Lokal variabel i main
  Account nobody;                // Standardkonstruktor anropas
  Account somebody(name, 100);   // Överlagrad konstruktor anropas

  nobody.print();
  somebody.print();
  nobody.input();
  nobody.print();

  return 0;
}
