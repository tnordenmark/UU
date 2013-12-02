#include <iostream>
#include <string>
using namespace std;

int main()
{
    string namn;
    string hej = "Hej";

    cout << "Ange ditt namn: ";
    getline(cin, namn);

    cout << hej << " " << namn << "!" << endl;
}
