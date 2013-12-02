//  Filnamn: .../maxover.cc
#include <iostream>
using namespace std;

int    max( int, int );
int    max( int, int, int );
double max( double, double );
double max( double, double, double );

int main() {
  cout  << " max of 6 3 : " << max(6,3) << "\n";
  cout  << " max of 2 6 3 : " << max(2,6,3) << "\n";
  cout  << " max of 3.5 6.5 : " << max(3.5,6.5) << "\n";
  cout  << " max of 9.8 3.5 6.5 : " << max(9.8,3.5,6.5) << "\n";
  return 0;
}

int max( int a,int b ) {
  if   ( a>b )  return a;
  else          return b;
}

int max( int a,int b,int c ) {
  int temp;
  if   ( a>b )  temp = a;
  else          temp = b;
  if ( temp>c ) return temp;
  else          return c;
}

double max( double a,double b ) {
  if   ( a>b )  return a;
  else          return b;
}

double max( double a,double b,double c ) {
  return  max( a, max(b,c) );
}
