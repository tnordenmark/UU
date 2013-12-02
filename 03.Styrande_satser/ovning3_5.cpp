#include <iostream>
using namespace std;

int main()
{
    int sum, i, tal;

    sum = 0;
    
    for(i=0; i<5; i++)
    {
        cout << "Mata in tal: ";
        cin >> tal;

        sum += tal;
    }

    cout << "Summan av talen är: " << sum << endl;

    return 0;
}