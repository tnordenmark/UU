// Filnamn : .../virtual/runner.h
#ifndef __RUNNER__
#define __RUNNER__

#include <string>
#include "sportsman.h"
using namespace std;

class runner : public sportsman {
 public:
  runner();                  // Standardkonstruktor
  runner( string fn, string ln,
	  string br, int nfp, double ci );
                             // Överlagrad konstruktor
  ~runner();                 // Destruktor

  void report();             // Skriver data på skärmen
  void input();              // Tar in data från användaren
  double getConditionIndex();// Selektor
  void setConditionIndex( double ci );// Sätt konditionsindex

 protected:
  double conditionIndex;     // En löpares syreupptagningsförmåga
};
#endif
