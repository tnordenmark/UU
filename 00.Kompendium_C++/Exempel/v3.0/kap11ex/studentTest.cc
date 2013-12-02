// Filnamn : .../studentTest.cc
#include <iostream>
#include "person.h"
#include "student.h"
using namespace std;

int main() {
  student flitig( "Hermione", "Granger", "häxkonst" );

  flitig.newCourse( "Förvandlingskonst", 3, 5.3 );
  flitig.newCourse( "Programmeringsteknik II ", 4, 4.9 );
  flitig.newCourse( "Genusvetenskap", 5, 3.5 );
  flitig.report();

  return 0;
}
