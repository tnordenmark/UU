/*Skriv ett program som läser in ett flyttal (variabeln
flyttal) från tangentbordet och lagrar det sedan som ett
heltal (variabeln heltal), dvs tilldela heltalsvariabeln
värdet av flyttalsvariabeln.

Programmet skall sedan skriva ut heltalet.
Prova programmet genom att läsa in några olika flyttal,
t.ex.:

3.3, 3.7, -4.2, -4.7, 1.6e+4, 1.4e+4 och 1.4e-4.

Vad blir resultatet och varför?*/
#include <iostream>
using namespace std;

int main()
{
	float flyttal;
	int heltal;

	cout << "Ange ett flyttal: ";
	cin >> flyttal;

	heltal = flyttal;

	cout << "Talet är: " << heltal << endl;
	
	return 0;
}