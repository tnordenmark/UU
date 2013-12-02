#include <iostream>
using namespace std;

class Person;

class Bil {
public:
  void nyAgare( Person *p );
private:
  Person *agare;
};

class Person {
public:
  void nyBil( Bil *b );
private:
  Bil *bil;
};

void Bil::nyAgare( Person *p ) {
  agare = p;
  if (agare!=0) agare->nyBil( this );
}

void Person::nyBil( Bil *b ) {
  bil = b;
  if (bil!=0) bil->nyAgare( this );
}


int main()

{
  Bil *b = new Bil();
  Person *p = new Person();
  p->nyBil( b );
}
