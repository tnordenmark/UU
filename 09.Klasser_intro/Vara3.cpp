//-------------------------------------------
// Vara3.cpp
// Klassen Vara med fler metoder samt
// med konstruktorer, destruktor och selektorer.

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
  Vara( string inNamn, double inPris, int inAntal ); //Annan konstruktor.
  ~Vara();                                           //Destruktor 
  double HaemtaPris();                               //Selektorer:
  int HaemtaAntal();
  string HaemtaNamn();
  void LaesIn();
  void TillLager( int AntalNya );                    //Nya till lagret.
  void Saelja( int AntalSaelj );                     //Sälj vara.
  void ProcentPris( double Faktor );                 //Sätt nytt pris.
  void SkrivUt();                                    //Skriv info om vara.
  
};
//=================================================
// Huvudprogram som testar klassen Vara.

int main()
{
  // Testa konstruktorerna:

  cout << "...nu testar vi konstruktorer..." << endl;
  Vara Boll;                             //(1)
  Vara Ost( "Brie", 145.00, 123 );       //(2)

  Vara Franska;                               //(3)
  Franska = Vara( "Franska", 1.50, 12000 );   //(4)

  // Testa selektorerna:

  cout << "...nu testar vi selektorer..." << endl  //(5)
       << Franska.HaemtaNamn() << " har priset " 
       << Franska.HaemtaPris()
       << " och det finns " 
       << Franska.HaemtaAntal() << " st i lager!"
       << endl;
  
  cout << "...nu testar vi destruktorn..." << endl; //(6)
  return 0;
}
//=====================================================
// Implementation (definition) av metoder i klassen Vara.

//--------------------------------------------------
Vara::Vara()
{
  Namn = "";
  Pris = 0.0;
  Antal = 0;
  cout << "Standard: ";
  SkrivUt();
}
//--------------------------------------------------
Vara::Vara( string inNamn, double inPris, int inAntal )
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
       << "\t\t Pris: " << Pris 
       << "\t Antal i lager: " << Antal
    << endl;
}
//--------------------------------------------------
/* Körningsexempel:
...nu testar vi konstruktorer...
Standard:        Varunamn:       Pris: 0         Antal i lager: 0
Överlagrad:      Varunamn: Brie  Pris: 145       Antal i lager: 123
Standard:        Varunamn:       Pris: 0         Antal i lager: 0
Överlagrad:      Varunamn: Franska       Pris: 1.5       Antal i lager: 12000
...nu testar vi selektorer...
Franska har priset 1.5 och finns 12000 st i lager!
...nu testar vi destruktorn...
Hej då   Varunamn: Franska       Pris: 1.5       Antal i lager: 12000
Hej då   Varunamn: Franska       Pris: 1.5       Antal i lager: 12000
Hej då   Varunamn: Brie  Pris: 145       Antal i lager: 123
Hej då   Varunamn:       Pris: 0         Antal i lager: 0
 */
