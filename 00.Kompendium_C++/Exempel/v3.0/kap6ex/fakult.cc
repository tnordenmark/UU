// Filnamn: .../fakult.cc

#include <iostream>
using namespace std;

int fakultet( int x ) {
  if (x<=1) 
    return 1;
  else 
    return x * fakultet(x-1);
}

int main() {
  cout << "Fakultet 4 : " << fakultet(4) << endl;
  cout << "Fakultet 7 : " << fakultet(7) << endl;
  return 0;
}
