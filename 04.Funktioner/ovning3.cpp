#include <iostream>
using namespace std;

int produkt(int a, int b);  //fyll i funktionsdeklarationen. Ett heltal returneras från funktionen.
     						//Vilken typ bör den då ha? int = heltal.

int main()
{
      int a, b, produkten;

      cout << "Mata in två heltal: " << endl;
      cin >> a >> b;

      produkten = produkt(a, b);//fyll i det som saknas i main

      cout << "Produkten blir: " << produkten << endl;  

      return 0;
}
      
int produkt(int a, int b) //Skriv funktionsdefinitionen själv
{
	int produkten;
	produkten = a * b;
	return produkten;
}