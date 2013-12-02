#include <iostream>
#include <string>
#include "Vara.h"
using namespace std;

//===================================================
// Program som testar den utökade klassen Vara.
// Klassdeklaration på header-filen Vara.h.
// Filnamn: TestVara.cpp
// Kompileras med 
// "bcc TestVara.cpp Vara.cpp"
// (bcc bytes mot lämpligt kompilatornamn)
//===================================================
// Huvudprogram som testar klassen Vara.

int main()
{
    Vara enVara;                    // Skapar objektet enVara. 
    enVara.LaesIn();                // Läs in data till enVara-objektet.
    enVara.SkrivUt();               // Skriv ut info om varan.

    enVara.ProcentPris( 1.10 );     // Prisökning 10%.
    enVara.TillLager( 100 );        // 100 nya från grossisten.
    enVara.Saelja( 50 );            // Sälj 50 st.

    enVara.SkrivUt();               //Skriv ut info om varan.
    return 0;
}

/* Körningsexempel:
Ge varans namn:
Ost   
Ge pris och antal i lager:
45.50 100
         Varunamn: Ost   Pris: 45.5      Antal i lager: 100
         Varunamn: Ost   Pris: 50.05     Antal i lager: 150
*/


