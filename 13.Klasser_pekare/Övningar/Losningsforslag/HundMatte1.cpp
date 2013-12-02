#include <iostream>
#include <string>
using namespace std;

// HundMatte1.cpp
// Svarsfil
// Eftersom Hund pekar på Matte och Matte på
// hund, så måste man låta ngn ha högre prioritet
// (annars kan det går "rundgång" i konstruktorer
// och utskriftmetoder t ex).
// Vi väljer att Matte är viktigare än hund.
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
};  
//-------------------------------------------------------
int main()
{
  Matte matte1( "Matilda" );
  Hund *hund1_p;                    // Pekare till hund.
  hund1_p = new Hund( "Fido", 15 ); // Skapa Fido.

  cout << "Lite startinfo:" << endl;
  hund1_p->skriv(); cout << endl;
  matte1.skriv();   cout << endl;

  cout << "Matilda kopplar Fido" << endl;
  matte1.kopplaHund( hund1_p );

  cout << "Fido blir knubbigare" << endl;
  hund1_p->nyvikt( 25 );

  matte1.skriv();   cout << endl; 
  hund1_p->skriv(); cout << endl;
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
  //  (*hund_p).kopplaMatte( this ); Funkar också bra.

  hund_p->kopplaMatte( this );
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
  if ( matte_p )
    {
      // OBS! Här blir "matte_p->skriv()" tokigt.
      // men detta går bra.

      cout << " har matte = " 
           << matte_p->haemtaNamn() << " ";
    }
  else
    cout << " är en herrelös hund, har ingen matte.";
}

void Hund:: kopplaMatte( Matte *m_p )
{
  matte_p = m_p; //Nu pekar de på samma matte.
}

void Hund:: nyvikt( int ny )
{
  vikt = ny;
}

/*
Lite startinfo:
hund heter Fido och väger 15
 är en herrelös hund, har ingen matte.
Matilda  har ingen hund...
Matilda kopplar Fido
Fido blir knubbigare
Matilda hund heter Fido och väger 25
 har matte = Matilda 
hund heter Fido och väger 25
 har matte = Matilda 

 */
