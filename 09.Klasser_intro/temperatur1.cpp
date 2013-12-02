#include <iostream>
#include <string>
using namespace std;

// Uppgift 1: temperatur1.cpp

// Deklaration av klassen:

class  temperatur
{
private:
  double grader;        // i Celsius.
       
public:
  temperatur();         // default-konstruktor
  temperatur(double t); // överlagrad konstruktor 
  void lasin();         // inläsning av grader
  void skriv();         // utskrift av grader
  double haemta_grader();        // selektor: returnerar grader
  double skillnad(temperatur t); // skillnaden mellan 2 temperaturer
  double fahrenheit();           // returnerar grader i Fahrenheit
  void rapport();       // skriver "rapport"
};
//------------------------------------------------------
// Huvudprogram:

int main()
{
  temperatur t1, t2, t3(35);

  cout << "Vi hanterar lite grader i Celsius..." << endl;
  t2.lasin();

  t1.skriv();
  t2.skriv();
  t3.skriv();
  
  t3.rapport();
  double temp = t1.haemta_grader();
  cout << "Default-temperatur är = " << temp << endl;

  double f = t1.fahrenheit();
  cout << temp 
       << " grader Celsius motsvaras av "
       << f << " grader Fahrenheit." << endl;
  
  double d = t2.skillnad(t3);
  cout << "Skillnaden mellan " << t2.haemta_grader()
       << " och " << t3.haemta_grader()
       << " = " << d << endl;

  return 0;
}

//------------------------------------------------------
// Implementation av klassens metoder:

// ---Konstruktorer---

temperatur::temperatur() // default-konstruktor
{ 
  grader = 28;  
}

temperatur::temperatur( double t )
{ 
  grader = t;
}

// ---Medlemsfunktioner--- 

void temperatur::lasin()
{
  cout << "\nAnge grader: ";
  cin >> grader;
}

void temperatur::skriv()
{ 
  cout << "Temperaturen är "<< grader << " grader Celsius." << endl;
}
  
double temperatur::haemta_grader()
{ 
  return grader;
}

double temperatur::skillnad( temperatur t )
{ 
  return (grader - t.grader);
}

double temperatur::fahrenheit()
{
  return ( 32 + 1.8*grader );
}
 
void temperatur::rapport()
{ 
  string s1 = "\nOh! Vad varmt det är idag.";
  string s2 = "\nOh! Vad kallt det är idag.";
  string s3 = "\nDet är lagom varmt idag.";
	
  if ( grader < 5 ) 
    cout << s2;
  else if ( grader < 15 ) 
    cout << s3;
  else 
    cout << s1;

  cout << endl;
}
     
/* Körningsexempel:
Ange grader: 37
Temperaturen är 28 grader Celsius.
Temperaturen är 37 grader Celsius.
Temperaturen är 35 grader Celsius.

Oh! Vad varmt det är idag.
Default-temperatur är = 28
28 grader Celsius motsvaras av 82.4 grader Fahrenheit.
Skillnaden mellan 37 och 35 = 2
kursa> CC temperatur1.cpp
kursa> a.out
Vi hanterar lite grader i Celsius...

Ange grader: 25
Temperaturen är 28 grader Celsius.
Temperaturen är 25 grader Celsius.
Temperaturen är 35 grader Celsius.

Oh! Vad varmt det är idag.
Default-temperatur är = 28
28 grader Celsius motsvaras av 82.4 grader Fahrenheit.
Skillnaden mellan 25 och 35 = -10
 */
