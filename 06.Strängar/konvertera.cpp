// Filen kovertera.cpp
#include <iostream>
#include <string>
using namespace std;

// En funktion som byter ut bokstaven c mot k. 
void konvert(string &str)
{
  int i;
  
  // Loopa igenom strängen och gör ändringar.
  for(i=0; i<str.length(); i++)
    if(str[i]=='c') 
      str[i]='k';
}

int main() 
{
  // Har skapas en array av strängar (5 st)
  string strang[5] = {"This will make English conform more\n",
		              "closely to German, a more proper\n",
		              "languange. Not only will this clear\n",
		              "up confusion, but typewriters can have \n",
		              "one less letter.\n\n"};

  // Skriv ut strängarna före konvertering.
  for(int i=0; i<5; i++)
    cout << strang[i];

  // Utför konvertering.
  for(int i=0; i<5; i++)
    konvert(strang[i]);

  // Skriv ut strängarna efter konvertering.
  for(int i=0; i<5; i++)
    cout << strang[i];

  return 0;
}
