#include <iostream>
using namespace std;

double *laes(int &n);
double medel(double *p, int n);

int main()
{
    int n;
    double *pris = 0;
    double result;

    cout << "Läs in tal mha laes()" << endl;
    pris = readNumbers(n);

    cout << "Beräkna medelvärde mha medel()" << endl;
    result = medel(pris, n);

    if(n)
        cout << "Medelvärdet är " << result << endl;

    return 0;
}

double *laes(int &n)
{
    cout << "Ge ett heltal: ";
    cin >> n;

    double *arr = 0;
    arr = new double[n];

    cout << "Ge " << n << " st flyttal: ";
    for(int i = 0; i < n; i++)
        cin >> *(arr + i);

    return arr;
}

double medel(double *arr, int n)
{
    double sum = 0;
    for(int i = 0; i < n; i++)
        sum +=*(arr + i);

    return sum/n;
}
