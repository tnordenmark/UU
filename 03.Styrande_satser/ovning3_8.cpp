#include <iostream>

using namespace std;

int main()
{
    int antal=0;
    const int MAX=10;    // heltalskonstant 
    bool fortsaett=true; // variabel av typen bool initieras till true

    cout << "Här kommer " << MAX << " rader med HEJ:" << endl;

    while(fortsaett) // variabeln fortsaett styr loopen
    {
        cout << "Hej" << endl;
        antal++;
        fortsaett = (antal<=10); // fortsaett får ett nytt värde:
                                // om antal>=0 true annars false
    }

    cout << "Nu är loopen klar." << endl;

    return 0;
}