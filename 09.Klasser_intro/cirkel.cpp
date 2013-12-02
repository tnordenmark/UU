#include <iostream>
#include <cmath>
using namespace std;

// cirkel.cpp
// En enkel cirkelklass.
// Antag en cirkel med radie=0 räknas som
// att den inte finns.

// M_PI är en konstant i "cmath"
// som har värdet 3.14159...

const double pi = M_PI;

// klassdeklarationen

class cirkel 
{
private:
  double x, y;                       //position
  double radie;                      // storlek

public:
  // konstruktorer
  cirkel();
  cirkel(double r);
  cirkel(double xp, double yp, double r);

  // selektor
  double R();              // returnera radie

  // andra metoder
  void lasin();            // läs in attributen
  void skrivut();          // skriv ut atttributen
  void flytta(double dx,
              double dy);    // flytta cirkeln
  void skala(double faktor); // skala cirkelns storlek
  double omkrets();          // beräkna cirkelns omkrets
  double yta();              // beräkna cirkelns yta

  int krock( cirkel annan ); // kolla om krock med annan
  cirkel ihop( cirkel & annan );   // smält ihop två cirklar...
};

//---------------------------------------------------------------

// Testa det hela

int main()
{
  // Skapa lite cirklar på olika sätt.

  cirkel c, d(0.5), e(4.4, -2.0, 8.0);
  cirkel f;

  // Skrivut vad vi fick.

  c.skrivut();
  d.skrivut();
  e.skrivut();
  f.skrivut();

  // Läs in f's attribut från tangentbordet
  // och skriv ut vad det blev på skärmen.

  f.lasin();
  f.skrivut();

  // Skala d med en faktor 2 och
  // skriv ut vad vi fick.

  d.skala(2);
  d.skrivut();

  // Flytta e och skriv ut vad vi fick.

  e.flytta(-1.0,-1.0);
  e.skrivut();

  // Beräkna yta och omkrest för e.

  cout << "Omkrets: " << e.omkrets()
       << " Yta: " << e.yta() << endl;
  
  // Tilldela nya värden till d och e:

  d = cirkel( 1.0, 1.0, 1.0 );
  e = cirkel( 1.5, 1.5, 1.0 );

  // Kolla om d och e krockar, i så fall
  // slå ihop dem :-).

  if ( d.krock( e ) )
    {
      cout << "OK, cirklar krockar och "
	   << "bildar ny cirkel!" << endl;
      cout << "Ursprungscirklarna är: ";
      d.skrivut();
      e.skrivut();

      // Så slå ihop till en cirkel.

      cirkel ny;
      ny = d.ihop( e );

      cout << "Resultatet blev: ";
      ny.skrivut();

      if ( d.R() == 0 && e.R() == 0 )
	{
	  cout << "De ursprungliga cirklarna "
	       << "finns ej mer..." << endl;
	}
    }
  return 0;
}
//---------------------------------------------
// Standardkonstruktorn, skapar en cirkel med
// radien 1 i origo.

cirkel::cirkel()
{
  x = y = 0.0;
  radie = 1.0;
}
//---------------------------------------------------------------
// Skapar en cirkel med radien r i origo.

cirkel::cirkel( double r )
{ 
  x = y = 0.0;
  radie = r;
}
//---------------------------------------------------------------
// Skapar en cirkel enligt order.

cirkel::cirkel( double xp, double yp, double r ) 
{
  x = xp;
  y = yp;
  radie = r;
}
//---------------------------------------------------------------
// Läser in cirkelns attribut från tangentbordet.

void cirkel::lasin()
{
  cout << "Ge position och radie: ";
  cin >> x >> y >> radie;
}
//---------------------------------------------------------------
// Skriver ut cirkelns egenskaper.

void cirkel::skrivut()
{
  cout << "Cirkeln ligger i position " << x << " " << y
       << " med radien " << radie << endl;
}
//---------------------------------------------------------------
// Returnera radien.

double cirkel:: R()
{
  return radie;
}
//---------------------------------------------------------------
// Flyttar cirkeln angiven sträcka
// i x- och y-led.

void cirkel::flytta( double dx, double dy )
{
  x += dx;
  y += dy;
}
//---------------------------------------------------------------
// Skala cirkelns radie angiven faktor,
// dvs förminska eller förstora.

void cirkel::skala( double faktor )
{
  radie *= faktor;
}
//---------------------------------------------------------------
// Beräkna och returnera cirkelns omkrets.

double cirkel::omkrets()
{
  return 2*radie*pi;
}
//---------------------------------------------------------------
// Beräkna och returnera cirkelns yta.

double cirkel::yta()
{
  return pi*radie*radie;
}

//---------------------------------------------------------------
// Två specialare bara för att visa att man
// kan returnera objekt och att man kan ha
// lokala objekt (deklarerade i en metod)

int cirkel::krock( cirkel  annan )
// Kolla om aktuella objektet krockar med annan.
{
  if (sqrt( (x - annan.x)*(x - annan.x) +
              (y - annan.y)*(y - annan.y) ) <=
          radie + annan.radie )
    return 1; //"true"
  else
    return 0; //"false"
}

cirkel cirkel::ihop( cirkel & annan )
  // Smält ihop två cirklar.
  // Låt oss ta medelvärden av attributen till
  // den nya cirkeln.
  // Egentligen borde de gamla cirklarna
  // försvinna efter sammanslagningen;
  // vi löser det med att deras radier blir noll.
  // Eftersom "annan" ändrar värde, så måste den
  // vara referensparameter.

{
  cirkel c;  // temporär cirkel som vi bygger
             // upp attribut för attribut
             // och sedan returnerar

  c.x = 0.5*(x + annan.x);
  c.y = 0.5*(y + annan.y);
  c.radie = 0.5*(radie + annan.radie);

  radie = 0;
  annan.radie = 0; // kräver att "annan" är  referensparameter

  return c;
}
/* Körningsexempel:
Cirkeln ligger i position 0 0 med radien 1
Cirkeln ligger i position 0 0 med radien 0.5
Cirkeln ligger i position 4.4 -2 med radien 8
Cirkeln ligger i position 0 0 med radien 1
Ge position och radie: 1.2 2.2 0.5
Cirkeln ligger i position 1.2 2.2 med radien 0.5
Cirkeln ligger i position 0 0 med radien 1
Cirkeln ligger i position 3.4 -3 med radien 8
Omkrets: 50.2655 Yta: 201.062
OK, cirklar krockar och bildar ny cirkel!
Ursprungscirklarna är: Cirkeln ligger i position 1 1 med radien 1
Cirkeln ligger i position 1.5 1.5 med radien 1
Resultatet blev: Cirkeln ligger i position 1.25 1.25 med radien 1
De ursprungliga cirklarna finns ej mer...
*/
