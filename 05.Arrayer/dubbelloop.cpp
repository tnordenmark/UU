// Filen dubbelloop.cpp
//
// Skapar en array av storlek [10][20]
// Låter användaren bestämma hur många 
// tal som ska matas in [n1][n2]]
// Läs in talen i en dubbel-loop
// Skriv ut tabellen 
#include <iostream>
using namespace std;

int main()
{
  const int MAX1 = 10;        // Max antal rader.
  const int MAX2 = 20;        // Max antal kolonner.
 
  double tabell[MAX1][MAX2];
  int n1, n2;

  // Låt användaren bestämma storlek [n1][n2]
  cout << "Ge antalet rader och kolumner" << endl;
  cin >> n1 >> n2;

  // Mata in talen
  for ( int i = 0; i < n1; i++ )
    {
      for ( int j = 0; j < n2; j++ )
        {
           cout << "Ge värde [" << i << "][" << j << "] i tabellen: ";
           cin >> tabell[i][j]; 
        }
    }

  // Skriv ut resultatet
  cout << "Du har matat in följande tabell:" << endl;
  for ( int i = 0; i < n1; i++ )
    {
      for ( int j = 0; j < n2; j++ )
        {
           cout << tabell[i][j] << "\t"; 
        }
      cout << endl;
    }
  return 0;
}