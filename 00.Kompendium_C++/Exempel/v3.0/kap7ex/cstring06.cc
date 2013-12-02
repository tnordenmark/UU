// Filnamn: .../cstring06.cc
// Inläsning med cin.getline

#include <iostream.h>

int main() {
  const int Size = 20;
  char name[Size], car[Size];

  cout << "What is your name ? ";
  cin.getline( name,Size );
  cout << "What car do you drive ? ";
  cin.getline( car,Size );
  
  cout << name << " drives a " << car << endl;
  return 0;
}
