#include <iostream>
using namespace std;

const int MAX = 5;

int main()
{
  double array[MAX];
  int i;

  for(i=0; i<MAX; i++)
  {
    cout << "Ange nummer " << i+1 << ": ";
    cin >> array[i];
  }

  for(i=MAX-1; i>=0; i--)
  {
    cout << array[i] << endl;
  }
}
