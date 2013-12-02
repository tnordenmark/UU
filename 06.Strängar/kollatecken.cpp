#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    int nletters=0;
    int ndigits=0;
    int ntotal=0;
    
    char c;
    cout << "Mata in en rad: ";
    
    cin.get(c); // Läs första tecknet
    
    // Så länge vi ej läst return-tecknet
    while(c!='\n')
    {
        ntotal++;
        if(isalpha(c))
            nletters++;
        else if(isdigit(c))
            ndigits++;

        cin.get(c); // Läs nästa tecken
    }

    cout << "Totalt antal lästa tecken: " << ntotal << endl;
    cout << "Totalt antal lästa bokstäver: " << nletters << endl;
    cout << "Totalt antal lästa siffror: " << ndigits << endl;

    return 0;
}
