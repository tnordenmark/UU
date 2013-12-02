// Filnamn: .../cstring07.cc
// Felaktigt exempel med cin.get() 

#include <iostream.h>
int main() {
  const int Size = 20;
  char name[Size], car[Size];

  cout << "What is your name ? ";
  cin.get( name,Size );
  cout << "What car do you drive ? ";
  cin.get( car,Size );
  
  cout << name << " drives a " << car << endl;
  return 0;
}
