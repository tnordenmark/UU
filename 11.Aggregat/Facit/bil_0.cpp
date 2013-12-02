#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

// Aggregatexempel.

//--- Klassen daeck representerar ett bildäck.---

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
                                  // om det går.
  void skriv();
};

//--- Klassen bil.---

class bil
{
private:
  string typ;            // Biltyp, t.ex. "Volvo"
  daeck hf, vf, hb, vb;  // Fyra st hjul.

public:
  bil();                           // Konstruktorer.4st.
  bil( string nytyp );
  bil( double nyhf, double nyvf,
       double nyhb, double nyvb );
  bil( daeck inhf, daeck invf,
       daeck inhb, daeck invb );
  string haemta_typ();           // Vilken typ?
  int gaspaadrag( double d );    // Gör gaspådrag.
  void skriv();                  // Skriv bilinfo.
};

int main()
{
  bil Volvo( "Volvo" );
  bil Saab( "Saab" );
 
  Volvo.skriv(); cout << endl;
  Saab.skriv();  cout << endl;

  int antVolvo, antSaab;

  antVolvo = Volvo.gaspaadrag( 4.0 );
  antSaab  = Saab.gaspaadrag( 4.0 );

  cout << "Antal slutslitna Volvodäck: " 
       << antVolvo << endl;
  Volvo.skriv(); cout << endl;
  cout << "Antal slutslitna Saabdäck: " 
       << antSaab << endl;
  Saab.skriv(); cout << endl;

  return 0;
}

//---Implementation av däckmetoder.---

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

//---Implementation av bilmetoder.---

bil::bil()
   : typ("Ingen") 
{
  // Här kommer standardkonstruktorn för daeck
  // att anropas automatiskt fyra ggr (hf,vf,hb,vb).
}

bil::bil( string nytyp )
   : typ( nytyp )
{}

bil::bil( double nyhf, double nyvf, 
          double nyhb, double nyvb )
  : hf(daeck(nyhf)), vf(daeck(nyvf)),
    hb(daeck(nyhb)), vb(daeck(nyvb)), typ("--")
{}

bil::bil( daeck inhf, daeck invf,
          daeck inhb, daeck invb )
  //  : hf(inhf), vf(invf), hb(inhb), vb(invb)
{
  hf = inhf; vf = invf;
  hb = inhb; vb = invb;
}

string bil::haemta_typ()
{
  return typ;
}

int bil::gaspaadrag( double d )
{
  // Däcken slits vid varje gaspådrag som
  // föraren gör.
  // Parameter: d = däckslitagekonstant
  // som beror på hur aggresivt föraren gasar.
  // Rekommendation tal i intervallet 2-5.
  // Antag att däcken i varje däckpar 
  // (höger/vänster) slits lika mycket.

  // Antag vidare att vi har en bakhjulsdriven bil.
  // Dvs det sliter mer på bakhjulen än framhjulen
  // då man gasar.
  // Konstanterna "framslit" och "bakslit" har 
  // beräknats från mätningar vid rallytävlingar.

  const double framslit = 3.0;  
  const double bakslit  = 3.5;   // Ty bakhjulsdriven.

  double fram, bak;
  fram = d*framslit;   // Enligt rallyberäkningar.
  bak  = d*bakslit;

  // Kom ihåg: daeck-klassens metod "slitage" returnerar
  // 1 om däcket har slut på gummi, annars 0.

  int sum; // sum = antal däck som är helt utslitna på bilen

  sum =  vf.slitage(fram) + hf.slitage(fram) +
         vb.slitage(bak) +  hb.slitage(bak);
  return sum;
}

void bil::skriv()
 {
   cout.setf( ios::fixed ); // Får lite snyggare utskrifter då...

   cout << "Bil av typen = " << typ << "\t har ";
   hf.skriv(); // Skriver bara ut ena i fram och ena i bak.
   hb.skriv(); 
}



/* Körningsexempel:
Bil av typen = Volvo     har  däck = 20.0 däck = 20.0
Bil av typen = Saab      har  däck = 20.0 däck = 20.0
Antal slutslitna Volvodäck: 0
Bil av typen = Volvo     har  däck = 8.0 däck = 6.0
Antal slutslitna Saabdäck: 0
Bil av typen = Saab      har  däck = 8.0 däck = 6.0
 */
