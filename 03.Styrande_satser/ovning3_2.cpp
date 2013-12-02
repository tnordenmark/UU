#include <iostream>
using namespace std;

int main()
{
  int year;

  cout << "Vilket år är du född? "; //fråga efter födelseår
  cin >> year; //inmatning av födelseår

  if (year < 2000)
    cout << "Du är född förra årtusendet." << endl; //Se exemplet ovan
  else
    cout << "Du är född detta årtusende." << endl;  

return 0;
}