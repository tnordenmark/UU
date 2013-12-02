// Filnamn: .../scope.cc
#include <iostream>
using namespace std;

double d1 = 17.5;       // global variable, scope from here

int main() {
  int i1 = 1;           // local variables
  int i2 = 2;           // scope from here in main function
  if (i1 != i2 ) {
    int i3 = 3;         // Scope within this {}
    cout << i3 << endl;
    int i4 = 4;         // Scope from here
    cout << d1 << endl; //    |
    cout << i4 << endl; // To here 
  }
  else {
    cout << i1 << i2 << d1 << endl;    // OK in scope
    cout << i3 << i4 << endl;          // NOT OK, compile error
  }
  return 0;
}
