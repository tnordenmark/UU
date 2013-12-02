// Filnamn : .../ex03.cc

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  double testData[100];
  string fileName;
  
  for ( int i=1; i<=100; i++ )
    testData[i-1] = i + i*0.001;

  cout << "Enter name of storing file : ";
  cin >> fileName;
  
  ofstream outFile( fileName.c_str() ); 
  outFile.write( (char*) &testData, sizeof(testData) );
  outFile.close();

  return 0;
}
