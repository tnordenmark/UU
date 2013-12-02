// Filnamn: .../lifetime.cc

#include <iostream>
using namespace std;

double gx = 1;

void Print() {
  int lx = 1;
  lx++;
  gx++;
  cout << "Global=" << gx << " Local=" << lx << endl;
}

int main() {
  for (int i=0; i<5 ; i++ )
    Print();
  return 0;
}
