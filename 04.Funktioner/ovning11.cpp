#include <iostream>
using namespace std;

char LasTecken();

int main()
{
	char svar;
	svar = LasTecken();

	cout << "Du skrev in följande tecken: " << svar << endl;

	return 0;
}

char LasTecken()
{
	char tecken;
	char t1='A';
	char t2='B';
	char t3='C';

	cout << "Mata in " << t1 << ", " << t2 << " eller "
	<< t3 << ": " << endl;

	cin >> tecken;

	while(! ( (tecken==t1 || tecken==t2 || tecken==t3)))
	{
		cout << "Fel tecken!" << endl;
		cout << "Mata in " << t1 << ", " << t2 << " eller "
		<< t3 << ": " << endl;
		cin >> tecken;
	}
	return tecken;
}