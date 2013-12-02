// Filnamn : .../personTest2.cc

#include <iostream>
#include "person.h"
using namespace std;

int main() {
  person *me;
  person *partner = new person("Eliza","Doolittle");
  me = new person;
  *me = person("Henry","Higgins");
  
  partner->report();
  me->report();
  
  delete partner;
  delete me;
 
  return 0;
}
