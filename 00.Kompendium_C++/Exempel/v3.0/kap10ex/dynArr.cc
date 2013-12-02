// Filnamn : .../dynArr.cc
#include <iostream>
using namespace std;

int main() {
  int num,i;
  double sum,mean;

  cout << "For how many numbers do you want the mean calculated : ";
  cin >> num;
  if (num<1) return 0;

  double *dPointer = new double[num];     // allokering

  sum = 0.0;
  for ( i=1; i<=num; i++ ) {
    cout << "Give number " << i << " : ";
    cin >> dPointer[i-1];
    sum += dPointer[i-1];
  }
  mean = sum/num;
  cout << "The values divided by the mean are:" << endl;
  for ( i=1; i<=num; i++ )
    cout << dPointer[i-1]/mean << endl;
  
  delete[] dPointer;                      // återlämning
  return 0;
}
