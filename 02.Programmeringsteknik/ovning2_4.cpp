/*Programmet ovan utför s.k. trunkering, dvs decimalerna
kastas bort. Modifiera det så att det avrundar till ett
heltal.

Testa programmet genom att läsa in några olika flyttal, t.ex.
3.3, 3.7, 1.6e+4, 1.4e+4 och 1.4e-4.

Prova sedan att läsa in -4.2 och -4.7.

Vad händer och varför?*/
#include <iostream>
using namespace std;

int main()
{
	float flyttal;
	int heltal;

	cout << "Ange ett flyttal: ";
	cin >> flyttal;

	heltal = (flyttal+0.5);

	cout << "Talet är: " << heltal << endl;
	
	return 0;
}