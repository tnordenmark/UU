// Filnamn : .../personTest1.cc

#include <iostream>
#include "person.h"
using namespace std;

int main() {
  person someOne( "Richard", "III" );
  person anotherOne("Katarina", "Jagellonica");
  person noOne;
  
  someOne.report();
  anotherOne.report();
  noOne.report();
  cout << "Hej ";
  someOne.writeName();
  cout << ", trevligt att se dig!" << endl;
  
  return 0;
}
