/*Skriv ett program som läser in två heltal (variabeln  tal1
respektive tal2). Beräkna sedan tal1/tal2 och
float(tal1)/tal2 samt skriv ut resultaten.
Testa programmet med lite olika värden på tal1 och tal2,
t.ex. 3 och 4, 5 och 3, -3 och 4, samt 5 och 0.

Vad blir resultatet? Och varför?*/
#include <iostream>
using namespace std;

int main()
{
	int tal1, tal2;

	cout << "Ange två heltal separerade med mellanslag: ";
	cin >> tal1 >> tal2;

	cout << tal1 << "/" << tal2 << " = " << tal1/tal2 << endl;
	
	cout << "float(" << tal1 << ")" << "/" 
		<< tal2 << " = " << float(tal1)/tal2 << endl;

	return 0;
}