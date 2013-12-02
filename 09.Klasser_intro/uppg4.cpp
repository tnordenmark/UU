#include <iostream>
#include <string>
using namespace std;


//Deklaration av klassen temperatur
class temperatur
{
private:
    double grader;                      // Gradtal
    string typ;                         // "Celsius" eller "Fahrenheit"

public:
    temperatur();                       // default-konstruktor
    temperatur(double t, string typen); // överlagrad konstruktor
    ~temperatur();                      // destruktor
    void lasin();                       // inläsning av grader
    void skriv();                       // utskrift av grader
    double haemta_grader();             // selektor, returnerar grader
    string haemta_typ();                // selektor, returnerar typ
    double skillnad(temperatur t);      // skillnaden mellan 2 temperaturer
    double fahrenheit();                // returnerar grader i Fahrenheit
    void rapport(int nedre, int oevre); // skriver "rapport"
};
//=================================================
// Huvudprogram för temperaturomvandling.

int main()
{
    const int ANTALTEMP = 7;
    temperatur juli2002[ANTALTEMP];
    string typ;
    double temp;

    cout << "Celsius eller Fahrenheit?" << endl;
    getline(cin, typ);

    cout << "Ange sju st medeltemperaturer i angiven enhet:" << endl;
    
    for(int i = 0; i < ANTALTEMP; i++)
    {
        cin >> temp;
        juli2002[i] = temperatur(temp, typ);
    }

    cout << "Skriv ut temperaturerna i en vacker tabell" << endl;    

    for(int i = 0; i < ANTALTEMP; i++)
    {
        juli2002[i].skriv();
        juli2002[i].rapport(10, 20);
    }


    return 0;
}
//=================================================
// Definition av metoderna i klassen temperatur

temperatur::temperatur()
{
    grader = 28;
    typ = "Celsius";
}
//-------------------------------------------------
temperatur::temperatur(double t, string typen)
{
    grader = t;
    typ = typen;
}
//-------------------------------------------------
temperatur::~temperatur()
{
}
//-------------------------------------------------
void temperatur::lasin()
{
    cout << "Ange grader: ";
    cin >> grader;
    cin.get(); // Läs förbi returtecknet

    cout << "Ange typen: ";
    getline(cin, typ);
}
//-------------------------------------------------
void temperatur::skriv()
{
    cout << "Temperaturen är " << grader << " grader " << typ << "." << endl;
}
//-------------------------------------------------
double temperatur::haemta_grader()
{
    return grader;
}
//-------------------------------------------------
string temperatur::haemta_typ()
{
    return typ;
}
//-------------------------------------------------
double temperatur::skillnad(temperatur t)
{
    if(typ == t.typ)
        return (grader - t.grader);
    else
    {
        cout << "Olika enheter!" << endl;
        return -99999;
    }
}
//-------------------------------------------------
double temperatur::fahrenheit()
{
    if(typ == "Celsius")
        return (32 + 1.8 * grader);
    else
        return grader;
}
//-------------------------------------------------
void temperatur::rapport(int nedre, int oevre)
{
    string varmt = "Oh! Vad varmt det är idag!";
    string kallt = "Oh! Vad kallt det är idag!";
    string lagom = "Det är lagom varmt idag.";

    if(grader < nedre)
        cout << kallt;
    else if(grader < oevre)
        cout << lagom;
    else
        cout << varmt;

    cout << endl;
}
