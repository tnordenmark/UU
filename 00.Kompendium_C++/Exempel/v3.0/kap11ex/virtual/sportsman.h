// Filnamn : .../virtual/sportsman.h

#ifndef __SPORT__
#define __SPORT__
#include <string>
#include "person.h"
using namespace std;

class sportsman : public person {
 public:
  sportsman();               // Standardkonstruktor
  sportsman( string fn, string ln,
	     string br, int nfp );
                             // Överlagrad konstruktor
  ~sportsman();              // Destruktor

  void report();             // Skriver data på skärmen
  void input();              // Tar in data från användaren
  void firstPrize();         // Räkna upp antal förstapris

  // Selektorer
  string getBranch();
  int getNrFirstPrize();

 protected:
  string branch;             // Idrottsgren
  int nrFirstPrize;          // Antal förstapris
};
#endif
