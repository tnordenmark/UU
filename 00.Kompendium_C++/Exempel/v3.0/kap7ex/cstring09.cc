// Filnamn: .../cstrin09.cc
// Exempel med cin och cin.getline (felaktigt)

#include <iostream.h>

int main() {
  const int Size = 20;
  char name[Size], car[Size];
  int num;

  cout << "How many cars do you have : ";
  cin >> num;                       // först ett tal
  cout << "What is your name ? ";
  cin.getline( name,Size );         // sedan en sträng
  cout << "What car do you drive ? ";
  cin.getline( car,Size );
  
  cout << name << " drives a " << car << endl;
  cout << "and has " << (num-1) << " other cars" << endl;
  return 0;
}
