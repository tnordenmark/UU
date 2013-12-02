#include <iostream>
#include "min.h"
using namespace std;

int main()
{
    int tal1, tal2;
    cout << "Ge två heltal: " << endl;
    cin >> tal1 >> tal2;
    cout << "Minst var talet " << min(tal1, tal2) << endl;
    return 0;
}
