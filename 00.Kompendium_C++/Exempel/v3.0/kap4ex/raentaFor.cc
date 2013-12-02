// Filnamn:.../raentaFor.cc
// Hur stort blir kapitalet efter ett visst antal år

#include <iostream>
using namespace std;

int main() {
  double kapital = 1.;                // Startkapital
  double raenta;                      // Räntesats i procent
  int    aar;                         // Antal gångna år

  cout << "Räntesats i procent: ";
  cin >> raenta;
  cout << "Antal år           : ";
  cin >> aar;        

  for ( int i = 1; i<=aar; i++ )
    kapital = kapital + kapital*raenta/100.;

  cout << "Kapitalet har blivit " << kapital << endl;

  return 0;
}
