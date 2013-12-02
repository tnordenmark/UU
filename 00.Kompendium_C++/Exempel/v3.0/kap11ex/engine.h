// Filnamn .../engine.h
#ifndef __engine__
#define __engine__

class engine {
 protected:
  double horsePower;
  double cylinders;
 public:
  engine();
  engine( double hp, double c );
  ~engine();};
#endif
