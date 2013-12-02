// Filnamn : .../Account0/Account.cc
// Första versionen av ett bankkonto.
#include <iostream>
#include <string>
using namespace std;

// Klassdefinition för hantering av bankkonton.

class Account {

public:       // Publika metoder
  void input() {
    cout << "Ge namn : ";
    getline(cin, name);
    balance = 0;
  }
  
  void deposit( double amount ) { balance += amount; }
  
  void withdraw( double amount ) { balance -= amount; }
  
  void print() {
    cout << name << " har " << balance 
         << " på sitt konto " << endl;
  }
  
protected:    // Skyddade datafält
  string name;
  double balance;
}; // Här är klassdefinitionen slut


// Ett litet testprogram

int main() {  
  // Deklaration av 2 objekt av klassen Account
  Account lisa;
  Account olle;

  lisa.input();
  olle.input();
  lisa.print();
  olle.print();
  lisa.deposit( 500 );
  lisa.withdraw( 350 );
  lisa.print();
  return 0;
}
