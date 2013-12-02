// Filnamn: .../ex05.cc

#include <iostream.h>

int main() {
  int twoD[8][6];

  for (int i=0; i<8; i++ )
    for (int j=0; j<6; j++)
      twoD[i][j] = i*10 + j;

  for (i=0; i<8; i++ ) {
    for (int j=0; j<6; j++) {
      cout.width(8);    // ser till bredd=8 på utskrift
      cout << twoD[i][j];
    }
    cout << endl;
  }
  return 0;
}
