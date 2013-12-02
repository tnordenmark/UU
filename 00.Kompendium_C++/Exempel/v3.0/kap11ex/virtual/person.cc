// Filnamn : .../virtual/person.cc

#include<iostream>
#include<string>
#include "person.h"
using namespace std;

person::person() {
  fname = "Arne";
  lname = "Anonym"; 
}

person::person(string fn, string ln) {
  fname = fn;
  lname = ln;
}

person::~person() {}

void person::report() {
  cout << fname << " " << lname << endl;
}

void person::writeName() {
  cout << fname << " " << lname;
}

void person::input() {
  cout << "Förnamn: ";
  getline(cin, fname);
  cout << "Efternamn: ";
  getline(cin, lname);
}
