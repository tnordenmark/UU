// Filnamn: .../maxdekl.cc

#include <iostream>
using namespace std;

int max ( int a, int b ); // deklaration

int main() {
   int tal1, tal2;
   cout << "Give two numbers : ";
   cin >> tal1 >> tal2;
   cout << "The largest of " << tal1 << " and " << tal2 ;
   cout << " is " << max(tal1,tal2) << endl;
   return 0;
}

int max ( int a, int b )  { // definition
  if ( a > b ) 
     return a;
  else 
    return b;
}
