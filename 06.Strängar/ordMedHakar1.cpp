#include <iostream>
#include <string>
using namespace std;

// Ett program som kollar om ett ord förekommer i en text
// eller som ett delord i andra ord. Programmet skriver ut dessa
// ord med hakar runt orden.
int main() {
    string strang;
    string ord;

    cout << "Skriv in lite text: ";
    getline(cin, strang);
    cout << "Skriv in ett ord att leta i texten: ";
    cin >> ord;

    // Sök igenom texten efter dessa ord (fristående
    // eller som del i ett annat ord). 
    for(int i=0; i<strang.length(); )
    {
    // För varje ny position i strängen jämför alla efterföljande
    // tecken med de i det sökta ordet.
        int j=0;
        while( j<ord.length() && (i+j)<strang.length() && strang[i+j]==ord[j])
            j++;

        // Om alla stämmer överens skriv ut ordet med hakar
        // runt det och hoppa fram till positionen efter ordet
        // Annars skriv ut det tecknet som vi är positionerade
        // vid och fortsatt kollen med nästa bokstav.
        if(j==ord.length())
        {
            cout << "[" << ord << "]";
            i+=ord.length();
        }
        else
        {
            cout << char(strang[i]);
            i++;
        }
    }
    cout << endl;
    
    return 0;
}

