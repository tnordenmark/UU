/* 
Filnamn: alla_start.cpp

All kod i en enda fil här.
1. Deklaration av vanliga funktioner, tex slump
2. Klassdeklarationer
3. Main
4. Funktionsdefinition (slump)
5. Klassmetoddefinitioner
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

//--------------------------------------------------
// Vanliga funktioner:
double slump( double tal );
//--------------------------------------------------
// Klassdeklarationer i rätt ordning, dvs bil kommer
// sist, eftersom bilen har objektattribut ur klass daeck
// och bensintank.

class bensintank
{
private:
  double liter;      // Antal liter bensin i tanken.
  double volym;      // Max antal liter, dvs tankens "volym".
public:
  bensintank();
  bensintank( double lit );       // Full tank (volym=liter).
  bensintank( double lit, double vol );
  double haemta_liter();
  void foerbruka( double & lit ); // Bensinen minskar om det går.
  void skriv();    
};

const double MAXdjup = 20.00; // 20 mm

class daeck
{
private:
  double djup;        // Mönsterdjup = antal mm gummi.

public:
  daeck();
  daeck( double indjup );
  double haemta_djup();
  int slitage( double slitdjup ); // Slit på däcken
  void skriv();
};

const int framhjulsdriven = 1;
const int bakhjulsdriven = 0;

class bil
{
private:
  string typ;            // Biltyp, t.ex. "Volvo"
  int framhjuls;         // Framhjuls-bakhjulsdriven?
  bensintank tank;       // Bensintanken.
  daeck hf, vf, hb, vb;  // Fyra st hjul.
  double xpos;           // Xposition, 0.0 = startlinjen.

public:
  bil();                                // Konstruktorer.
  bil( string nytyp,  int nyfram );
  string haemta_typ();                  // Vilken typ?
  int tom();                            // 1=tom tank, 0 annars. 
  double haemta_x ();                   // Var är bilen?
  void gaspaadrag( double d, double b); // Gör gaspådrag.
  void skriv();                         // Skriv bilinfo.
};

//--------------------------------------------------
// MAIN:
int main()
{
  int froe;
  froe = long( time( NULL ) );
  srand48( froe ); // Starta slumptalsgeneratorn. (SUN)
  //  srand( froe );   // PC

  bil Volvo( "Volvo", framhjulsdriven );
  bil Saab( "Saab", bakhjulsdriven );
 
  Volvo.skriv();  cout << endl;
  Saab.skriv(); cout << endl;
  int alla_har_slut;
  cout << "\n---Nu startar tävlingen!" << endl << endl;

  do
    {
      Volvo.gaspaadrag( slump(2), slump(20.0) );
      Saab.gaspaadrag( slump(2), slump(20.0) );

      Volvo.skriv(); cout << endl;
      Saab.skriv(); cout << endl;

      cout << "Liten pause innan nästa gaspådrag... (tryck return)." 
	   << endl;
      cin.get();

      alla_har_slut = Volvo.tom() + Saab.tom();
    } while ( alla_har_slut < 2 );

  cout << "\n-----Slutresultat: " << endl;
  cout << "Vinnare:" << endl;

  if ( Volvo.haemta_x() > Saab.haemta_x() )
    Volvo.skriv();
  else
    Saab.skriv(); 

  cout << endl;
  cout << "Tack och hej!" << endl;

  return 0;
}
//--------------------------------------------------
// Definition (implementation) av vanliga funktioner:

double slump( double tal )
{
  // För att få tal i intervallet 0-tal på SUN:
  // return drand48()*tal;
  // För att få tal i intervallet 0-tal på PC:
  // return tal*rand()/double(RAND_MAX);

  return drand48()*tal;
}
//--------------------------------------------------
// Definition (implementation) av klassernas metoder
//--------------------------------------------------
//--- Konstruktorer:
bensintank::bensintank()
  : liter(0), volym(0)
{}
bensintank::bensintank( double lit )
  : liter(lit), volym(lit)
{}
bensintank::bensintank( double lit, double vol )
  : liter(lit), volym(vol)
{}
//---Selektorer:
double bensintank::haemta_liter()
{
  return liter;
}
//---Andra metoder:
void bensintank::foerbruka( double & lit )
{
  // Vi vill förbruka "lit" antal liter.
  // Om detta ej går, så förbruka så mycket som möjligt.
  // Ändra i så fall värdet på "lit", ty referensparameter.
 
  if ( lit > liter )
    {
      cout << "Soppatorsk! Bilen slukar " << liter 
	   << " liter fast du ville " << lit << " liter." << endl;
      lit = liter;  // Tanka så mycket det går.
      liter = 0;    // Tom tank;
    }
  else
    liter -= lit;
}
void bensintank::skriv()
{
  cout.setf( ios::fixed );
  cout << setw(5) << setprecision(1) << liter << " liter ";
}  
//--------------------------------------------------
//---Konstruktorer:
daeck::daeck()
  : djup(MAXdjup)
{}
daeck::daeck( double indjup )
  : djup(indjup)
{}
//---Selektorer: 
double daeck::haemta_djup()
{
  return djup;
}
//---Andra metoder:
int daeck::slitage( double slitdjup )
{
  // Slit ned "slitdjup" mycket av
  // gummit (om det går).
  // Returnera 1 om allt gummi slut,
  // annars 0.

  int slutgummi = 0;

  if ( djup - slitdjup < 0 )
    {
      djup = 0;
      slutgummi = 1;
    }
  else
    djup -= slitdjup;

  return slutgummi;
}
void daeck::skriv()
{
  cout.setf( ios::fixed );
  cout << " däck = " << setprecision(1) << djup;
}
//--------------------------------------------------
bil::bil()
  : framhjuls(framhjulsdriven), // Antag standard är framhjulsdrift.
  xpos(0.0), typ("Ingen")
{
  // Här kommer standardkonstruktorerna för bensintank
  // hf, vf, hb, vb att anropas automatiskt.
}
bil::bil( string nytyp, int nyfram )
  : tank( bensintank(100.00) ), framhjuls( nyfram ),
    xpos(0.0), typ(nytyp)
{}
string bil::haemta_typ()
{
  return typ;
}
double bil::haemta_x()
{
  return xpos;
}
void bil::gaspaadrag( double d, double b )
{
  // Däcken slits och bensin går åt vid en rivstart.
  //
  // Parametrar: d = däckslitage, b = bensinminskning.
  // Beroende på om bilen är framhjuls- eller bakhjulsdriven, så slits
  // den på lite olika sätt...
  //
  // Dessutom, man kan köra på helslitna däck, men då går det åt
  // mycket mer bensin!
  //
  // Antag att däcken i varje däckpar (höger/vänster) slits lika mycket.
  const double framslit = 2.0;
  const double bakslit = 2.5;
  const double framliter = 1.75;
  const double bakliter = 1.5;
  double fram, bak, lit;

  if ( framhjuls )
    {
      fram = d*framslit;
      bak  = d;
      lit  = b*framliter;
    }
  else
    {
      fram = d;
      bak  = d*bakslit;
      lit  = b*bakliter;
    }

  double daeckminus = 2*fram + 2*bak;
  double hur_mycket_soppa = tank.haemta_liter();  // init=innan.
  int sum; //sum = antal däck som är helt utslitna

  if ( hur_mycket_soppa > 0 )
    {
      sum =  vf.slitage(fram) + hf.slitage(fram) +
             vb.slitage(bak) +  hb.slitage(bak);

      double soppaminus = (1 + sum)*lit;    //kolla skillnad.

      tank.foerbruka( soppaminus );

      // Det kan hända att "hur_mycket_soppa" blir negativ om man
      // får slut på soppa.
      // Dvs soppamnius skall vara ett mindre tal ibland...

      hur_mycket_soppa -= soppaminus;   
      xpos += soppaminus + 10*daeckminus;
    }
}

int bil::tom()
{
  // Om tanken tom, så returnera 0, annars 1.
  // Eftersom "exakt nolla" ej finns som flyttal så
  // kan det vara bra att kolla om absolutbeloppet av liter är litet tal
  // (nästan tomt i tanken), dvs funktionen "fabs" i cmath används.

  if ( fabs( tank.haemta_liter() ) < 1.0e-6 ) 
    return 1;
   else
     return 0;
}

void bil::skriv()
{
  cout.setf( ios::fixed ); // Får lite snyggare utskrifter då...
  if ( framhjuls )
    cout << "Framhjuls ";
  else
    cout << "Bakhjuls  ";
  cout << " av typen = " << typ << "\t har ";
  tank.skriv();
  hf.skriv(); // Skriver bara ut ena i fram och ena i bak.
  hb.skriv(); 
  cout << " xpos = " << xpos;
}
//--------------------------------------------------
/* Körningsresultat:

Framhjuls  av typen = Volvo      har 100.0 liter  däck = 20.0 däck = 20.0 xpos = 0.0
Bakhjuls   av typen = Saab       har 100.0 liter  däck = 20.0 däck = 20.0 xpos = 0.0

---Nu startar tävlingen!

Framhjuls  av typen = Volvo      har  79.6 liter  däck = 19.3 däck = 19.6 xpos = 42.4
Bakhjuls   av typen = Saab       har  84.9 liter  däck = 19.4 däck = 18.5 xpos = 57.8
Liten pause innan nästa gaspådrag... (tryck return).

Framhjuls  av typen = Volvo      har  51.6 liter  däck = 17.2 däck = 18.6 xpos = 133.6
Bakhjuls   av typen = Saab       har  71.8 liter  däck = 18.9 däck = 17.4 xpos = 101.9
Liten pause innan nästa gaspådrag... (tryck return).

Framhjuls  av typen = Volvo      har  40.8 liter  däck = 13.7 däck = 16.9 xpos = 247.5
Bakhjuls   av typen = Saab       har  55.9 liter  däck = 17.8 däck = 14.5 xpos = 197.0
Liten pause innan nästa gaspådrag... (tryck return).

Framhjuls  av typen = Volvo      har   5.9 liter  däck = 13.7 däck = 16.8 xpos = 284.5
Bakhjuls   av typen = Saab       har  53.8 liter  däck = 16.6 däck = 11.5 xpos = 283.3
Liten pause innan nästa gaspådrag... (tryck return).

Framhjuls  av typen = Volvo      har   5.7 liter  däck = 10.0 däck = 15.0 xpos = 392.8
Bakhjuls   av typen = Saab       har  31.0 liter  däck = 15.5 däck = 8.8 xpos = 383.1
Liten pause innan nästa gaspådrag... (tryck return).

Soppatorsk! Bilen slukar 5.7 liter fast du ville 13.5 liter.
Framhjuls  av typen = Volvo      har   0.0 liter  däck = 7.6 däck = 13.8 xpos = 471.2
Bakhjuls   av typen = Saab       har  12.4 liter  däck = 14.7 däck = 6.8 xpos = 458.0
Liten pause innan nästa gaspådrag... (tryck return).

Framhjuls  av typen = Volvo      har   0.0 liter  däck = 7.6 däck = 13.8 xpos = 471.2
Bakhjuls   av typen = Saab       har   2.0 liter  däck = 14.4 däck = 6.0 xpos = 490.2
Liten pause innan nästa gaspådrag... (tryck return).

Soppatorsk! Bilen slukar 2.0 liter fast du ville 11.5 liter.
Framhjuls  av typen = Volvo      har   0.0 liter  däck = 7.6 däck = 13.8 xpos = 471.2
Bakhjuls   av typen = Saab       har   0.0 liter  däck = 13.5 däck = 3.6 xpos = 557.9
Liten pause innan nästa gaspådrag... (tryck return).


-----Slutresultat: 
Vinnare:
Bakhjuls   av typen = Saab       har   0.0 liter  däck = 13.5 däck = 3.6 xpos = 557.9
Tack och hej!


*/
