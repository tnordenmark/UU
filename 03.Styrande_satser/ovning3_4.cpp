#include <iostream>
using namespace std;

int main()
{
    int sum, i, tal;

    sum = 0;
    i = 1;
    
    while(i<=5)
    {
        cout << "Mata in tal: ";
        cin >> tal;

        sum += tal;
        i = i + 1;
    }

    cout << "Summan av talen är: " << sum << endl;

    return 0;
}