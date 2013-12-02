#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

// testabildaeck.cpp

//--- Klassen daeck representerar ett bildäck.---

const double MAXdjup = 20.00; // 20 mm

class daeck
{
private:
  double djup;        // Mönsterdjup = antal mm gummi.

public:
  daeck();
  daeck( double indjup );
  double haemta_djup();
  int slitage( double slitdjup ); // Slit på däcken om det går.
  void skriv();
};

int main()
{
  // Skapa några bildäck och testa lite:
  cout << "Testa lite med däcksklassen:" << endl;
  daeck hf, vf, hb, vb;
  
  // Skriv ut ursprungsdjupet
  hf.skriv();
  vf.skriv();
  hb.skriv();
  vb.skriv();
  cout << endl;

  // Slit lite på däcken
  hf.slitage(10.00);
  vf.slitage(5.00);
  hb.slitage(7.00);
  vb.slitage(3.00);

  // Skriv ut resultatet efter slitage
  cout << "Nu sliter vi lite på däcken:" << endl;
  hf.skriv();
  vf.skriv();
  hb.skriv();
  vb.skriv();
  cout << endl;

  return 0;
}  

//---Implementation av däckmetoder.---

//---Konstruktorer:

daeck::daeck()
: djup(MAXdjup)
{}

daeck::daeck( double indjup )
: djup(indjup)
{}

//---Selektorer: 

double daeck::haemta_djup()
{
  return djup;
}

//---Andra metoder:

int daeck::slitage( double slitdjup )
{
  // Slit ned "slitdjup" mycket av
  // gummit (om det går).
  // Returnera 1 om allt gummi slut,
  // annars 0.

  int slutgummi = 0;

  if ( djup - slitdjup < 0 )
    {
      djup = 0;
      slutgummi = 1;
    }
  else
    djup -= slitdjup;

  return slutgummi;
}

void daeck::skriv()
{
  cout.setf( ios::fixed );
  cout << " däck = " << setprecision(1) << djup;
}
/* Körningsexempel:

Testa lite med däcksklassen:
 däck = 20.0 däck = 30.0
Nu sliter vi lite på dem...
 däck = 18.5 däck = 27.5

 */
