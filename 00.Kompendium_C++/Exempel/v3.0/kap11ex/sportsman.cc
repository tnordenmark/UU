// Filnamn : .../sportsman.cc
#include <iostream>
#include <string>
#include "person.h"
#include "sportsman.h"
using namespace std;

sportsman::sportsman() : person() {
  branch = "";
  nrFirstPrize = 0;
  cout << "Välkommen sportsman " << fname << endl;
}

sportsman::sportsman( string fn, string ln, string br, int nfp ) 
  : person(fn, ln) {
  branch = br;
  nrFirstPrize = nfp;
  cout << "Välkommen sportsman " << fname << endl;
}

sportsman::~sportsman() {
  cout << "Ajöss sportsman " << fname << " " << lname << endl;
}

void sportsman::report() {
  person::report();
  cout << "och utövar " << branch << ".\n"
       << fname << " har vunnit " << nrFirstPrize 
       << " förstapriser" << endl;
}

void sportsman::input() {
  person::input();
  cout << "Ange gren för " << fname << " : ";
  getline(cin, branch);
  cout << "Ange antal förstapriser : ";
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
