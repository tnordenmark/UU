// Filnamn: .../string1.cc
// Läser ett namn, skriver en hälsning
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s = "Hej på dig";
  string namn;

  cout << "Vad heter du? ";
  cin >> namn;
  
  cout << s << ", " << namn << '!' << endl;
  return 0;
}
