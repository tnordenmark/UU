// Filnamn : .../ex01.cc

#include <iostream>
#include <fstream>
using namespace std;

int main() {
  const double magicNum = 123456789.123456789;
  ofstream outFile( "exempel.dat" );
  
  outFile << "Hej från program ex01.cc" << endl;
  outFile << "En double ser ut så här: " << magicNum << endl;
  outFile << endl;
  outFile << "Ajöss och tack för fisken!" << endl;
  
  outFile.close();
  return 0;
}
