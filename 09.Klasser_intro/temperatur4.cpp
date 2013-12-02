#include <iostream>
#include <string>
using namespace std;

// Uppgift 4: temperatur4.cpp

// Deklaration av klassen:

class  temperatur
{
private:
  double grader;                        // Gradtal
  string typ;                           // "Celsius" eller "Fahrenheit"

public:
  temperatur();                         // default-konstruktor
  temperatur( double t, string typen ); // överlagrad konstruktor 
  void lasin();                         // inläsning av grader
  void skriv();                         // utskrift av grader
  double haemta_grader();               // selektor: returnerar grader
  string haemta_typ();                  // selektor, returnerar typ.
  double skillnad( temperatur t );      // skillnaden mellan 2 temperaturer
  double fahrenheit();                  // returnerar grader i Fahrenheit
  void rapport( int nedre, int oevre ); // skriver "rapport"
  
};
//------------------------------------------------------
// Huvudprogram:

int main()
{
  const int MAX = 7;
  temperatur juli2002[MAX];
  string vilken;

  cout << "Vi skall studera medeltemp en vecka i juli 2002."
       << endl;
  cout << "Fahrenheit eller Celsius?" << endl;
  getline(cin,vilken);

  cout << "Ge sju st medeltemperaturer i angiven enhet:"
       << endl;
  double temp;

  for ( int i = 0; i < MAX; i++ )
    {
      cin >> temp;
      juli2002[i] = temperatur( temp, vilken ); 
    }

  cout << "Nu testar vi att skriva ut alla i vacker tabell"
       << endl;

  for ( int i = 0; i < MAX; i++ )
    {
      juli2002[i].skriv();
      juli2002[i].rapport(10, 20);
    }
  return 0;
}

//------------------------------------------------------
// Implementation av klassens metoder:

// ---Konstruktorer---

temperatur::temperatur() // default-konstruktor
{ 
  grader = 28;  
  typ = "Celsius";
}

temperatur::temperatur( double t, string typen )
{ 
  grader = t;
  typ = typen;
}

// ---Medlemsfunktioner--- 

void temperatur::lasin()
{
  cout << "Ange grader: ";
  cin >> grader;
  cin.get();  //Läs förbi returntecknet.

  cout << "Ange typen: ";
  getline( cin, typ );
}

void temperatur::skriv()
{ 
  cout << "Temperaturen är "<< grader << " grader "
       << typ << "." << endl;
}
  
double temperatur::haemta_grader()
{ 
  return grader;
}

string temperatur::haemta_typ()
{
  return typ;
}

double temperatur::skillnad( temperatur t )
{ 
  // Kolla att samma enheter mäts!
  if ( typ == t.typ )
    return (grader - t.grader);
  else
    {
      cout << "Olika enheter!!!" << endl;
      return -99999;
    }
}

double temperatur::fahrenheit()
{
  if ( typ == "Celsius" )        // Om Celsius, så konvertera.
    return ( 32 + 1.8*grader );
  else
    return grader;             // Annars, låt vara.
}
 
void temperatur::rapport( int nedre, int oevre )
{ 
  string s1 = "Oh! Vad varmt det är idag.";
  string s2 = "Oh! Vad kallt det är idag.";
  string s3 = "Det är lagom varmt idag.";
	
  if ( grader < nedre ) 
    cout << s2;
  else if ( grader < oevre ) 
    cout << s3;
  else 
    cout << s1;

  cout << endl;
}
/* KÖRNINGSEXEMPEL:
     Vi skall studera medeltemp en vecka i juli 2002.
Fahrenheit eller Celsius?
Celsius
Ge sju st medeltemperaturer i angiven enhet:
15 19 17 22 34 22 21 15 25 34
Nu testar vi att skriva ut alla i vacker tabell
Temperaturen är 15 grader Celsius.
Det är lagom varmt idag.
Temperaturen är 19 grader Celsius.
Det är lagom varmt idag.
Temperaturen är 17 grader Celsius.
Det är lagom varmt idag.
Temperaturen är 22 grader Celsius.
Oh! Vad varmt det är idag.
Temperaturen är 34 grader Celsius.
Oh! Vad varmt det är idag.
Temperaturen är 22 grader Celsius.
Oh! Vad varmt det är idag.
Temperaturen är 21 grader Celsius.
Oh! Vad varmt det är idag.
*/

