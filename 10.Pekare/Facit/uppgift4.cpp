//-------------------------------------------
// uppgift4.cpp

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

double* sort(const double* arr, int antal)
{
   double *x; 
   x = new double[antal];
  
   int i;
   //kopiera arr i x (vill behålla arrayen arr  oförändrad)
   for (i=0; i<antal; i++) 
     {
       *(x+i) = *(arr+i);
     }
   
   //sortera x, bubbelsort
   double temp;
   int osorterad = 1 ;
   while ( osorterad )
     { 
       osorterad = 0;
       for (i=0; i< antal-1; i++)
	 {
	   if (x[i] > x[i+1])
	     { 
	       temp = x[i]; 
	       x[i] = x[i+1]; 
	       x[i+1] = temp; 
	       ++osorterad;
	     }
	 }
     }
   return x;
}

//En funktion som skriver ut talen i array med k st tal per rad
void skriv( double *array, int n, int k )
{ 
  for (int i=0; i<n; i++) 
    { 
      cout << array[i] <<"  ";
      if ( (i+1)%k == 0 )
	{ 
	  cout << endl;  // k tal per rad
	}
    }
  cout << endl;
}

int main()
{
  int n, k;

  cout << "\nLäs in tal mha laes" << endl;
  double *a = laes( n );

  cout << "\nSkriv ut arrayen mha skriv" << endl;
  cout << "Ange antal tal per rad : ";
  cin >> k;
  skriv( a, n , k );
  
  cout << "\nSortera arrayen mha sort" << endl;
  double *s = sort( a, n );

  cout << "\nSkriv ut sorterade arrayen mha skriv" << endl;
  cout << "Ange antal tal per rad : ";
  cin >> k;
  skriv( s, n , k );

  delete[] s;
  delete[] a;

  return 0;
}
  
