// Filnamn .../car.h
#ifndef __car__
#define __car__
#include "tire.h";
#include "engine.h";

class car {
 protected:
  engine en;             // one engine
  tire lf, lr, rf, rr;   // four tires
 public:
  car();
  car( double hp, 
       double cyl, 
       double tD, 
       double tP );
  ~car();
};
#endif
