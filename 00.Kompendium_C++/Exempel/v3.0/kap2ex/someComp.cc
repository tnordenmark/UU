//  Filnamn: .../someComp.cc
//
//  Ett andra exempel på ett program. Det läser in ett tal,
//  beräknar sinus och cosinus för talet samt
//  skriver ut resultaten.

#include <iostream>
#include <cmath>

using namespace std;

int main() {
  double  x, sinval, cosval;

  cout << "Hello again, please give me a number > ";
  cin  >> x;
  cout << "Thanks, I will make some calculations \n";

  sinval = sin(x);
  cosval = cos(x);
  cout << "The number you gave me was " << x << "\n";
  cout << "The cosine of that number is  " << cosval << "\n";
  cout << "The sine   of that number is  " << sinval << "\n";
  cout << "Bye for this time!\n";

  return 0;
}
