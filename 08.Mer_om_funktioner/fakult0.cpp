// fakult0.cpp
#include<iostream>
using namespace std;

int fakult0 ( int n );
int fakultet( int n );

int main()
{
  int heltal;
  cout << "Ge ett heltal (ej för stort!): ";
  cin >> heltal;

  cout << "Resultat med fakult0: " << fakult0( heltal ) << endl;
  cout << "Resultat med fakultet: " << fakultet( heltal ) << endl;
  return 0;
}

int fakult0 ( int n )
{
  int prod = 1;
  
  for ( int i = 2; i <= n; i++ )
    prod *= i;

  return prod;
}

int fakultet( int n )
{
  if ( n <= 1 )
    return 1;
  else
    return n*fakultet(n-1);
}

/* Körningsexempel:
Ge ett heltal (ej för stort!): 4
Resultat med fakult0: 24
Resultat med fakultet: 24
*/
