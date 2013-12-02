#include <iostream>
#include <cctype>
using namespace std;

char getCommand()
{
    char c;
    cout << "Ge kommando (I, R eller Q): ";
    cin >> c;
    return toupper(c); // Konvertera till versaler
}

int main()
{
    char command = getCommand();

    while(command != 'Q')
    {
        switch(command)
        {
            case 'I':
                cout << "Du gav kommandot insert" << endl;
                break;
            case 'R':
                cout << "Du gav kommandot remove" << endl;
                break;
            default:
                cout << "Felaktigt kommando, försök igen";
                break;
        }
        command = getCommand();
    }
    return 0;
}
