// Filnamn: .../get.cc

#include <iostream>
using namespace std;

int main() {
   char c;
   cout << "Ge ett tecken: ";
   cin.get(c);          // Läser ett tecken och lagrar det i c
   cout << "Kod för tecknet " << c 
        << " är " << int(c) << endl;
   return 0;
}
