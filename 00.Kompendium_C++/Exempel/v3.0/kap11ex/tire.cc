// Filnamn : .../tire.cc
#include<iostream>
#include<string>
#include "tire.h"

tire::tire() {
  diameter = 10;
  patternDepth = 10;
}

tire::tire( double d, double pd ) {
  diameter = d;
  patternDepth = pd;
  cout << "Constructor for tire " << endl;
}

tire::~tire() {
        cout << "Destructor for tire " << endl;
}
