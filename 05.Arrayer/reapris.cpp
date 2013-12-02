#include <iostream>
using namespace std;

const int MAX = 20;

int main()
{
	double pris[MAX];
	int rea[MAX];
	int antal, i;

	cout << "Hur många artiklar? ";
	cin >> antal;

	for(i = 0; i < antal; i++)
	{
		cout << "Ange pris på artikel nr " << i + 1 << ": ";
		cin >> pris[i];
    }

    cout << endl;
    cout << "Ange reastatus på artiklarna. 1 för ja, 0 för nej." << endl;
    cout << "##################################################" << endl
    << endl;

    for(i = 0; i < antal; i++)
	{
		cout << "Ange reastatus på artikel nr " << i + 1 << ": ";
		cin >> rea[i];
    }

    cout << endl;

    for(i = 0; i < antal; i++)
    	if(rea[i] == 1)
    	{
    		pris[i] = 0.70 * pris[i];
    	}
    	
    	cout << "Nya priser:" << endl;
    	cout << "###########" << endl << endl;

    	for(i = 0; i < antal; i++)
    	{
    		cout << "Nytt pris på artikel nr " << i + 1 << ": "
    		<< pris[i] << endl;
    	}

    return 0;
}