// Filnamn : .../ex03.cc

#include <iostream>
#include <string>
#include "weightlifter.h"
using namespace std;

int main() {
  srand48( 30313 );          // Initiering av slumpgenerator
  double nr;
  Weightlifter wL1("Rocky","Balboa","Boxare",3,120);
  Weightlifter wL2("Modesty","Blaise","Boxare",3000,90);

  cout << "COMPETITION...." << endl;
  for (int i=1; i<=10000; i++) {
    nr = drand48();
    if (nr > 0.55) 
      wL1.firstPrize();
    else
      wL2.firstPrize();
  }
  
  cout << "...and the winner is : ";
  if (wL1.getNrFirstPrize() > wL2.getNrFirstPrize())
    wL1.report();
  else if (wL1.getNrFirstPrize() < wL2.getNrFirstPrize())
    wL2.report();
  else
    cout << "no one :-(" << endl;

  return 0;
}
