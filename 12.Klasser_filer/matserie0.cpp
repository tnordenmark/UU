#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// matserie0.cpp
// Statisk allokering

const int MAXANTAL = 100;

class SMatserie 
{
 private:
  double d[MAXANTAL];
  int antal;

 public:
  SMatserie();
  void laes( istream &is );
  void skriv( ostream &os );
  double medel();
};


SMatserie:: SMatserie()
  : antal(0)
{}

void SMatserie:: laes( istream &is )
{
  is >> antal;

  for ( int i = 0; i < antal; i++ )
    is >> d[i];
}

void SMatserie:: skriv( ostream &os )
{
  os <<  antal;

  for ( int i = 0; i < antal; i++ )
    os << " " << d[i];

  os << endl;
}

double SMatserie:: medel()
{
  double sum = 0;

  for ( int i = 0; i < antal; i++ )
    sum += d[i];

  return sum/double(antal);
}

//---main0--

int main()
{
  ifstream fin( "matserie" );
  SMatserie vaerden;
  vaerden.laes( fin );
  vaerden.skriv( cout );
  cout << "Medelvärdet är "
       << vaerden.medel() 
       << endl;

  return 0;
}
