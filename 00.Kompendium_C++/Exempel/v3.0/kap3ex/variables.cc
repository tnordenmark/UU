//  File name : .../variables.cc
//
//  Demonstrates variable declaration and adress   

#include <iostream>
using namespace std;

int main()
{
  int intval = 3;               // integer variable with value 3
  double realval = 3.141593;    // real variable with value 3.14....
 
  cout << "Variable intval has value "       << intval   << "\n";
  cout << "Variable realval has value "      << realval  << "\n";
  cout << "Size in bytes of an int   " << sizeof(intval)  << "\n";
  cout << "Size in bytes of a double " << sizeof(realval) << "\n\n";

  intval  = 3.14;
  realval = 7.12;

  cout << "Variable intval has value "       << intval   << "\n";
  cout << "Variable realval has value "      << realval  << "\n";

  return 0;
}
