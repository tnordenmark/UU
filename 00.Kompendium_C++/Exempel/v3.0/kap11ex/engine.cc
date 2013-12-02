// Filnamn .../engine.cc
#include<iostream>
#include<string>
#include "engine.h"

engine::engine() {
  horsePower = 10;
  cylinders = 10;
}

engine::engine( double hp, double c ) {
  horsePower = hp;
  cylinders = c;
  cout << "Constructor for engine " << endl;
}

engine::~engine() { 
  cout << "Destructor for engine " << endl;
}
