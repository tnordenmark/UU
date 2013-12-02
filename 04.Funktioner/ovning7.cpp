#include <iostream>
using namespace std;

void berakna(int &summa, int &differens);  //fyll i funktionsdeklarationen

int main()
{
      int summa, differens;

      berakna(summa, differens); //skriv funktionsanropet

      cout << "Talens summa är: " << summa << endl;
      cout << "Talens differens är: " << differens << endl;

      return 0;
}

void berakna(int &summa, int &differens)
{
	int a, b;

	cout << "Mata in två heltal: " << endl;
	cin >> a >> b;

	summa = a + b;
	differens = a -b;
}  //Skriv funktionsdefinitionen själv. OBS: inmatningen av de två 
     //talen skall ske i funktionen, inte i main.