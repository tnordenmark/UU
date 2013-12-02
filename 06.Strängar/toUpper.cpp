#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string strang;

    cout << "Skriv en mening: ";
    getline(cin, strang);

    for(int i=0; i<strang.length(); i++)
        cout << char(toupper(strang.at(i)));
    cout << endl;

    return 0;
}
