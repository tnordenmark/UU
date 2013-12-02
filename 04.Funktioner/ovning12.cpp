#include <iostream>
using namespace std;

void byt(float &tal1, float &tal2);

int main()
{
	float ch1, ch2;

	cout << "Mata in tal 1: ";
	cin >> ch1;
	cout << "Mata in tal 2: ";
	cin >> ch2;

	byt(ch1, ch2);

	cout << "Tal 1 har nu värdet: " << ch1 << endl;
	cout << "Tal 2 har nu värdet: " << ch2 << endl;

	return 0;
}

void byt(float &tal1, float &tal2)
{
	float temp = tal1;
	tal1 = tal2;
	tal2 = temp;
}