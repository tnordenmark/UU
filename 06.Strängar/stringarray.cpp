#include <iostream>
#include <string>
using namespace std;


int main()
{
    const int STRINGS=4;
    string strings[STRINGS];
    int crypto;

    for(int i=0; i<STRINGS; i++)
    {
        cout << "Mata in rad " << i+1 << ": ";
        getline(cin, strings[i]);
    }

    cout << "Ange ett tal: ";
    cin >> crypto;

    for(int i=0; i<STRINGS; i++)
        for(int j=0; j<(int)strings[i].length(); j++)
        {
            strings[i].at(j)=strings[i].at(j)+crypto;
        }

    cout << "Krypterade raderna:" << endl;

    for(int i=0; i<STRINGS; i++)
    {
        cout << strings[i] << endl;
    }
    return 0;
}
