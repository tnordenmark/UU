#include <iostream>
#include <string>
using namespace std;

//Deklaration av klassen temperatur

class temperatur
{
private:
    double grader;                      // i Celsius
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
    temperatur t1, t2;
    temperatur t3(35, "Celsius"), t4(100, "Fahrenheit");
    t2.lasin();

    t1.skriv();
    t2.skriv();
    t3.skriv();
    t4.skriv();
    t3.rapport(5, 15);
    t4.rapport(75, 90);

    double temp = t1.haemta_grader();
    string grad_enhet = t1.haemta_typ();
    cout << "Default-objekt: " << temp << endl << " " << grad_enhet << endl;

    double f = t1.fahrenheit();
    cout << temp << " grader Celsius motsvaras av " << f
        << " grader Fahrenheit." << endl;

    double d = t2.skillnad(t3);
    cout << "Skillnaden mellan " << t2.haemta_grader() << " och "
         << t3.haemta_grader() << " är " << d << endl;

    return 0;
}
//=================================================
// Definition av metoderna i klassen temperatur

temperatur::temperatur()
{
    grader = 28;
    typ = "Celsius";
    cout << "Jag är default-konstruktor: grader = " << grader << endl;
}
//-------------------------------------------------
temperatur::temperatur(double t, string typen)
{
    grader = t;
    typ = typen;
    cout << "Jag är överlagrad konstruktor: grader = " << grader << endl;
}
//-------------------------------------------------
temperatur::~temperatur()
{
    cout << "Nu dödas objektet med temperatur = " << grader << endl;
}
//-------------------------------------------------
void temperatur::lasin()
{
    cout << "Ange grader: ";
    cin >> grader;
    cin.get();

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
