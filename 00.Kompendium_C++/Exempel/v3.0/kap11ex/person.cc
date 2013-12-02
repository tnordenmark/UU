// Filnamn : .../person.cc
#include<iostream>
#include<string>
#include "person.h"
using namespace std;

// Konstruktorer och destruktor

person::person() {
  fname = "Arne";
  lname = "Anonym"; 
  cout << "Välkommen " << fname << endl;
}

person::person(string fn, string ln) {
  fname = fn;
  lname = ln;
  cout << "Välkomen " << fname << endl;
}

person::~person() {
  cout << "Ajöss " << fname << " " << lname << endl;
}


// Publika metoder

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
