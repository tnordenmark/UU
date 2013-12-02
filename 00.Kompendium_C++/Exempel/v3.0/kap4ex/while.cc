// .../while.cc
#include <iostream>
using namespace std;

int main() {
  double tal, summa=0.0;
  cout << "Ge tal att summeras. Avbryt med 0.";
  cin >> tal;              // Läs det första talet
  while ( tal!=0 ) {       // Så länge inte 0 lästs
    summa = summa + tal;   // Addera till summan  
    cin >> tal;            // Läs nytt tal
  }
  cout << "Summan är: " << summa << endl;
}
