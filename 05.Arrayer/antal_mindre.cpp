#include <iostream>
using namespace std;

int smallerThan(const double arr[], int antal, double specialtal);

const int MAX = 10;

int main()
{
	double arr[MAX];
	int antal, i, antal_mindre;
	double specialtal;

	cout << "Mata in antal tal som ska jämföras (max 10 st): ";
	cin >> antal;

	for(i = 0; i < antal; i++)
	{
		cout << "Ange tal " << i + 1 << ": ";
		cin >> arr[i];
    }

    cout << "Ange talet som ska jämföras: ";
    cin >> specialtal;

    antal_mindre = smallerThan(arr, antal, specialtal);
    cout << "Det finns " << antal_mindre << " tal i arrayen som är mindre än "
    << specialtal << "." << endl;
}

int smallerThan(const double arr[], int antal, double specialtal)
{
	int i;
	int count = 0;

	for (i = 0; i < antal; i++)
    {
    	if(arr[i] <= specialtal)
    	{
    		count++;
    	}
    }
    return count;
}
