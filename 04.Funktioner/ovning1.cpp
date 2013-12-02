#include <iostream>
using namespace std;

// Funktionsdeklaration:
// En in-parameter (s.k. värdeparameter): antal
// Inget returvärde, dvs void

void greetings(int varv);

int main()  //huvudprogram
{
      int antal;

      cout << "Jag hälsar på dej!" << endl;
      cout << "Hur många gånger vill Du bli hälsad?" << endl;
      cin >> antal;  // main frågar efter antalet

      // Värdet av antal skall skickas till funktionen
      greetings(antal); //fyll i funktionsanropet

      cout << "Vi ses!" << endl;

      return 0;
}

// Funktionsdefinition
void greetings(int varv)  //fyll i parameterlistan
{
      for ( int i = 0; i < varv; i++ )
          cout << " HEJ!" << endl;
} //Varför avslutas inte funktionen med en return-sats?
  //Svar: den har returntypen void och returnerar alltså inget.
