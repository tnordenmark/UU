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
  const int MAX = 10;  // Max antal bilar i tävlingen.
  int froe;
  froe = long( time( NULL ) );
  srand48( froe ); // Starta slumptalsgeneratorn. (SUN)
  //  srand( froe );   // PC

  bil startheat[MAX];
  int antal = 5;

  startheat[0] = bil("Volvo", framhjulsdriven);
  startheat[1] = bil("Saab", framhjulsdriven);
  startheat[2] = bil("Ford", framhjulsdriven);
  startheat[3] = bil("Fiat", bakhjulsdriven);
  startheat[4] = bil("Ferrari", bakhjulsdriven);

  int alla_har_slut;

  cout << "\n---Nu startar tävlingen!" << endl << endl;
  do
    {
      alla_har_slut = 0;

      for ( int i = 0; i < antal; i++ )
	    {
	       startheat[i].gaspaadrag( slump(2.0), slump(20.0) );
	       //  startheat[i].gaspaadrag( 2.0, 20.0 ); // För tester

	       startheat[i].skriv();
	       cout << endl;
	       alla_har_slut  += startheat[i].tom(); // Summera antal bilar
	    }                                       // som ej har bensin
      cout << "Liten pause innan nästa gaspådrag... (tryck return)." 
	   << endl;
      cin.get();
    } while ( alla_har_slut < antal );

  // Leta efter den som kom längst, dvs vinnaren:
  // Om vi har flera vinnare, så syns inte det...

  double maxx = startheat[0].haemta_x();
  int maxindex = 0;

  for ( int i = 1; i < antal; i++ )
    {
      if ( startheat[i].haemta_x() > maxx )
	{
	  maxx = startheat[i].haemta_x();
	  maxindex = i;
	}
    }

  cout << "Vinnare:" << endl;

  startheat[maxindex].skriv();

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


---Nu startar tävlingen!

Framhjuls  av typen = Volvo      har  73.9 liter  däck = 18.4 däck = 19.2 xpos = 74.9
Framhjuls  av typen = Saab       har  73.9 liter  däck = 16.6 däck = 18.3 xpos = 128.0
Framhjuls  av typen = Ford       har  71.5 liter  däck = 18.3 däck = 19.2 xpos = 78.1
Bakhjuls   av typen = Fiat       har  79.6 liter  däck = 19.1 däck = 17.8 xpos = 83.3
Bakhjuls   av typen = Ferrari    har  92.3 liter  däck = 18.9 däck = 17.2 xpos = 87.3
Liten pause innan nästa gaspådrag... (tryck return).

Framhjuls  av typen = Volvo      har  48.1 liter  däck = 16.5 däck = 18.2 xpos = 157.7
Framhjuls  av typen = Saab       har  39.8 liter  däck = 13.2 däck = 16.6 xpos = 262.7
Framhjuls  av typen = Ford       har  40.5 liter  däck = 15.7 däck = 17.9 xpos = 187.2
Bakhjuls   av typen = Fiat       har  56.5 liter  däck = 18.8 däck = 17.0 xpos = 127.2
Bakhjuls   av typen = Ferrari    har  81.6 liter  däck = 18.2 däck = 15.6 xpos = 141.3
Liten pause innan nästa gaspådrag... (tryck return).

Framhjuls  av typen = Volvo      har  42.7 liter  däck = 13.8 däck = 16.9 xpos = 244.5
Framhjuls  av typen = Saab       har  20.5 liter  däck = 12.7 däck = 16.4 xpos = 298.2
Framhjuls  av typen = Ford       har  28.0 liter  däck = 12.4 däck = 16.2 xpos = 300.9
Bakhjuls   av typen = Fiat       har  38.0 liter  däck = 18.4 däck = 15.9 xpos = 176.4
Bakhjuls   av typen = Ferrari    har  54.4 liter  däck = 17.1 däck = 12.6 xpos = 251.9
Liten pause innan nästa gaspådrag... (tryck return).

Framhjuls  av typen = Volvo      har  22.4 liter  däck = 11.6 däck = 15.8 xpos = 330.8
Soppatorsk! Bilen slukar 20.5 liter fast du ville 33.5 liter.
Framhjuls  av typen = Saab       har   0.0 liter  däck = 9.4 däck = 14.7 xpos = 416.6
Framhjuls  av typen = Ford       har  13.4 liter  däck = 10.1 däck = 15.1 xpos = 383.6
Bakhjuls   av typen = Fiat       har  15.9 liter  däck = 16.7 däck = 11.8 xpos = 315.0
Bakhjuls   av typen = Ferrari    har  25.4 liter  däck = 15.7 däck = 9.2 xpos = 377.1
Liten pause innan nästa gaspådrag... (tryck return).

Framhjuls  av typen = Volvo      har  21.5 liter  däck = 11.4 däck = 15.7 xpos = 336.8
Framhjuls  av typen = Saab       har   0.0 liter  däck = 9.4 däck = 14.7 xpos = 416.6
Soppatorsk! Bilen slukar 13.4 liter fast du ville 21.2 liter.
Framhjuls  av typen = Ford       har   0.0 liter  däck = 8.5 däck = 14.3 xpos = 444.6
Bakhjuls   av typen = Fiat       har   2.3 liter  däck = 15.9 däck = 9.8 xpos = 384.4
Bakhjuls   av typen = Ferrari    har   8.2 liter  däck = 15.6 däck = 9.1 xpos = 397.9
Liten pause innan nästa gaspådrag... (tryck return).

Framhjuls  av typen = Volvo      har   4.0 liter  däck = 10.7 däck = 15.4 xpos = 373.5
Framhjuls  av typen = Saab       har   0.0 liter  däck = 9.4 däck = 14.7 xpos = 416.6
Framhjuls  av typen = Ford       har   0.0 liter  däck = 8.5 däck = 14.3 xpos = 444.6
Soppatorsk! Bilen slukar 2.3 liter fast du ville 14.9 liter.
Bakhjuls   av typen = Fiat       har   0.0 liter  däck = 14.1 däck = 5.1 xpos = 516.2
Soppatorsk! Bilen slukar 8.2 liter fast du ville 19.6 liter.
Bakhjuls   av typen = Ferrari    har   0.0 liter  däck = 14.2 däck = 5.4 xpos = 508.4
Liten pause innan nästa gaspådrag... (tryck return).

Soppatorsk! Bilen slukar 4.0 liter fast du ville 24.8 liter.
Framhjuls  av typen = Volvo      har   0.0 liter  däck = 8.6 däck = 14.3 xpos = 441.0
Framhjuls  av typen = Saab       har   0.0 liter  däck = 9.4 däck = 14.7 xpos = 416.6
Framhjuls  av typen = Ford       har   0.0 liter  däck = 8.5 däck = 14.3 xpos = 444.6
Bakhjuls   av typen = Fiat       har   0.0 liter  däck = 14.1 däck = 5.1 xpos = 516.2
Bakhjuls   av typen = Ferrari    har   0.0 liter  däck = 14.2 däck = 5.4 xpos = 508.4
Liten pause innan nästa gaspådrag... (tryck return).

Vinnare:
Bakhjuls   av typen = Fiat       har   0.0 liter  däck = 14.1 däck = 5.1 xpos = 516.2
Tack och hej!


*/
