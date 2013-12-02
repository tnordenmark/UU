#include <iostream>
#include <string>
using namespace std;

int main()
{
    string namn;

    cout << "Ange ditt namn: ";
    getline(cin, namn);
    cout << endl;

    cout << "Namnet lodrätt:" << endl;

    for(int i=0;i<namn.length();i++)
        cout << namn[i] << endl;

    cout << endl;

    cout << "Namnet baklänges:" << endl;

    for(int i=namn.length()-1; i >= 0; i--)
        cout << namn[i];

    cout << endl;
}

