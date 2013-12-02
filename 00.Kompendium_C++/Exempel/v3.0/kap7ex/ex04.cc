// Filnamn: .../ex04.cc

#include <iostream>
using namespace std;

double sumArray( const int num, double data[] ) {
  double sum = 0.0;
  for (int i=0; i<num; i++ )
    sum += data[i];
  return sum;
}

int main() {
  const int max = 5;
  double temp[max];

  cout << "Give " << max << " numbers: " << endl;

  for (int i=1; i<=max; i++) {
    cout << "Give number " << i << " : ";
    cin >> temp[i-1];
  }

  cout << "The numbers added : " << sumArray( max,temp) << endl;
  return 0;
}
