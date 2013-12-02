// Filnamn: .../power2.cc
#include <iostream>
using namespace std;

double power( double x, int n=2 ) { // default parameter
   double p = 1.0;
   for (int i=1; i<=n; i++) {
          p *=x;
   }
   return p;
}

int main() {
   cout << "Call 1 : " << power( 3.5 , 3 ) << endl;
   cout << "Call 2 : " << power( 3.5 , 2 ) << endl;
   cout << "Call 3 : " << power( 3.5 ) << endl;
   return 0;
}
