#include <iostream>
using namespace std;

int siffsum(int x);

int main()
{
	int x, sum;

	cout << "Mata in ett heltal för att beräkna siffersumman: ";
	cin >> x;

	sum = siffsum(x);
	cout << "Siffersumman av talet är: " << sum << endl;
}

int siffsum(int x)
{
	int y=0;

	while(x > 0)
	{
		y += x%10;
		x /= 10;
	}
	return y;
}