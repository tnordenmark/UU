// Filnamn: .../cstring05.cc
// Felaktig inmatning av strängar med cin

#include <iostream.h>

int main() {
  char name[30], car[30];

  cout << "What is your name ? ";
  cin >> name;
  cout << "What car do you drive ? ";
  cin >> car;

  cout << name << " drives a " << car << endl;
  return 0;
}
