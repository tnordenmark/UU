// Filnamn: .../harmonicWhile2.cc

#include <iostream>
using namespace std;

int main() {
  int    n;
  
  cout << "Antal termer: ";
  cin >> n;
  while ( n>0 ) {
    double h = 0.0;
    while ( n>0 ) {
      h = h + 1./double(n);
      n--;
    }
    cout << "Summan är: " << h << endl;
    cout << "Nytt antal (0 om du vill sluta): ";
    cin  >> n;
  }
  return 0;
}
