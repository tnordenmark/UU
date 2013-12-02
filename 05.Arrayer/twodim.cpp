#include <iostream>
using namespace std;

int main() 
{
  // En array med 2x3 st element (int)
  // Arrayen har 2 st index. Det första löper från 0-1.
  // Det andra löper från 0-2
  // Elementen initieras till:
  // twodim[0][0]=3, twodim[0][1]=2, twodim[0][2]=7,
  // twodim[1][0]=6, twodim[1][1]=2, twodim[1][2]=8,

  int twodim[2][3] = { {3, 2, 7} , {6, 2, 8} }; 

  // ex. utskrift av ett av element
  //cout << twodim[0][2];

  // ex. utskrift av alla elementen
  // Skriv ut med 3 st värden per rad och tab mellan värdena
  for (int i=0; i<2; i++) // radloopen (första index)
  {
     for (int j=0; j<3; j++) // kolumnloopen (andra index)
        cout << twodim[i][j] << "\t" ;

     cout << endl; // radbyte
  } 
  return 0; 
}