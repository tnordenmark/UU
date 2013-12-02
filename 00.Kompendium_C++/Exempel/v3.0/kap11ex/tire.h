// Filnamn .../tire.h
#ifndef __tire__
#define __tire__

class tire {
protected:
  double diameter;
  double patternDepth;
public:
  tire();      
  tire( double d, double pd );
  ~tire();              
};
#endif
