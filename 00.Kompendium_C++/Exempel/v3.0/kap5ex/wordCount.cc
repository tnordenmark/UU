// Filnamn: .../wordCount.cc
// Räknar "ord". Med "ord" avses en följd av tecken som
// inte innehåller något vitt tecken 
// Avbryter när inget mer finns att läsa.

#include <iostream>
#include <string>

using namespace std;

int main() {
  int nwords = 0;
  string w;;
  while ( cin >> w ) {     // Läs ett ord
    nwords++;
  }
  cout << "Antal lästa ord: " << nwords << endl;
  return 0;
}
