// Filnamn: .../static.cc

#include <iostream>
using namespace std;

double gx = 1;

void Print() {
  static int lx = 1;  // static deklaration
  lx++;
  gx++;
  cout << "Global=" << gx << " Local=" << lx << endl;
}

int main() {
   for (int i=0; i<5 ; i++ )
     Print();
   return 0;
}
