// Filnamn: .../cstring10.cc
// Hur inläsning av tal och strängar klaras

#include <iostream.h>

int main() {
  const int Size = 20;
  char name[Size], car[Size];
  int num;

  cout << "How many cars do you have : ";
  cin >> num;
  cin.get();                  // saved by the bell!
  cout << "What is your name ? ";
  cin.getline( name,Size );
  cout << "What car do you drive ? ";
  cin.getline( car,Size );
  
  cout << name << " drives a " << car << endl;
  cout << "and has " << (num-1) << " other cars" << endl;
  return 0;
}
