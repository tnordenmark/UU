#include <iostream>
using namespace std;

void test(const int arr[]); // deklaration av funktionen test

int main()
{
  int tal[32];  //en array med 32 element

  cout << "Arrayens längd uttryckt i antal bytes = " << sizeof(tal) << endl;

  cout << "Arrayens längd uttryckt i antal element = " << 
    sizeof(tal)/sizeof(int) << endl;

  test(tal);  //anropa funktionen test

  return 0;

}

// funktionen får veta var i minnet som arrayen startar
void test(const int arr[]) // definition av funktionen test
{
  cout << "I funktionen test: " << sizeof(arr) << endl;
}