// Filnamn : .../weightlifter.h

#ifndef __WEIGHTLIFTER__
#define __WEIGHTLIFTER__

#include <string>
#include "sportsman.h"
using namespace std;

class weightlifter : public sportsman {
 public:
  weightlifter();            // Standardkonstruktor
  weightlifter( string fn, string ln,
		string br, int nfp, int w );
                             // Överlagrad konstruktor
  ~weightlifter();           // Destruktor

  void report();             // Skriver data på skärmen
  void input();              // Tar in data från användaren
  int getWeight();           // Selektor
  void setWeight( int w );   // Sätt vikt

 protected:
  int weight;                // Vikt som kan lyftas i bänkpress
};
#endif
