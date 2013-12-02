// Filnamn: .../char.cc

#include <iostream>
using namespace std;

int main() {
   char c;
   cout << "Ge ett tecken: ";
   cin  >> c;
   cout << "Kod för tecknet " << c 
        << " är " << int(c) << endl;
   cout << "Nästa tecken är " << char(c+1) 
        << " med kod " << c+1 << endl;
   return 0;
}
