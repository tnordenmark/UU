#include <iostream>
using namespace std;

void min_max(int x, int y, int &max, int &min);

int main()
{
	int a, b, max, min;

	cout << "Mata in två heltal: " << endl;
	cin >> a >> b;

	min_max(a, b, max, min);

	cout << "Det största talet är: " << max << endl;
	cout << "Det minsta talet är: " << min << endl;
}

void min_max(int x, int y, int &max, int &min)
{
	if(x > y)
	{
		max = x;
		min = y;
	}
	else
	{
		max = y;
		min = x;
	}
}