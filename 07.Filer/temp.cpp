#include <string>
#include <iostream>
using namespace std;

void enFunktion(string s)
{
    char tmp;
    for (int i = 0; i<s.length(); i++)
    {
        tmp = s.at(i);
        if (isupper(tmp))
        {
            cout << tmp;
        }
    }
    cout << endl;
}

int main()
{
    string txt = "jaG hAr pussLat ihop EN rad Som vi Kan testA På.";
    enFunktion(txt);

    return 0;
}
