//-------------------------------------------
// Vara4.cpp
// Klassen Vara används för att skapa en
// affär i huvudprogrammet, dvs ha en array 
// av Vara-objekt, som kallas "Artiklar".

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
  Vara();                                            //Standardkonstruktor.
  Vara(string inNamn, double inPris, int inAntal); //Annan konstruktor.
  ~Vara();                                           //Destruktor 
  double HaemtaPris();                               //Selektorer:
  int HaemtaAntal();
  string HaemtaNamn();
  void LaesIn();
  void TillLager(int AntalNya);                    //Nya till lagret.
  void Saelja(int AntalSaelj);                     //Sälj vara.
  void ProcentPris(double Faktor);                 //Sätt nytt pris.
  void SkrivUt();                                    //Skriv info om vara.
  
};
//=================================================
// Huvudprogram för en enkel affär.

int main()
{ 
  // Skapa nu en hel array av objekt i klassen Vara.
  // Antag max 5 st varor nu.

  const int MaxVaror = 5;
  int AntalVaror;

  Vara Artiklar[MaxVaror];                   //(1)

  Artiklar[0] = Vara("Mjölk", 6.50, 3000); //(2) 
  Artiklar[1] = Vara("Lime", 1.00, 150);   //(3)
  Artiklar[2] = Vara("Äpple", 2.00, 7000); //(4)
  Artiklar[3].LaesIn();                      //(5)

  AntalVaror = 4;

  cout << "Nu har vi följande varor i lager: " 
       << endl;

  for (int i = 0; i < AntalVaror; i++)    //(6)
    {
      Artiklar[i].SkrivUt();
    }

  cout << "Vi skall sätta om priset på alla varor"
       << ", ge faktorn: ";
  double Fakt;
  cin >> Fakt;

  for (int i = 0; i < AntalVaror; i++)
    {
      Artiklar[i].ProcentPris(Fakt);
    }

  cout << "Skriver ut varor med nya priser: " 
       << endl;

  for (int i = 0; i < AntalVaror; i++)
    {
      Artiklar[i].SkrivUt();
    }

  return 0;
}
//================================================
// Implementation (definition) av metoder i 
// klassen Vara.
//------------------------------------------------
Vara::Vara()
{
  Namn = "";
  Pris = 0.0;
  Antal = 0;
  cout << "Standard: ";
  SkrivUt();
}
//--------------------------------------------------
Vara::Vara(string inNamn, double inPris, int inAntal)
{
  Namn = inNamn;
  Pris = inPris;
  Antal = inAntal;
  cout << "Överlagrad: ";
  SkrivUt();
}
//--------------------------------------------------
Vara::~Vara()
{
  cout << "Hej då ";
  SkrivUt();         // Skriv ut aktuella objektet
}
//--------------------------------------------------
double Vara::HaemtaPris()
{
  return Pris;
}
//--------------------------------------------------
int Vara::HaemtaAntal()
{
  return Antal;
}
//--------------------------------------------------
string Vara::HaemtaNamn()
{
  return Namn;
}
//--------------------------------------------------
void Vara::LaesIn()
{
  cout << "Ge varans namn:" << endl;
  getline( cin, Namn );
  cout << "Ge pris och antal i lager:" << endl;
  cin >> Pris >> Antal;
  cin.get(); //Så man kan läsa in ny vara senare...
}
//--------------------------------------------------
void Vara::TillLager(int AntalNya)
{
  Antal += AntalNya;
}
//--------------------------------------------------
void Vara::Saelja(int AntalSaelj)
{
  Antal -= AntalSaelj;   //Vad händer om man säljer mer än man har?
}
//--------------------------------------------------
void Vara::ProcentPris(double Faktor)
{
  Pris *= Faktor;
}
//--------------------------------------------------
void Vara::SkrivUt()
{
  cout << "\t Varunamn: " << Namn 
       << "\t Pris: " << Pris 
       << "\t Antal i lager: " << Antal
    << endl;
}
//--------------------------------------------------
/* Körningsexempel:
Standard:    Varunamn:               Pris: 0     Antal i lager: 0
Standard:    Varunamn:               Pris: 0     Antal i lager: 0
Standard:    Varunamn:               Pris: 0     Antal i lager: 0
Standard:    Varunamn:               Pris: 0     Antal i lager: 0
Standard:    Varunamn:               Pris: 0     Antal i lager: 0
Överlagrad:  Varunamn: Mjölk         Pris: 6.5       Antal i lager: 3000
Överlagrad:  Varunamn: Småfranska    Pris: 1         Antal i lager: 150
Överlagrad:  Varunamn: Äpple         Pris: 2         Antal i lager: 7000
Ge varans namn:
Kanin
Ge pris och antal i lager:
185.00 3
Nu har vi följande varor i lager: 
         Varunamn: Mjölk       Pris: 6.5   Antal i lager: 3000
         Varunamn: Småfranska  Pris: 1     Antal i lager: 50
         Varunamn: Äpple       Pris: 2     Antal i lager: 7000
         Varunamn: Kanin       Pris: 185   Antal i lager: 3
Vi skall sätta om priset på alla varor, ge faktorn: 1.10
Skriver ut varor med nya priser: 
         Varunamn: Mjölk       Pris: 7.15  Antal i lager: 3000
         Varunamn: Småfranska  Pris: 1.1   Antal i lager: 150
         Varunamn: Äpple       Pris: 2.2   Antal i lager: 7000
         Varunamn: Kanin       Pris: 203.5 Antal i lager: 3
Hej då   Varunamn: Äpple       Pris: 2     Antal i lager: 7000
Hej då   Varunamn: Småfranska  Pris: 1     Antal i lager: 150
Hej då   Varunamn: Mjölk       Pris: 6.5   Antal i lager: 3000
Hej då   Varunamn:             Pris: 0     Antal i lager: 0
Hej då   Varunamn: Kanin       Pris: 203.5 Antal i lager: 3
Hej då   Varunamn: Äpple       Pris: 2.2   Antal i lager: 7000
Hej då   Varunamn: Småfranska  Pris: 1.1   Antal i lager: 150
Hej då   Varunamn: Mjölk       Pris: 7.15  Antal i lager: 3000
 */
