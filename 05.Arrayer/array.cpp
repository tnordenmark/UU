#include <iostream> 
using namespace std;

const int MAX=10; // En global konstant

void laesin(int n, int heltal[]);   // Funktions-deklaration 
void tvaertom(int n, int heltal[]); //        "
void skrivut(int n, const int heltal[]);   //       "

// Huvudfunktion
int main() 
{   
  int tal[MAX];         // arrayen
  int antal=MAX;        // aktuellt antal tal i arrayen

  laesin(antal,tal);    // skicka ett heltal och arrayen till funktionen 
  tvaertom(antal,tal);  //       "

  skrivut(antal,tal);   //       "

  return 0; 
}

// Läser in värdena i arrayen
// n är antalet tal som skall läsas in
void laesin(int n, int heltal[])  
{   
  cout << "Skriv in " <<  n << " heltal: " << "\n"; 

  for(int i=0; i<n; i++) 
    cin >> heltal[i];  // Läs in element för element
}

// Vänder om värdena i arrayen
// n är antalet tal i arryen
void tvaertom(int n, int heltal[])
{   
  int temp[MAX]; // behöver en lokal temporär array med fix storlek
  // Kan ej deklarera:
  // int temp[n];  
  // eftersom n är en variabel

  // kopiera baklänges från heltal till temp
  // Om n=10:
  // dvs temp[0]=heltal[9], temp[1]=heltal[8], etc
  for(int i=0; i<n; i++)
    temp[n-1-i]=heltal[i];

  // kopiera från arrayen temp till heltal
  // dvs heltal[0]=temp[0], heltal[1]=temp[1], etc
  for(int i=0; i<n; i++) // kopiera temp till heltal
    heltal[i]=temp[i]; 
}

// Skriver ut innehållet i arrayen
// n är antalet tal i arryen
void skrivut(int n, const int heltal[]) // OBS! const
{
 // Loopa igenom arrayen och skriv ut innehållet i resp. element
  for(int i=0; i<n; i++) 
    cout << heltal[i] <<  "\n"; 
}