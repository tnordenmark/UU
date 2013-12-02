//-------------------------------------------
// uppgift1.cpp


#include <iostream>
#include <string>
using namespace std;

int main()
{ 
  int a = 3;   
  int *b = &a;
  cout << "\n  b = " <<  b << endl;
  cout << "\n *b = " << *b << endl;

  int c = 5; 
  b = &c; 
  cout << "\n b = " << b << endl;
  cout << "\n c = " << c << endl;
  cout << "\n c var = 5 och b=&c gör att  *b blir = " << *b << endl;

  *b = 100;
  cout << "\n *b=100 gör att även c blir = " << c << endl;
  return 0;
}
