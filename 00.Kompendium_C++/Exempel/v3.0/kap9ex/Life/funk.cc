// Filnamn : .../Life/funk.cc

/* 
   Funktioner till 'Game of life'. 
*/

#include <iostream>
#include "funk.h"
using namespace std;


void menu() {
  cout << endl;
  cout << "\t1:\t Spela:" << endl;
  cout << "\t0:\t Avsluta:" << endl; 
}

int readChoice() {
  int choice;
  
  cout << "\nAnge ditt val: " << endl; 
  cin >> choice;
  cin.get();
  
  while (choice<0 || choice>1) {
    cout << "\nValet ska vara  0 eller 1:" << endl;
    cin >> choice;
    cin.get();
  }

  return choice;
}
