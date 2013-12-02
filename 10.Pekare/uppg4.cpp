#include <iostream>
#include <string>
using namespace std;

double *laes(int &n)
{
    cout << "Ge ett heltal: ";
    cin >> n;

    double *array = 0;
    array = new double[n];

    cout << "Ge " << n << " st flyttal: ";
    for(int i = 0; i < n; i++)
        cin >> *(array + i);

    return array;
}

double *sort(const double *arr, int antal)
{
    double *x;
    x = new double[antal];
    int i;
    // Kopiera arr till x (behåll arr oförändrad)
    for(i = 0; i < antal; i++)
        *(x + i) = *(arr + i);

    // Sortera x med bubblesort
    double temp;
    int osorterad = 1;
    while(osorterad)
    {
        osorterad = 0;
        for(i=0; i<antal-1; i++)
        {
            if(x[i] > x[i+1])
            {
                temp = x[i];
                x[i] = x[i+1];
                x[i+1] = temp;
                ++osorterad;
            }

        }
    }
    return x;
}

void skriv(double *array, int n, int k)
{
    for(int i=0; i<n; i++)
    {
        cout << array[i] << "  ";
        if((i+1)%k == 0) // Om modus = 0, byt till ny rad
            cout << endl; // k antal tal per rad
    }
    cout << endl;
}

int main()
{
    int n, k;

    cout << "Läs in tal mha laes()" << endl;
    double *a = laes(n);

    cout << "Skriv ut arrayen mha skriv()" << endl;
    cout << "Ange tal per rad: ";
    cin >> k;
    skriv(a, n, k);

    cout << "Sortera arrayen mha sort" << endl;
    double *s = sort(a, n);

    cout << "Skriv ut sorterade arrayen mha skriv()" << endl;
    cout << "Ange antal tal per rad: ";
    cin >> k;
    skriv(s, n, k);

    delete[] s;
    delete[] a;

    return 0;
}
