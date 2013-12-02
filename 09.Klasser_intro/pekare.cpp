#include <iostream>
#include <string>
using namespace std;

int main()
{
    int myint;                  // En int-cell allokeras, och 
                                // "myint" associeras med adressen. 
    int *myptr;                 // En pekare till int deklareras.
                                // Den pekar inte på något.
    myptr = &myint;             // "myptr" pekar på variabeln "myint". 
    myint = 5;                  // Vi fyller cellen med värdet 5. 
    cout << myint << endl;
    *myptr = 6;                 // Vi fyller cellen med värdet 6. 
    cout << myint << endl;      // Utskriften blir '6', inte '5'.
    cout << myptr << endl;      // Adressen till cellen skrivs ut 
                                // (jämför förra exemplet). 
    cout << *myptr << endl;     // Innehållet i cellen skrivs ut, 
                                // dvs '6'.
    return 0;
}
