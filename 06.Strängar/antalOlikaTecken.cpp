#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void antalOlikaTecken(const string &strang, int &numbok, int &numsif, int &numovr);

int main()
{
    string strang;
    int bok, sif, ovr;

    cout << "Ange en text att räkna tecken i: ";
    getline(cin, strang);

    antalOlikaTecken(strang, bok, sif, ovr);

    cout << "Antal bokstäver: " << bok << endl;
    cout << "Antal siffror: " << sif << endl;
    cout << "Antal övriga: " << ovr << endl;

    return 0;
}

void antalOlikaTecken(const string &strang, int &numbok, int &numsif, int &numovr)
{
    numbok=numsif=numovr=0;

    for(int i=0; i< (int) strang.length(); i++)
    {
        if(isalpha(strang.at(i)))
            numbok++;
        else if(isdigit(strang.at(i)))
            numsif++;
        else
            numovr++;
    }
}

