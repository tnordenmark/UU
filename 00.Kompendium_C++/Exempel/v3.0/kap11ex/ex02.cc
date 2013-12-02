// Filnamn : .../ex02.cc

#include <iostream>
#include <string>
#include "sportsman.h"
using namespace std;

int main() {
  Sportsman anyOne("Kajsa","Bergkvist","yymmdd-xxxx","Höjdhopp",100);

  anyOne.report();
  anyOne.firstPrize();
  cout << "Hello ";
  anyOne.writeName();
  cout << ", you have " << anyOne.getNrFirstPrize() 
       << " number of first prizes!" << endl;

  return 0;
}
