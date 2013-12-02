/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: VT/2013

Inlämningsuppgift nr: 1

Namn: Thomas Nordenmark

Personummer: 810427-8257

Fyll i (alt. stryk det som INTE är relevant) av nedanstående:

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja
     Om Nej, beskriv vilka testdata som ger problem: -

Jag har använt kompilator/editor: llvm-gcc 4.2.1/Sublime Text 2

Jag har använt följande dator: MacBook 3.1
      med operativsystemet: OSX 10.6.8

Jag har arbetat ungefär 0,5 timmar med denna uppgift

================================================================================
*/
#include <iostream>
using namespace std;

int main()
{
  int a;
  int b = 12;
  a = 0;

  cout << "a = " << a << endl;
  cout << a+b << '\n' << "a-b = " << a-b << endl;

  return 0;
}
/*
================================================================================
Här följer programkörningar för alla testdata:
==============================================

$ ./annatTest
a = 0
12
a-b = -12

================================================================================

Uppgiften går ut på att felsöka och åtgärda felaktig kod.

Satsen "a = 0" (rad 33) saknade ett semikolon som avslut.

*/