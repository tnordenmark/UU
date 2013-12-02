// rek1.cpp
#include<iostream>
using namespace std;

int doWhat( int a[], int n );

int main()
{
  const int SIZE = 5;
  int x[SIZE];

  cout << "Ge " << SIZE << " heltal:" << endl;

  for ( int i = 0; i < SIZE; i++ )
    cin >> x[i];

  cout << "Resultatet blev: " << doWhat( x, SIZE) << endl;
  return 0;
}

int doWhat( int a[], int n )
{
  if ( n == 1 )
    return a[0];
  else
    return a[n-1] + doWhat( a, n-1 );
}

/* Körningsexempel:

Ge 5 heltal:
1 6 3 8 7
Resultatet blev: 25

Ge 5 heltal:
1 2 3 4 5
Resultatet blev: 15

Ge 5 heltal:
2 2 2 2 2
Resultatet blev: 10
*/
