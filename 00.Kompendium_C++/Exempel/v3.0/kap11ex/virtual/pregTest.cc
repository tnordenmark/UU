// Filnamn : .../virtual/pregTest.cc

#include <iostream>
#include <string>
#include "person.h"
#include "sportsman.h"
#include "runner.h"
#include "student.h"
#include "preg.h"

using namespace std;

int main() {
  preg myRegister;
  person *tempP;
  student *tempS;
 
  tempP = new person("Small", "Person" );
  myRegister.insertPerson( tempP );

  tempS = new student("Ginny", "Weasly", "häxkonst" );
  tempS->newCourse( "C++ kursen", 5, 4.8 );
  myRegister.insertPerson( tempS );
  
  tempP = new sportsman("Calle", "Kula", "kulstötning", 0 );
  myRegister.insertPerson( tempP );
  
  tempP = new runner("Gunder","Hägg", "löpning", 0, 0. );
  myRegister.insertPerson( tempP );
  
  myRegister.reportAll();
  return 0;
}
