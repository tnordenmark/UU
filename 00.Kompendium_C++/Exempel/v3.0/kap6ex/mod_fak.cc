// Filnamn: .../mod_fakult.cc

#include <iostream>
using namespace std;

void PrintChar( char c, int n ) {
  for (int i=1; i<=n; i++)
    cout << c;
  cout << endl;
}

int fakultet( int x ) {       
  int temp;
  PrintChar( '>', x );

  if (x<=1) 
    temp = 1;
  else 
    temp = x * fakultet(x-1);
  PrintChar( '<',x );
  return temp;
}

int main() {
  int result = fakultet(12);
  cout << "fakultet(12) : " << result << endl;
  return 0;
}
