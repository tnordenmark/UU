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
  Villa *v1, *v2;

  // Två objekt kommer in till fastighetsförmedlingen:

  v1 = new Villa("Ekvägen 123", 1000000);  
  v2 = new Villa("Alvägen 12", 1200000);   

  // Vi säljer genast villa "v1".

  delete v1;   // Lämna tillbaka det minne v1 pekar på
  v1 = 0;      // Sätt pekaren till NULL.

  // Skriv info om våra objekt om det går, dvs
  // om pekarna pekar på något (dvs är nollskilda).

  cout << "---Skriv info om villorna" << endl;

  if ( v1 != 0 )
    {
      v1->skriv(); cout << endl;
    }
  else
    cout << "Villan fanns ej!" << endl;

  if ( v2 != 0 )
    {
      v2->skriv(); cout << endl;
    }
  else
    cout << "Villan fanns ej!" << endl;

  // Sälj alla villor för skojs skull...
  // utan att kolla om de finns eller ej.

  delete v1;
  delete v2;  // Vi får göra delete på noll-pekare,
              // men inget händer.
  
  // Ha för vana sätta pekare till NULL efter delete.
  // I allafall om programmet är större; nu slutar det ju.

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

/*Körning:
---Skriv info om villorna
Villan fanns ej!
 Adress = Alvägen 12, pris = 1200000

*/
