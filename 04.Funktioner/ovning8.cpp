#include <iostream>
using namespace std;

int min(int x, int y);

int main()
{
	int a, b, resultat;

	cout << "Mata in två heltal: " << endl;
	cin >> a >> b;

	resultat = min(a, b);
	cout << "Det minsta talet är: " << resultat << endl;

	return 0;
}

int min(int x, int y)
{
	if(x > y)
		return y;
	else
		return x;
}