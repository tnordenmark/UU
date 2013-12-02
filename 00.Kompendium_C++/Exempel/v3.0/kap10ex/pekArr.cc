// Filnamn : .../pekArr.cc
#include <iostream>
using namespace std;

int main() {

  const int max = 20;
  double a[max];

  for ( int i=0; i<max; i++ )
    a[i] = 0.1*i;
  
  double *p = &a[0];
  cout << "p pekar till    : " << *p << endl;
  
  p = p + 10;
  cout << "p pekar till    : " << *p << endl;
  
  p++;
  cout << "p pekar till    : " << *p << endl;
  
  cout << "p+3 pekar till  : " << *(p+3) << endl; 
  cout << "Alternativ (fel): " << *p+3 << endl; 
  return 0;
}

