#include <iostream>
#include <string>
using namespace std;

// KLASS: Dog, en hund som kan skälla
class Dog
{
// Objekt
public:
    string name;
    int age;
    string race;
    
// Metoder
public:
    static void Info();
    Dog(string _name, int _age, string _race);
    void Bark();
};

int main()
{
    Dog::Info();
    Dog myDog("Fido", 3, "pudel");

    cout << "Hunden heter " << myDog.name << ", är en " << myDog.race << " och är " << myDog.age
         << " år gammal." << endl;
    myDog.Bark();

    cin.get();
    
    return 0;
}

// METOD: Dog::Dog, konstruktor
Dog::Dog(string _name, int _age, string _race)
{
    name = _name;
    age = _age;
    race = _race;
}

// METOD: Bark, hunden skäller.
void Dog::Bark()
{
    if(age > 1)
        cout << name << " skäller VOFF VOFF!";
    else
        cout << name << " är bara en liten valp och vågar inte skälla på dig.";
}

// METOD: Dog::Info, statisk metod som ger information
void Dog::Info()
{
    cout << "Hundar är fyrbenta djur." << endl;
}
