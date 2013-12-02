#include <string>
#include <iostream>
using namespace std;

int main()
{
    string namn = "Statsminister Fredrik Reinfeldt";
    string baklanges_namn;
    for(int i=namn.length()-1; i>=0; i--)
    {
        baklanges_namn = baklanges_namn + namn[i];
    }
    cout << baklanges_namn << endl;

    return 0;
}
