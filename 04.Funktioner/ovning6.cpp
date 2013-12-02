#include <iostream>
using namespace std;

void berakna(int x, int y, int &summa, int &differens);  //fyll i parameterlistan i funktionsdeklarationen

int main()
{
      int a, b, summa, differens;

      cout << "Mata in två heltal: " << endl;
      cin >> a >> b;

      berakna(a, b, summa, differens);  //fyll i det som saknas i main

      cout << "Talens summa är: " << summa << endl;
      cout << "Talens differens är: " << differens << endl;

      return 0;
}

void berakna(int x, int y, int &summa, int &differens)
{
	summa = x + y;
	differens = x - y;
}  	//Skriv funktionsdefinitionen själv. Skall det finnas någon return-sats?
	//Svar: Nej, både summa och differens är referensparametrar.