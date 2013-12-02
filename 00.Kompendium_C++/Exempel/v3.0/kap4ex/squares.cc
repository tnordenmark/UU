// Filnamn: .../squares.cc
// Beräkna kvadrater på ett antal inlästa tal

#include <iostream>
using namespace std;

int main() {
  double tal;
  cout << "Ge tal att kvadrera. Avbryt med 0.";
  cin >> tal;                       // Läs det första talet
  while ( tal!=0 ) {                // Så länge inte 0 lästs
    cout << "Kvadraten är " << tal*tal << endl;
    cin >> tal;                     // Läs nytt tal
  }
  cout << "Tack för mig!" << endl;
  return 0;
}
