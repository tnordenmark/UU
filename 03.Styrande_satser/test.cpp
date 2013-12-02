#include <iostream> 
using namespace std; 
int main() 
{
  int a, b, c, d; 
  cout << "Ange a och b:\n"; 
  cin >> a >> b; 
  c = 0; d = 1; 

  for (int i = a; i <= b; i++) 
    { 
      c += i; 
      d *= i; 
    } 

  cout << "c = " << c << endl; 
  cout << "d = " << d << endl; 
  return 0; 

}