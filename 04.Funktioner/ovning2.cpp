#include <iostream>
using namespace std;

//funktionsdeklaration
void berakna(int a, int b);//fyll i funktionsdeklarationen. Ledtråd: se funktionsanropet i main

int main()
{
   int a, b;

   cout << "Mata in två heltal: " << endl;
   cin >> a >> b;

   berakna(a, b);  //funktionsanrop med två värdeparametrar. Inget returvärde.

   return 0;
}

//funktionsdefinition
void berakna(int x, int y) //fyll i funktionshuvudet, dvs returtyp, funktionsnamn, ev. parametrar
{ // Satserna mellan { och } kallas för funktionens kropp.
   cout << "Talens summa är: " << x + y << endl;
   
   if(x > y)
   {
   	cout << "Talens differens är: " << x - y << endl;
   }
   else
   {
   	cout << "Talens differens är: " << y - x << endl;
   }

   cout << "Talens produkt är: " << x * y << endl;
   //Skall det finnas en return-sats här? Nej.
} //avsluta funktionen