#include <iostream> // för cout
#include <fstream>  // för ifstream
#include <string>   // för string
#include <cstdlib>  // för exit
using namespace std;

void copyFile(string &infil, string &utfil);

int main()
{
    string infil, utfil;

    cout << "Ange den skadade filens namn: ";
    getline(cin, infil);
    cout << "Ange filnamnet för den reparerade filen: ";
    getline(cin, utfil);

    // Exekvera funktionen copyFile() för att kopiera infil -> utfil
    copyFile(infil, utfil);
    return 0;
}

void copyFile(string &infil, string &utfil)
{
    // En sträng att lagra filens innehåll i temporärt
    string rad;

    // Öppna infilen och konstruera objektet fin
    ifstream fin(infil.c_str());
    
    // Kontrollera att infilen existerar
    if(!fin.good())
    {
        cout << "Infilen kunde inte öppnas, kontrollera filnamnet." << endl;
        exit(EXIT_FAILURE);
    }
    
    // Öppna utfilen och konstruera objektet fout
    ofstream fout(utfil.c_str());

    // Kontrollera att utfilen går att öppna
    if(!fout.good())
    {
        cout << "Utfilen kunde inte öppnas, kontrollera filnamnet." << endl;
        exit(EXIT_FAILURE);
    }

    while(getline(fin, rad))
    {
        for(int i=rad.length()-1; i>=0; i--)
            fout << rad.at(i);

        fout << endl;
    }

    fin.close();
    fout.close();
}
