// Filnamn: .../cstring03.cc
// Exempel på sträng till tal

#include <iostream.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
  char ns1[20] , ns2[20];
  strcpy( ns1,"38" );          // ns1 has string value "38"
  strcpy( ns2,"3.14" );        // ns2 has string value "3.14"

  int i = atoi( ns1 );         // conversion of str to int
  double d = atof( ns2 );      // conversion of str to double

  cout << "Value of int i : " << i << endl;
  cout << "Value of double d : " << d << endl;
  return 0;
}
