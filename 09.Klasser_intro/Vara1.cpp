//-------------------------------------------
// Vara1.cpp

#include <iostream>
#include <string>
using namespace std;

//Klassdeklaration för klassen Vara.

class Vara
{
private:
  string Namn;
  double Pris;
  int    Antal;

public:
  void LaesIn()                            //Läs från tangentbord.
  {
    cout << "Ge varans namn:" << endl;
    getline( cin, Namn );
    cout << "Ge pris och antal i lager:" << endl;
    cin >> Pris >> Antal;
    cin.get(); //Så man kan läsa in ny vara senare ..
  }
  void TillLager( int AntalNya )                    //Nya till lagret.
  {
    Antal += AntalNya;
  }
  void Saelja( int AntalSaelj )                     //Sälj vara.
  {
    Antal -= AntalSaelj;   //Vad händer om man säljer mer än man har?
  }
  void ProcentPris( double Faktor )                 //Sätt nytt pris.
  {
    Pris *= Faktor;
  }
  void SkrivUt()                                    //Skriv info om vara.
  {
    cout << "\t Varunamn: " << Namn 
         << "\t Pris: " << Pris 
         << "\t Antal i lager: " << Antal
         << endl;
    
  }
};
//=====================================================
// Huvudprogram som testar klassen Vara.

int main()
{
  Vara enVara;        // Skapar objektet enVara. 
  enVara.LaesIn();    // Läs in data till enVara-objektet.
  enVara.SkrivUt();   // Skriv ut info om varan.

  enVara.ProcentPris( 1.10 );    // Prisökning 10%.
  enVara.TillLager( 100 );       // 100 nya från grossisten.
  enVara.Saelja( 50 );           // Sälj 50 st.

  enVara.SkrivUt();               //Skriv ut info om varan.
  return 0;
}

/* Körningsexempel:
Ge varans namn:
Mjölk
Ge pris och antal i lager:
7.00 125
         Varunamn: Mjölk         Pris: 7         Antal i lager: 125
         Varunamn: Mjölk         Pris: 7.7       Antal i lager: 175
*/
