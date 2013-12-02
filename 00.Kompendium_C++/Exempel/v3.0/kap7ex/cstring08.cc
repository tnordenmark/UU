// Filnamn: .../cstring08.cc
// Fixat program med cin.get

#include <iostream.h>

int main() {
  const int Size = 20;
  char name[Size], car[Size];

  cout << "What is your name ? ";
  cin.get( name,Size );         // cin.get för sträng
  cin.get();                    // läs bort <Return>
  cout << "What car do you drive ? ";
  cin.get( car,Size ).get();    // som ovan fast elegantare!
  cout << name << " drives a " << car << endl;
  return 0;
}
