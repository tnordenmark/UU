//-------------------------------------------
// uppgift5.cpp

#include <iostream>
#include <string>
using namespace std;

double sum( double *a, int n)
{
  if ( n <= 0 )
    {
      return 0.0;
    }
  else
    {
      return *a + sum(a+1,n-1);
    }
}

double *laes( int &n )
{
  cout << "\nAnge n  ";  
  cin >> n;
 
  double *array = 0;  
  array = new double[n];
 
  cout << "\nMata in " << n << " st tal\n";
  for (int i = 0; i<n; i++) 
    {
      cin >> *(array+i); // eller array[i]
    }
  return array;
}

int main()
{
  int n;

  cout << "\nLäs in tal mha laes" << endl;
  double *a = laes( n );

  cout << "\nBeräkna summan mha sum" << endl;
  double s = sum( a, n );


  if ( n ) 
    {
      cout << "\nSumman = " << s << endl;
    }

  delete[] a;
  return 0;
}
