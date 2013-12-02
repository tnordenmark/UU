// Filnamn: .../nested.cc

#include <iostream>
using namespace std;

double x = 17.5;                   // första x:et

int main() {
  int x = 4;                       // andra x:et
  cout << "Out 1 " << x << endl;
  if ( x > 3 ) {
    double x = 3.5;                // tredje x:et
    cout << "Out 2 " << x << endl;
  }
  cout << "Out 3 " << x << endl;
  cout << "Out 4 " << ::x << endl; // scope resolution
  return 0;
}
