// Filnamn: .../kapital.cc

#include <iostream>
using namespace std;

int main() {
  double raenta;
  cout << "Räntesats i procent:";
  cin >> raenta;                      // Läs in räntesats
  double kapital = 1.;                // Startkapital
  int    aar = 0;                     // Antal gångna år

  while ( kapital < 2. ) {
    kapital = kapital + kapital*raenta/100.; // Lägg till en årsränta
    aar++;
  }
  cout << "Det krävs " << aar 
       << " för att fördubbla kapitalet" << endl;
  return 0;
}
