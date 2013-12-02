// Filnamn : .../Bank1/Bank.cc

#include <iostream>
#include "Account.h"
using namespace std;

const int MAX_NR_ACC = 100; // Arraystorlek. Maximalt antal konton

class Bank {
public:
  Bank();              // Standardkonstruktor
  
  void newAccount();
  void printAllAccounts();
  
protected:
  string name;         // Banknamn
  int noOfAcc;         // Antal befintliga konton. Fungerar även
                       // som index till första fria position.
  Account accounts[MAX_NR_ACC]; // Array med konton
};

Bank::Bank() {
  noOfAcc = 0;         // Inga konton från början
  name    = "TDBank";
}

void Bank::newAccount() {
  // Kontroll om fler konton får plats
  if (noOfAcc >= MAX_NR_ACC)
    cout << "Inga fler konton får plats!" << endl;
  else {
    accounts[noOfAcc].input();
    noOfAcc++;
  }
}

void Bank::printAllAccounts() {
  cout << endl << "Följande konton finns i " 
       << name << " : \n";

  for (int i=0; i<noOfAcc; i++) 
    accounts[i].print();
}

// Ett litet testhuvudprogram
int main() {
  int nr;
  Bank myBank;

  myBank.printAllAccounts();
  cout << "Hur många konton ska läggas in : ";
  cin >> nr;
  cin.get();   // Läs bort returtecknet

  for(int i=1; i<=nr; i++)
    myBank.newAccount();
  myBank.printAllAccounts();

  return 0;
}
