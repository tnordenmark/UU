// Filnamn: .../virtual/preg.cc
#include<iostream>
#include<string>
#include "person.h"
#include "preg.h"

preg::preg() {     // Konstruktor
  numPersons = 0;
  for (int i=1; i<=maxPerson; i++)
    pers[i-1] = 0;  // Pekare till ingenting
}

preg::~preg() {     // Destruktor
  for (int i=1; i<=numPersons; i++ )
    delete pers[i-1];
}

void preg::reportAll() {
  for (int i=1; i<=numPersons; i++ ) {
    cout << "==============================================" << endl;
    cout << "Person " << i << " : " << endl;
    pers[i-1]->report();
  }
}

void preg::inputAll() {
  for (int i=1; i<=numPersons; i++ )
    pers[i-1]->input();
}

void preg::insertPerson(person *p) {
  numPersons++;
  if ( numPersons > maxPerson ) {
    cout << "Fö många personer! Programmet avbryts." << endl;
    exit(2);
  }
  pers[numPersons-1] = p;
}
