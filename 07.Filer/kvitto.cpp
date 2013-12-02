#include <iostream> // för cout
#include <fstream>  // för ifstream
#include <string>   // för string
#include <cstdlib>  // för exit
using namespace std;

int main()
{
    double sum1 = 0, sum2 = 0;
    string namn1, namn2;

    // Öppna filen för läsning
    ifstream fin("betalat.txt");

    // Om filen inte kan öppnas, avsluta programmet. Om filen kan öppnas
    // skriv ut meddelande om vilken fil som öppnats.
    if(!fin)
    {
        cout << "Filen kunde inte öppnas." << endl;
        return 0;
    }
    else
        cout << "Läser in namn och belopp från filen betalat.txt." << endl;

    getline(fin, namn1);
    getline(fin, namn2);

    double belopp;
    string namn;

    // Läs in två värden per varv, lägg det första i namn och det andra
    // i belopp
    while(fin >> namn >> belopp)
    {
        // Om namn1 betalat något, addera beloppet till sum1
        if(namn == namn1)
            sum1 += belopp;
        // Om namn2 betalat något, addera beloppet till sum2
        else if(namn == namn2)
            sum2 += belopp;
    }

    cout << namn1 << " har betalat " << sum1 << " kr totalt." << endl;
    cout << namn2 << " har betalat " << sum2 << " kr totalt." << endl;

    if(sum1 > sum2)
        cout << "Resultat: " << namn2 << " ska betala " << namn1 <<
            " " << (sum1-sum2)/2 << " kr." << endl;
    else
        cout << "Resultat: " << namn1 << " ska betala " << namn2 <<
            " " << (sum2-sum1)/2 << " kr." << endl;

    return 0;
}
