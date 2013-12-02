#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

// testabilbensintank.cpp

class bensintank
{
private:
  double liter;      // Antal liter bensin i tanken.
  double volym;      // Max antal liter, dvs tankens "volym".

public:
  bensintank();
  bensintank( double lit );  // Full tank (volym=liter).
  bensintank( double lit, double vol );
  double haemta_liter();
  void foerbruka( double & lit ); // Bensinen minskar 
                                  // om det går.
  void skriv();				    
};

int main()
{
  cout << "Testa lite med bensintanksklassen:" << endl;

  bensintank saab;
  bensintank volvo( 300.0 ), ford( 350.0, 500.0 );

  saab.skriv();
  volvo.skriv();
  ford.skriv();
  cout << endl;

  cout << "Nu förbrukar vi lite bensin: " << endl;

  double bensinliter;

  bensinliter = 45.0;
  saab.foerbruka( bensinliter);
  bensinliter = 45.0;
  volvo.foerbruka( bensinliter);
  bensinliter = 745.0;
  ford.foerbruka( bensinliter );

  saab.skriv();
  volvo.skriv();
  ford.skriv();
  cout << endl;

  return 0;
}
//--- Konstruktorer:

bensintank::bensintank()
  : liter(0), volym(0)
{}

bensintank::bensintank( double lit )
  : liter(lit), volym(lit)
{}

bensintank::bensintank( double lit, double vol )
  : liter(lit), volym(vol)
{}

//---Selektorer:

double bensintank::haemta_liter()
{
  return liter;
}

//---Andra metoder:

void bensintank::foerbruka( double & lit )
{
  // Vi vill förbruka "lit" antal liter.
  // Om detta ej går, så förbruka så mycket som möjligt.
  // Ändra i så fall värdet på "lit", ty referensparameter.
 
  if ( lit > liter )
    {
      cout << "Soppatorsk! Bilen slukar " << liter 
	   << " liter fast du ville " << lit << " liter." << endl;
      lit = liter;  // Tanka så mycket det går.
      liter = 0;    // Tom tank;

    }
  else
    liter -= lit;
}

void bensintank::skriv()
{
  cout.setf( ios::fixed );
  cout << setw(5) << setprecision(1) << liter << " liter ";
}  
/*
Körningsexempel:

Testa lite med bensintanksklassen:
  0.0 liter 300.0 liter 350.0 liter 
Nu förbrukar vi lite bensin: 
Soppatorsk! Bilen slukar 0.0 liter fast du ville 45.0 liter.
Soppatorsk! Bilen slukar 350.0 liter fast du ville 745.0 liter.
  0.0 liter 255.0 liter   0.0 liter 
*/
