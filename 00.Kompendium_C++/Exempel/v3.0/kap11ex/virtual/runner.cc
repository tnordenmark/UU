// Filnamn : .../virtual/runner.cc
#include <iostream>
#include <string>
#include "sportsman.h"
#include "runner.h"
using namespace std;

runner::runner() : sportsman() {
  conditionIndex = 0;
}

runner::runner( string fn, string ln, 
		string br, int nfp, double ci )
  : sportsman( fn, ln, br, nfp ) {
  conditionIndex = ci;
}

runner::~runner() {}

void runner::report() {
  sportsman::report();
  cout << "Konditionsindex : " << conditionIndex <<endl;
}

void runner::input() {
  sportsman::input();
  cout << "Ange konditionsindex : ";
  cin >> conditionIndex;
  cin.get();
}

double runner::getConditionIndex() {
  return conditionIndex;
}

void runner::setConditionIndex( double ci ) {
  conditionIndex = ci;
}
