#include <iostream>
#include <string>
using namespace std;

const int antalbok=26;

int main()
{
    string rad;

    cout << "Mata in en rad text: ";
    getline(cin, rad);

    int f[antalbok];

    for(int i=0; i<antalbok; i++)
        f[i]=0;

    for(int i=0; i<(int) rad.length(); i++)
    {
        int index;
        if(rad.at(i)>='a' && rad.at(i)<='z')
        {
            index = rad.at(i) - 'a';
            f[index]++;
        }
        if(rad.at(i)>='A' && rad.at(i)<='Z')
        {
            {
                index = rad.at(i) - 'A';
                f[index]++;
            }
        }
    }

    cout << "\nBokstav\tFrekvens\n";
        for(int i=0; i<antalbok; i++)
        {
            char b = char (i+'A');
            if(f[i]>0)
                cout << b << "\t" << f[i] << endl;
        }
    return 0;
}
