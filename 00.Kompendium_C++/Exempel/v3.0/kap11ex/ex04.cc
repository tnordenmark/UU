// Filnamn : .../ex04.cc

#include <iostream>
#include "person1.h"
#include "student1.h"
using namespace std;

int main() {
  Student flitig( "Filip","Flitig","730907-0345","MBL" );

  flitig.newCourse( "Geometri",5,3.5 );
  flitig.newCourse( "Analys 1",3,5.3 );
  flitig.newCourse( "C++ ",4,4.9 );
  flitig.report();

  return 0;
}
