#include <iostream>
using namespace std;

void write_date ( string text, int d = 31, int m = 12, int y = 2008 );

int main()
{
  cout << "Test av en datumfunktion: " << endl;

   write_date ("Första dagen nästa år", 1, 1, 2009);             // anrop av funktionen write_date
  return 0;
}

void write_date ( string text, int d, int m, int y )
{
  // Funktion som skriver ut en text och ett datum på formen 1998-06-27.
  // Specialbehandlar om d < 10 eller m < 10 för att få ut nollan
  // före själva siffran i månaden eller dagen.
  
  const int noll = 0;

  // Skriv ut år.
  cout << text << ": " << y << "-";

  // Skriv ut månad.
  if ( m < 10 ) 
    cout << noll;
  cout << m << "-";

  // Skriv ut dag.
  if ( d < 10 ) 
    cout << noll;
  cout << d << endl;
}
