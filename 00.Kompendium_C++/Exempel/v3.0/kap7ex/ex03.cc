// Filnamn: .../ex03.cc

#include <iostream>
using namespace std;

int main() {
  const int max = 5;
  int temp[max];

  cout << "Give " << max << " numbers: " << endl;

  for (int i=1; i<=max; i++) {
    cout << "Give number " << i << " : ";
    cin >> temp[i-1];
  }
  cout << "The given numbers in reversed order : " << endl;

  for ( i = max ; i>=1; i-- )
    cout << temp[i-1] << endl;
  
  cout << "Thanks for today " << endl;
  return 0;
}
