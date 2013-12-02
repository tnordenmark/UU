#include <iostream>
using namespace std;

// Funktionsdeklaration
void greetings();   //fyll i funktionens returtyp. Ledtråd: skall något 
                   //returneras från funktionen?
                   //Observera den tomma parameterlistan: inga in-
                   // eller ut parametrar. Vad menas med det?

int main()
{

      cout << "Jag hälsar på dej!" << endl;

      greetings();    //fyll i funktionsanropet

      cout << "Vi ses!" << endl;

      return 0;
}

//funktionsdefinition
void greetings()  //fyll i funktionshuvudet
{
      int antal_varv;

      cout << "Hur många gånger vill Du bli hälsad?" << endl;
      cin >> antal_varv;

      for (int i=0; i<antal_varv; i++)
          cout << " HEJ!" << endl;
}