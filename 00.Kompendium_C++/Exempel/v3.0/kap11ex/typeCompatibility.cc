// Filnamn : .../typeCompatibility.cc

#include <iostream>
#include "person.h"
#include "sportsman.h"
#include "runner.h"
#include "student.h"
using namespace std;

int main() {
  person    p("P","P");
  sportsman sp("Sp", "Sp", "", 0);
  runner    ru("Ru", "Ru", "", 0, 0.0);
  student   st("S", "S", "MBL");

  // These assignments are OK
  p  = sp;            // en nivå upp
  p  = ru;            // två nivåer upp
  p  = st;            // en nivå upp
  sp = ru;            // en nivå upp

  // These assignments are NOT OK
  sp = p;
  ru = sp;
  ru = p;
  st = sp;
  return 0;
}
