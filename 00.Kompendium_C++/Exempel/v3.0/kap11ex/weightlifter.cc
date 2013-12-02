// Filnamn : .../kap11ex/weightlifter.cc

#include <iostream>
#include <string>
#include "sportsman.h"
#include "weightlifter.h"
using namespace std;


weightlifter::weightlifter() : sportsman() {
  weight = 0;
  cout << "Welcome weightlifter " << fname << endl;
}
  
weightlifter::weightlifter( string fn, string ln,
			    string br, int nfp, int w )
  : sportsman( fn, ln, br, nfp ) {
  weight = w;
  cout << "Welcome weightlifter " << fname << endl;
}

weightlifter::~weightlifter() {
  cout << "Bye weightlifter " << fname << " " << lname << endl;
}

void weightlifter::report() {
  sportsman::report();
  cout << "weight " << weight <<endl;
}

void weightlifter::input() {
  sportsman::input();
  cout << "Enter the weight : ";
  cin >> weight;
  cin.get();
}

int weightlifter::getWeight() {
  return weight;
}  

void weightlifter::setWeight( int w ) {
  weight = w;
}
