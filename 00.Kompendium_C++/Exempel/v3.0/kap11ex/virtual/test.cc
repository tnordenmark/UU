// Filnamn : .../virtual/test.cc
#include <iostream>
#include "person.h"
#include "sportsman.h"
#include "student.h"
using namespace std;

int main() {
  person *p;    

  int ans;
  cout << "Skapa en idrottare eller en student? " << endl;
  cout << "Svara 1 för idrottare och 2 för student: ";
  cin >> ans;

  if (ans==1)
    p = new sportsman("Calle", "Kula", "kulstötning", 0);
  else
    p = new student("Ginny", "Weasly", "häxkonst" );
  p->report();
  delete p;
  return 0;
}
