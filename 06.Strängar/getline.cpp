#include <string>
#include <iostream>
using namespace std;

int main()
{
    string namn;

    cout << "Ge namn: ";
    getline(cin, namn);
    cout << namn << endl;

    return 0;
}
