// Filnamn: .../wordlength.cc
// Räknar ordlängder
#include <iostream>
#include <string>
using namespace std;

int main() {

   string w;
   cout << "Ge ett ord: ";
   cin  >> w;
   while ( w != "STOPP" ) {
     cout << "Ordet " << w << " innehåller " 
          << w.length() << " tecken" << endl;
     // Läs ett nytt ord
     cout << "Ge ett ord: ";
     cin  >> w;
   }
   return 0;
}
