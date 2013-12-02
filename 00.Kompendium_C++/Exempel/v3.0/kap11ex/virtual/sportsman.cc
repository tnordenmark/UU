// Filnamn : .../virtual/sportsman.cc

#include <iostream>
#include <string>
#include "person.h"
#include "sportsman.h"
using namespace std;

sportsman::sportsman() : person() {
  branch = "";
  nrFirstPrize = 0;
}

sportsman::sportsman( string fn, string ln,
		      string br, int nfp ) 
  : person(fn, ln) {
  branch = br;
  nrFirstPrize = nfp;
}

sportsman::~sportsman() {}

void sportsman::report() {
  person::report();
  cout << "och utövar " << branch << ".\n"
       << fname << " har vunnit " << nrFirstPrize 
       << " förstapriser." << endl;
}

void sportsman::input() {
  person::input();
  cout << "Ange gren " << fname << " : ";
  getline(cin, branch);
  cout << "Ange antalet förstapriser : ";
  cin >> nrFirstPrize;
  cin.get();
}

void sportsman::firstPrize() {
  nrFirstPrize++;
}

string sportsman::getBranch() {
  return branch;
}

int sportsman::getNrFirstPrize() {
  return nrFirstPrize;
}
