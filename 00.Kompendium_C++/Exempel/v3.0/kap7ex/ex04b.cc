// Filnamn: .../ex04b.cc

#include <iostream>
using namespace std;

void tenPercent( int num, double data[] ) {
  for (int i=0; i<num; i++ )
    data[i] *= 1.10;
}

int main() {
  const int max = 3;
  double temp[max] = { 1.0, 2.0, 3.0 };

  cout << "Values before function call : " << endl;
  for (int i=1; i<=max; i++ )
    cout << temp[i-1] << " ";

  tenPercent( max, temp );

  cout << "\nValues after function call : " << endl;
  for ( i=1; i<=max; i++ )
    cout << temp[i-1] << " ";

  cout << endl;
  return 0;
}
