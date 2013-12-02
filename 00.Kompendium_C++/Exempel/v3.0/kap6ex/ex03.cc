// Filnamn: .../ex03.cc

#include <iostream>
#include <cmath>
using namespace std;

double tangens ( double );  // deklaration

int main( void ) {
   cout << "table of sin, cos and tangens: " << endl;

   for ( double x=0.0; x<=1.2; x +=0.1 ) {
         cout << x << " " << sin(x) << " " << cos(x);
         cout << " " << tangens(x) << endl ;
   }
   return 0;
}

double tangens ( double v ) // definition
{
  if (fabs(cos(v))<1e-6) 
     return 1e6;
  else
     return sin(v)/cos(v);
}
