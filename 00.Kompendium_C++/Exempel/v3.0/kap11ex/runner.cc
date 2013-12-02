// Filnamn : .../runner.cc

#include <iostream>
#include <string>
#include "sportsman.h"
#include "runner.h"
using namespace std;

runner::runner() : sportsman() {
  conditionIndex = 0;
  cout << "Välkommen runner " << fname << endl;
}

runner::runner( string fn, string ln, 
	  string br, int nfp, double ci )
  : sportsman( fn, ln, br, nfp ) {
  conditionIndex = ci;
  cout << "Välkommen runner " << fname << endl;
}

runner::~runner() {
  cout << "Ajöss runner " << fname << " " << lname << endl;
}

void runner::report() {
  sportsman::report();
  cout << "Konditionsindex : " << conditionIndex <<endl;
}

void runner::input() {
  sportsman::input();
  cout << "Ge konditionsindex : ";
  cin >> conditionIndex;
  cin.get();
}

double runner::getConditionIndex() {
  return conditionIndex;
}

void runner::setConditionIndex( double ci ) {
  conditionIndex = ci;
}
