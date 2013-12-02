// Filnamn: .../ex01.cc

#include <iostream>
using namespace std;

int main() {
  int NumOfItems[3];      // Deklarera en array med 3 int
  NumOfItems[0] = 3;
  NumOfItems[1] = 5;
  NumOfItems[2] = 7;

  double ItemPrice[3] = { 2.50, 7.35, 3.35 };

  for ( int i=0; i<3; i++ )
    cout << "Value of items with number # " << i
         <<   " is : " << ItemPrice[i]*NumOfItems[i] << endl;

  double StockValue = 0.0;
  for ( i=0; i<3; i++)
    StockValue += NumOfItems[i]*ItemPrice[i];

  cout << "Value of whole stock : " << StockValue << endl;
  return 0;
}
