#include <iostream>
using namespace std;

int main()
{
    int i, n;

    cout << "Ange antal platser i arrayen: ";
    cin >> n;

    int *array = 0;
    array = new int[n];

    cout << "Ange " << n << " st heltal: ";
    for(i = 0; i < n; i++)
        cin >> *(array + i); // Eller array[i]

    for(i = 0; i < n; i++)
    {
        cout << *(array + i) << "\t";
        if((i + 1) % 5 == 0)
            cout << endl;
    }
    cout << endl;

    // Kopiera array till nyarray
    int *nyarray;
    nyarray = new int[n];

    for(i = 0; i < n; i++)
        nyarray[i] = array[i];

    for(i = 0; i < n; i++)
    {
        cout << *(nyarray + i) << "\t"; // Eller nyarray[i]
        if((i + 1) % 5 == 0)
            cout << endl;
    }
    cout << endl;

    delete []array;
    delete []nyarray;

    return 0;
}
