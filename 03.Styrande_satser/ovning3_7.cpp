#include <iostream>
using namespace std;

int main()
{
    int sum, i, tal, max;

    sum = 0;
    tal = 0;
    max = 0;

    for(i=0; i<10; i++)
    {
        cout << "Mata in tal: ";
        cin >> tal;

        sum += tal;

        if(tal > max)
        {
            max = tal;
        }
    }

    cout << "Du har matat in " << i << " tal och summan är "
            << sum << "." << endl;
    cout << "Det största talet är: " << max << endl;

    return 0;
}