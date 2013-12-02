/*Testa att mata in lite olika tecken, exempelvis bokstäver,
siffror eller andra tecken som finns på tangentbordet.
Vad skrivs ut och varför?*/
#include <iostream>
using namespace std;

int main()
{
	char tecken, tecken1;
	int tal;
	cout << "Mata in ett tecken: ";
	cin >> tecken;

	tal = int(tecken); // gör heltal av tecken

	cout << "Heltal av tecken=" << tal<< endl;
	cout << "Tecken=" << tecken<< endl;

	tecken1 = char(tal+1);  //  gör tecken av heltal
	cout << "Tecken1=" << tecken1<< endl;
	
	return 0;
}
