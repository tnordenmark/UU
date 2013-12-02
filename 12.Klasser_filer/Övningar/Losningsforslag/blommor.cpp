#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Blomgrupp 
{
private:
  int x, y;     // Positionen (x,y) i trädgården
  string namn;  // Namn på blomgruppen (ex. tulpan)
  int antal;    // Antal st blommor i blomgruppen

public:
  Blomgrupp();
  Blomgrupp ( string namnin, int antalin, int xin, int yin );

  int hamtaAntal();          // Returnerar antalet blommor i denna blomgr
  bool liggeri( int xx, int yy ); // Ret sant om blomgr. finns i (xx,yy)
  bool sammanamn( string n );     // Returnerar sant om blomgruppen heter n
  bool laes( istream &is );       // Läser in data om blomgrupp från fil
  string hamtanamn();      // Skickar ut namnet i param utnamn
  void skriv( ostream &os );
};
//--------------------------------------------
int main()
{
  Blomgrupp b;
  int val;

  do
    {
      cout << "Vad vill du göra?" << endl;
      cout << "1) Läsa från fil och skriva på skärmen." << endl; 
      cout << "2) Läsa från fil och skriva på ny fil (ny.txt)." << endl; 
      cin >> val;
    } while ( val < 1 || val > 2 );

  // Läs från fil och skriv ut på skärmen.

  ifstream is( "blommor.txt" );
  ofstream os ("ny.txt");

  if ( is )
    {
      while ( b.laes(is) )
	{
	  //	  cout << "Blomma = " << b.hamtanamn() << " finns i antal "
	  //   << b.hamtaAntal() << endl;
	  if ( val == 1 )
	    b.skriv( cout );
	  else if ( val == 2 )
	    b.skriv( os );
	}
    }
  else
    cout << "Finns ej ngn fil..." << endl;
  return 0;
}


//--------------------------------------------

Blomgrupp:: Blomgrupp() 
  : namn("Inget namn")
{}

Blomgrupp:: Blomgrupp ( string namnin, int antalin, int xin, int yin )
  : antal(antalin), x(xin), y(yin), namn(namnin)
{}

int Blomgrupp:: hamtaAntal() 
{ 
  return antal;
}

bool Blomgrupp:: liggeri( int xx, int yy )
{
  return ( x == xx && y == yy );
}

bool Blomgrupp:: sammanamn( string n )
{
  return (namn == n);
}

bool Blomgrupp:: laes( istream &is )
{
  is >> namn >>  antal >> x >> y;
  return !is.eof();
}

string Blomgrupp:: hamtanamn()
{
  return namn;
}

void Blomgrupp:: skriv( ostream & os)
{
  os << "Blomgrupp: " << namn << " " 
       << x << " " << y << " " << antal << endl;
}

      /*      b.laes( is );
      
      while ( !is.eof() )
	{
	  b.skriv( cout );
	  
	  b.laes( is );
	}
      */


/*Körning:
1) Läsa från fil och skriva på skärmen.
2) Läsa från fil och skriva på ny fil (ny.txt).
4
Vad vill du göra?
1) Läsa från fil och skriva på skärmen.
2) Läsa från fil och skriva på ny fil (ny.txt).
5
Vad vill du göra?
1) Läsa från fil och skriva på skärmen.
2) Läsa från fil och skriva på ny fil (ny.txt).
1
Blomgrupp: Flox 1 1 30
Blomgrupp: Flox 1 2 30
Blomgrupp: Flox 2 2 30
Blomgrupp: Flox 2 1 30
Blomgrupp: Tulpan 2 5 20
Blomgrupp: Rödros 13 10 2
Blomgrupp: Lilja 14 145 10000
Blomgrupp: Solros 4 3 4
Blomgrupp: Blåklocka 6 6 6
Blomgrupp: Blåklocka 5 6 6
Blomgrupp: Blåklocka 4 6 6
kursa> a.out
Vad vill du göra?
1) Läsa från fil och skriva på skärmen.
2) Läsa från fil och skriva på ny fil (ny.txt).
2
kursa> more ny.txt
Blomgrupp: Flox 1 1 30
Blomgrupp: Flox 1 2 30
Blomgrupp: Flox 2 2 30
Blomgrupp: Flox 2 1 30
Blomgrupp: Tulpan 2 5 20
Blomgrupp: Rödros 13 10 2
Blomgrupp: Lilja 14 145 10000
Blomgrupp: Solros 4 3 4
Blomgrupp: Blåklocka 6 6 6
Blomgrupp: Blåklocka 5 6 6
Blomgrupp: Blåklocka 4 6 6
*/
