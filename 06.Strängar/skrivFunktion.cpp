#include <iostream>
#include <string>
using namespace std;

void skriv(const string &namn, const string &riktning);

int main()
{
    string namn;

    cout << "Ange ditt namn: ";
    getline(cin, namn);

    string riktning;
    cout << "Hur vill du skriva ut strängen? Lodrätt eller baklänges? ";
    getline(cin, riktning);

    skriv(namn, riktning);

    return 0;
}

void skriv(const string &namn, const string &riktning)
{
    cout << endl << "Namnet " << riktning << ":" << endl;
    if(riktning == "lodrätt")
    {
    for(int i=0;i<namn.length();i++)
        cout << namn.at(i) << endl;
    }
    else if(riktning == "baklänges")
    {
        for(int i=namn.length()-1;i >= 0; i--)
            cout << namn.at(i);
    }
    else
        cout << "Ange \"lodrätt\" eller \"baklänges\".";
    cout << endl;
}

