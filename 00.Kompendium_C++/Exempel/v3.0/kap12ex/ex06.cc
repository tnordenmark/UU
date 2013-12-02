// Filnamn : .../ex06.cc

#include <iostream>
#include <fstream>
using namespace std;

class Dummy {
public:
  Dummy( int n=0, double vx=0.0, double vy=0.0);
  void            WriteFile( string FileName);
  void            ReadFile( string FileName );

protected:
  double                  x[100];
  double                  y[100];
  int                     num;

};
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main() {
  Dummy D( 10,1,2 );

  D.ReadFile("DummyFile.dat");    // read from file ?
  D.WriteFile("DummyFile.dat");   // write to file
  D.ReadFile("DummyFile.dat");    // read from file
  return 0;
}
//-----------------------------------------------------------
Dummy::Dummy(int n, double vx, double vy) {
  for (int i=0; i<=n; i++ ) {
    x[i] = vx; y[i]=vy;
  }

  num=n;
}
//-----------------------------------------------------------
void Dummy::WriteFile( string FileName ) {
  ofstream outFile( FileName );
  outFile.write( (char*) this, sizeof(*this) );
}
//-----------------------------------------------------------
void Dummy::ReadFile( string FileName ) {
 ifstream inFile( FileName );
 if ( inFile.good() ) {
   cout << "Reading data from file " << FileName << endl;
   inFile.read( (char*) this, sizeof(*this) );
 }
 else
   cout << "No data to read from file " << FileName << endl;
}
//-----------------------------------------------------------
