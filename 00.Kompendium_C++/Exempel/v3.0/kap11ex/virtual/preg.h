// Filnamn: .../virtual/preg.h
#ifndef __preg__
#define __preg__
#include "person.h"

const int maxPerson = 100;

class preg {
protected:
  int numPersons;           // Verkligt antal personer
  person *pers[maxPerson];  // array med pekare till personer
public:
  preg();                
  ~preg();               
  void reportAll();      
  void inputAll();                
  void insertPerson(person *p);
};
#endif
