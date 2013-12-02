#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// matserie3.cpp
// Statisk allokering av flera mätserier 
// i samma klass.
//
// Här kommer "d" att fungera som
// en 2-dim dynsmisk matris med 
// element d[s][i], där 1:a dimensionen och
// och 2:a dimensionen är dynamiska.


class DMatserier 
{
private:
  double **d;  // pekare till pekare (array av pekare)
  int *antal;  // hör ihop med "d"
  int antalserier;     
  void deallocate(); // hjälpmetod, privat

 public:
  DMatserier();
  ~DMatserier();
  void laes( istream &is );
  void skriv( ostream &os );
  double medel( int serienummer );
  int antalSerier();
};

DMatserier:: DMatserier()
  : antalserier(0), d(0), antal(0)
{}

DMatserier:: ~DMatserier()
{
  deallocate(); // Anrop av privat metod i samma klass
}

void DMatserier:: deallocate()
{
  // Lämna tillbaka minne, dvs det som pekarna
  // pekar på.

  for (int i=0; i < antalserier; i++)
    {
      delete[] d[i]; 
    }

  delete[] d;
  delete[] antal;
}

void DMatserier:: laes( istream &is )
{
  deallocate();
  is >> antalserier;

  d = new double*[antalserier];
  antal = new int[antalserier]; 

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

void DMatserier:: skriv( ostream &os )
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

double DMatserier:: medel( int serienummer )
{
  double sum = 0;

  for ( int i = 0; i < antal[serienummer]; i++ )
    sum += d[serienummer][i];

  return sum / double(antal[serienummer]);
}

int DMatserier:: antalSerier()
{
  return antalserier;
}
//------------------------

int main()
{
  ifstream fin("matserier");
  DMatserier vaerden;

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


