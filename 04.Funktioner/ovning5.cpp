#include <iostream>
using namespace std;

int berakna(int a, int b);  //fyll i funktionsdeklarationen för berakna

int main()
{
      int resultat, a, b;
      cout << "Mata in två heltal: ";
      cin >> a >> b;
      
      resultat = berakna(a, b);    //fyll i det som fattas när berakna anropas
      cout << "produkten blir: " << resultat << endl;

      return 0;
}

int berakna(int a, int b)
{
	int produkten;
	produkten = a * b;
	return produkten;
}  //Skriv funktionsdefinitionen själv
