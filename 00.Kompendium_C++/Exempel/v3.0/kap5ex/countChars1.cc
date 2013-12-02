//  Filnamn: .../countChars1.cc
// Läser och räknar antalet bokstäver och siffror.
// Avbryter när inget mer finns att läsa.

#include <iostream>
#include <cctype>

using namespace std;

int main() {
  int nletters = 0, ndigits = 0, ntotal = 0;
  char c;
  while ( cin.get(c) ) {
    ntotal++;
    if ( isalpha(c) )
      nletters++;
    else if ( isdigit(c) )
      ndigits++;
  }
  cout << "Totalt antal lästa tecken: " << ntotal << endl;
  cout << "Antal bokstäver          : " << nletters << endl;
  cout << "Antal siffror            : " << ndigits << endl;

  return 0;
}
