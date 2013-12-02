// Filnamn: .../countDigits.cc
// Räknar antalet siffror på en rad
#include <iostream>
#include <cctype>

using namespace std;

int main() {
  int ndigits = 0;
  char c;
  cin.get(c);               // Läs första tecknet
  while ( c!='\n' ) {       // Så länge ej radslut
    if ( c>='0' && c<='9' ) // Om siffra så
      ndigits++;            // räkna
    cin.get(c);             // Läs nästa tecken
  }
  cout << "Antal siffror: " << ndigits << endl;

  return 0;
}
