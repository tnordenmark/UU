#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// matserie1.cpp
// Dynamisk allokering


class DMatserie 
{
 private:
  double *d;
  int antal;

 public:
  DMatserie();
  ~DMatserie();
  void laes( istream &is );
  void skriv( ostream &os );
  double medel();
};


DMatserie:: DMatserie()
  : antal(0), d(0)
{}

DMatserie:: ~DMatserie()
{
  delete [] d;
}

void DMatserie:: laes( istream &is )
{
  is >> antal;
  d = new double[antal]; //Så mycket vi behöver bara

  for ( int i = 0; i < antal; i++ )
    is >> d[i];
}

void DMatserie:: skriv( ostream &os )
{
  os <<  antal;

  for ( int i = 0; i < antal; i++ )
    os << " " << d[i];

  os << endl;
}

double DMatserie:: medel()
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
  DMatserie vaerden;

  vaerden.laes( fin );
  vaerden.skriv( cout );

  cout << "Medelvärdet är "
       << vaerden.medel() 
       << endl;

  return 0;
}
