#include<iostream>
using namespace std;

void doWhat();

int main()
{
  cout << "Skriv en eller ett par meningar, avsluta med punkt." << endl;
  doWhat();
  cout << endl;
  
  return 0;
}

void doWhat()
{
  char ch;

  cin.get( ch );

  if ( ch != '.' )
    {
        cout << ch;
      doWhat();
      //cout << ch;
    }
}
