#include <iostream>
#include <string>
using namespace std;

// En funktion som omvandlar en "binär sträng"
// till ett decimalt tal. 
void bin2dec(const string& binstr, long &dectal)
{
    long tp=1; // tp är "värdet" av aktuell bit om satt
    dectal=0; 
    // Läs det binära talet från höger till vänster och
    // räkna upp det decimala talet om biten är satt
    for(int i=binstr.length()-1; i>=0; i--)
    {
        if(binstr.at(i) == '1')
            dectal += tp;
        tp*=2;
    }
}


// En funktion som omvandlar ett decimalt
// tal till en "binär sträng".
void dec2bin(long dectal, string &binstr)
{
    binstr.clear(); // d.v.s. = en tom sträng
    // Extrahera bitarna från lägsta bit till högsta.
    // Lägg in varje nytt tecken först i strängen.
    while (dectal)
    {
        if (dectal % 2)
            binstr.insert(0,"1");
        else
            binstr.insert(0,"0");
        dectal /= 2;
    }
}


int main()
{
    long tal;
    string str;
    
    cout << "Skriv in ett decimalt tal: ";
    cin >> tal;
    dec2bin(tal,str);
    cout << tal << " är binärt " << str << endl;

    cout << "Skriv in ett binärt tal: ";
    cin >> str;
    bin2dec(str,tal);
    cout << str << " är decimalt " << tal << endl;

    return 0;
}

