// Filnamn .../car.cc
#include<iostream>
#include<string>
#include "car.h"
#include "tire.h"
#include "engine.h"

car::car() : en(), lf(), lr(), rf(), rr() {}

car::car( double hp, 
          double cyl, 
          double tD, 
          double tP ) :
  n(hp,cyl), lf(tD,tP), lr(tD,tP), rf(tD,tP), rr(tD,tP) {
        cout << "Constructor for car " << endl;
}

car::~car() {
        cout << "Destructor for car " << endl;
}
