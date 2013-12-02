// Filnamn : .../ex02b.cc

#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inFile( "exempel.dat" );
  string line;

  while ( getline(inFile, line) ) {
    cout << line << endl;
  }
  inFile.close();
  return 0;
}
