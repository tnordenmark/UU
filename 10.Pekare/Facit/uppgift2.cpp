//-------------------------------------------
// uppgift2.cpp

#include <iostream>
#include <string>
using namespace std;


int main()
{
  int i, n;
  cout << "\nAnge n  ";  
  cin >> n;
 
  int *array = 0;  
  array = new int[n];
 
  cout << "\nMata in " << n << " st tal\n";
  for (i = 0; i<n; i++) 
    {
      cin >> *(array+i); // eller array[i]
    }

  //Skriv ut talen med 5 tal per rad
  for (i=0; i<n; i++) 
    { 
      cout << *(array+i) << "\t"; // eller array[i]
      if ( (i+1)%5 == 0 ) 
	{
	  cout << endl;
	}
    }
  cout << endl;
  // Kopiera:
  //  double *nyarray = &array[0];
  int *nyarray;
  nyarray = new int[n];

  for (i=0; i<n; i++) 
    {
      nyarray[i] = array[i];
    }

  for (i=0; i<n; i++) 
    {
      cout << *(nyarray+i) << "\t"; // eller nyarray[i]
      if ( (i+1)%5 == 0 ) 
	{
	  cout<<endl;
	}
    }
  cout<<endl;

  delete []array;
  delete []nyarray;
  return 0;
}
