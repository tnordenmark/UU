//-------------------------------------------
// uppgift3.cpp


#include <iostream>
#include <string>
using namespace std;

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
double medel( double *p, int n )
{
  int i;
  double sum = 0;
  for (i=0; i<n; i++) 
    {
      sum +=*(p+i);  // eller p[i]
    }
  return sum/n;
}

int main()
{
  int n;
  double *pris = 0;  

  cout << "\nLäs in tal mha laes" << endl;
  pris = laes( n );
 
  cout << "\nBeräkna medelvärdet mha medel" << endl;
  double val;
  val = medel( pris, n );

  if ( n ) 
    {
      cout << "\nMedelvärdet = " << val << endl;
    }

  delete[] pris;
  return 0;
}
