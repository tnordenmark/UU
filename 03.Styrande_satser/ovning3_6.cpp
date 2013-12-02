#include <iostream>
using namespace std;

int main()
{
    int sum, i, tal;

    sum = 0;
    tal = 0;
    i = 0;

    while(tal>=0)
    {
        cout << "Mata in tal: ";
        cin >> tal;

        if(tal>=0)
        {
            sum += tal;
            i = i + 1;
        }
        else
        {
            cout << "Du har skrivit ett negativt tal." << endl;
            cout << "Du har matat in " << i << " tal och summan är "
            << sum << "." << endl;
        }
    }

    return 0;
}