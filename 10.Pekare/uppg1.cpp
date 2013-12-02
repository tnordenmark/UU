#include <iostream>
using namespace std;

int main()
{
    int a = 3;
    int c = 5;
    int *b = &c;

    cout << "\n b = " << b <<   endl;
    cout << "\n *b = " << *b <<endl;
    cout << "\n c = " << c << endl;
}
