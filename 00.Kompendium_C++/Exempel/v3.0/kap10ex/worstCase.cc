// Filnamn : .../worstCase.cc
#include <iostream>
using namespace std

int main() {
  const int max = 1000;           // worst case
  double dArray[max];
  
  int num,i;
  double sum,mean;
  
  cout << "For how many numbers do you want the mean calculated: ";
  cin >> num;
  if ( (num<1) || (num>max) ) return 0;

  sum = 0.0;
  for ( i=1; i<=num; i++ ) {
    cout << "Give number " << i << " : ";
    cin >> dArray[i-1];
    sum += dArray[i-1];
  }
  mean = sum/num;
  cout << "The values divided by the mean are:" << endl;
  for ( i=1; i<=num; i++ )
    cout << dArray[i-1]/mean << endl;
  return 0;
}


