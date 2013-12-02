// Filnamn: .../string2.cc
// Läser ord och tar reda på ordlängden
#include <iostream>
#include <string>
using namespace std;

int main() {

   string s;
   cout << "Ge ett ord: ";
   cin  >> s;
   while ( s != "STOP" ) {
     cout << "Ordet " << s << " innehåller " 
	  << s.length() << " tecken" << endl;
     // Läs ett nytt ord
     cout << "Ge ett ord: ";
     cin  >> s;
   }
   return 0;
}
