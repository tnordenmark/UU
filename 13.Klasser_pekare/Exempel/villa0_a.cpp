#include <iostream>
#include <string>
using namespace std;

class Villa 
{
private:
  string adress;
  int pris;

public:
  Villa();
  Villa( string inAdress, int inPris );
  void skriv();
};

int main()
{
  // Två objekt finns inne på fastighetsförmedlingen:

  Villa villa1("Ekvägen 123", 1000000);  
  Villa villa2("Alvägen 12", 1200000);   

  // Vi låter pekare peka ut dem.

  Villa *v1, *v2;
  v1 = &villa1;
  v2 = &villa2;

  cout << "---Skriv info om villorna" << endl;

  v1->skriv(); cout << endl;
  v2->skriv(); cout << endl;

  // Sälj alla villor för skojs skull...
  // Vi tar bort själva pekandet, men egentligen
  // ligger villorna kvar i minnet, eftersom vi
  // deklarerade dem statiskt som "villa1" och "villa2".

  v1 = 0;
  v2 = 0;

  return 0;
}


Villa::Villa()
  : adress("Ingen"), pris(0)
{}

Villa::Villa( string inAdress, int inPris )
  : adress(inAdress), pris(inPris)
{}

void Villa::skriv()
{
  cout << " Adress = " << adress 
       << ", pris = "  <<  pris;
}

/* Körning:
---Skriv info om villorna
 Adress = Ekvägen 123, pris = 1000000
 Adress = Alvägen 12, pris = 1200000
*/
