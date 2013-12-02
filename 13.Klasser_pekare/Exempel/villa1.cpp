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
  const int MAX=100;

  Villa *villor[MAX];   // Array av pekare till 
                        // många Villa-objekt.

  for ( int i = 0; i < MAX; i++ ) 
    {
      villor[i] = 0;   // Bra att nollställa pekararrayen.
    }

  int antal;         // Antal villor idag.

  do                 // Kontroll på inläsningen
    {
      cout << "Hur många villor?" << endl;
      cin >> antal;
    } while( antal <= 0 || antal > MAX);

  // Skapa lite villor, dvs simulering av att
  // objekt kommer in till försäljning.

  villor[0] = new Villa("Ekvägen 123", 1000000); 
  villor[1] = new Villa("Alvägen 12", 1200000); 
  villor[antal-1] = new Villa("Hävelvägen 7", 130000);

  // Bums säljer vi Ekvägen.
  cout << "---Nu säljer vi första villan" << endl;
 
  delete villor[0];     
  villor[0] = 0;     

  // Skriv ut de villor som finns kvar till
  // försäljning.

  for ( int i = 0; i < antal; i++ ) 
    {
      if ( villor[i] != 0 ) 
	{
	  cout << "---Objekt nr " << i+1 << " ";
	  villor[i]->skriv(); cout << endl;
	}
    }
  
  // En konkurrerande mäklarfirma
  // köper upp alla villaobjekt!

  for ( int i = 0; i < antal; i++ ) 
    {
      // Behöver ej kolla vilka pekare 
      // som är NULL. Man får göra delete 
      // på noll-pekare, fast inget händer...,
      // men det förenklar programmeringen.

      delete villor[i]; 
    }

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


/*Körningsexempel:

Hur många villor?
300
Hur många villor?
-4
Hur många villor?
8
---Nu säljer vi första villan
---Objekt nr 2  Adress = Alvägen 12, pris = 1200000
---Objekt nr 8  Adress = Hävelvägen 7, pris = 130000
*/
