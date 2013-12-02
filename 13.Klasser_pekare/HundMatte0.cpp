#include <iostream>
#include <string>
using namespace std;

// HundMatte0.cpp
// Matte pekar på hund, men inte hund på matte.
// Du skall komplettera så att hund pekar på rätt matte.
// Dvs om en matte kopplar en hund så skall hunden koppla matten!
//-------------------------------------------------------
class Hund; // Klassdeklaration. Så att det funkar!

class Matte
{
private:
  string namn;   // Mattes namn
  Hund *hund_p;  // Pekare till hunden

public:
  Matte();                // Default.konstr.
  Matte( string nynamn ); // Överlagr.konstr.
  void skriv();
  void kopplaHund( Hund *h_p );
  string haemtaNamn();
};
//-------------------------------------------------------
class Hund
{
private:
  string namn;   // Hundens namn
  int vikt;      // Hundens vikt.
  Matte *matte_p;// Pekare till matte

public:
  Hund();                       // Default.konstr.
  Hund( string nynamn, int v ); // Överlagr.konstr.
  void skriv();
  void kopplaMatte( Matte *m_p );
  void nyvikt( int ny );
  string haemtaNamn();
};  
//-------------------------------------------------------
int main()
{
  Matte matte1( "Matilda" ), matte2;
  Hund *hund1_p, *hund2_p;                    // Pekare till hund.
  hund1_p = new Hund( "Fido", 15 ); // Skapa Fido.
  hund2_p = new Hund("Snobben", 20); // Skapa Snobben.

  cout << "Lite startinfo:" << endl;
  hund1_p->skriv(); cout << endl;
  hund2_p->skriv(); cout << endl;
  matte1.skriv();   cout << endl;
  matte2.skriv();   cout << endl;

  cout << matte1.haemtaNamn() << " kopplar " << hund1_p->haemtaNamn() << endl;
  matte1.kopplaHund( hund1_p );

  cout << matte2.haemtaNamn() << " kopplar " << hund2_p->haemtaNamn() << endl;
  matte2.kopplaHund(hund2_p);

  cout << "Fido blir knubbigare" << endl;
  hund1_p->nyvikt( 25 );
  
  cout << "Snobben blir knubbigare" << endl;
  hund2_p->nyvikt(30);


  matte1.skriv();   cout << endl; 
  hund1_p->skriv(); cout << endl;

  matte2.skriv();   cout << endl;
  hund2_p->skriv(); cout << endl;

  return 0;
}
//-------------------------------------------------------
Matte::  Matte()
  : namn("Arne"), hund_p(0)
{}

Matte::  Matte( string nynamn )
  : namn(nynamn), hund_p(0)
{}

void Matte:: skriv()
{
  cout << namn << " ";

  if ( hund_p )
    hund_p->skriv(); // OBS! Kolla att Hund:s skriv ej
                     // använder Mattes:s skriv!!
  else               
    cout << " har ingen hund...";
}

void Matte:: kopplaHund( Hund *h_p )
{
  hund_p = h_p;  // Nu pekar hund_p på samma som h_p
  
  // Vill att aktuell mattes hund (hund_p) kopplas till
  // givna hunden (h_p).
  // Vill även att just denna hund får just aktuella matten
  // dvs i Hund:: vill vi att matte_p blir "this".
  hund_p->kopplaMatte(this);
}
string Matte::haemtaNamn()
{
  return namn;
}
//-------------------------------------------------------
Hund::  Hund()
  : vikt(0), namn("Namnlös"), matte_p(0)
{}

Hund::  Hund( string nynamn, int v )
  : vikt(v), namn(nynamn), matte_p(0)
{}

void Hund:: skriv() 
{ 
  cout << "hund heter " << namn << " och väger "
       << vikt << endl;
  if(matte_p)
  {
      cout << " har matte = " << matte_p->haemtaNamn() << " ";
  }
  else
      cout << " är en herrelös hund, har ingen matte";
}

string Hund::haemtaNamn()
{
    return namn;
}

void Hund:: kopplaMatte( Matte *m_p )
{
    matte_p = m_p; // Nu pekar de på samma matte
}


void Hund:: nyvikt( int ny )
{
  vikt = ny;
}

/*
Lite startinfo:
hund heter Fido och väger 15
(har ingen matte ännu!, fast matte kanste tror det!)
Matilda  har ingen hund...
Matilda kopplar Fido
Fido blir knubbigare
Matilda hund heter Fido och väger 25
(har ingen matte ännu!, fast matte kanste tror det!)
hund heter Fido och väger 25
(har ingen matte ännu!, fast matte kanste tror det!)

 */
