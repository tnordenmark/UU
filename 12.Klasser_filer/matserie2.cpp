#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// matserie2.cpp
// Statisk allokering av flera mätserier 
// i samma klass.
//
// Här kommer "d" att fungera som
// en 2-dim matris med element d[s][i],
// där 1:a dimensionen är fix=MAXANTAL
// och 2:a dimensionen är dynamisk.


const int MAXANTAL = 100;

class SMatserier 
{
private:
  double *d[MAXANTAL]; // 100 st pekare till double.
  int antal[MAXANTAL]; // hör ihop med "d"
  int antalserier;     

 public:
  SMatserier();
  ~SMatserier();
  void laes( istream &is );
  void skriv( ostream &os );
  double medel( int serienummer );
  int antalSerier();
};

SMatserier:: SMatserier()
  : antalserier(0)
{
  // Sätt nollpekare och nollantal:

  for ( int s = 0; s < MAXANTAL; s++ )
    {
      d[s] = 0; // NULL-pekare. Tom dynamisk array.
      antal[s] = 0;
    }
}

SMatserier:: ~SMatserier()
{
  for ( int s = 0; s < antalserier; s++ )
    {
      delete[] d[s]; // d[s] är dynamisk array!
    }
}

void SMatserier:: laes( istream &is )
{
  is >> antalserier;

  // När vi vet antalet mätserier, så kan vi ju
  // läsa med for-loop.

  for ( int s = 0; s < antalserier; s++ )
    {
      is >> antal[s];

      d[s] = new double[antal[s]];

      for ( int i = 0; i < antal[s]; i++ )
	{
	  is >> d[s][i];
	}
    }
}

void SMatserier:: skriv( ostream &os )
{
  os << antalserier << endl;

  for ( int s = 0; s < antalserier; s++ )
    {
      os << antal[s];      

      for (int i=0; i < antal[s]; i++)
	os << " " << d[s][i];

      os << endl;
    }
}

double SMatserier:: medel( int serienummer )
{
  double sum = 0;

  for ( int i = 0; i < antal[serienummer]; i++ )
    sum += d[serienummer][i];

  return sum / double(antal[serienummer]);
}

int SMatserier:: antalSerier()
{
  return antalserier;
}
//------------------------

int main()
{
  ifstream fin("matserier");
  SMatserier vaerden;

  vaerden.laes( fin );
  vaerden.skriv( cout );

  for ( int i = 0; i < vaerden.antalSerier(); i++ )
    cout << "medelvärdet för serie " 
	 << i << " är " << vaerden.medel(i) <<endl;

  return 0;
}

/*
3
8 3.4 5.6 1.2 3.5 1.8 6.7 3.4 3.9
3 1.2 1.5 1.3
5 5.6 7.8 3.4 5.6 4.5
medelvärdet för serie 0 är 3.6875
medelvärdet för serie 1 är 1.33333
medelvärdet för serie 2 är 5.38
*/


