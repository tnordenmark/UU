// Filnamn: .../cstring04.cc
// Exempel på omvandling från tal till sträng
#include <iostream.h>
#include <string.h>

int main() {
  char ns1[20] , ns2[20];

  int i = 38; 
  double d = 3.14; 

  sprintf(ns1,"%6d",i);     // conversion of int to string
  sprintf(ns2,"%8.3f",d);   // conversion of double to string

  cout << "Value of ns1 : " << ns1 << endl;
  cout << "Value of ns2 : " << ns2 << endl;
  return 0;
}
