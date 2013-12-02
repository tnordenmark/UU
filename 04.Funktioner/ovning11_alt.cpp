#include <iostream>
using namespace std;

char LasTecken(char ch1, char ch2, char ch3);

int main()
{
	char svar;
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	svar = LasTecken(ch1, ch2, ch3);

	cout << "Du skrev in följande tecken: " << svar << endl;

	return 0;
}

char LasTecken(char ch1, char ch2, char ch3)
{
	char tecken;

	cout << "Mata in " << ch1 << ", " << ch2 << " eller "
	<< ch3 << ": " << endl;

	cin >> tecken;

	while(! ( (tecken==ch1 || tecken==ch2 || tecken==ch3)))
	{
		cout << "Fel tecken!" << endl;
		cout << "Mata in " << ch1 << ", " << ch2 << " eller "
		<< ch3 << ": " << endl;
		cin >> tecken;
	}
	return tecken;
}