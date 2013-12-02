// Filnamn : .../kap12ex/ex04.cc

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  string fileName;
  
  cout << "Enter name of file to read from : ";
  cin >> fileName;

  double test[100];
  ifstream inFile( fileName.c_str() );

  inFile.read( (char*) &test, sizeof(test) );
  inFile.close();

  for ( int i=1; i<=5; i++ )
    cout << test[i-1] << endl;

  return 0;
}
