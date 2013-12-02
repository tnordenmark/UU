#include <iostream>
using namespace std;

const int ANTAL_BOKSTAVER = 26;  //A-Z
const int ANTAL_SPRAK = 4;
const double FREKV[ANTAL_SPRAK][ANTAL_BOKSTAVER]=
      {{8.27,1.48,2.94,4.03,11.78,2.22,1.72,6.77, //engelska: frekvens för A-Z
        7.39,0.12,0.81,3.76,2.85,6.71,7.79,1.54,
        0.05,5.95,6.69,9.07,2.66,1.13,2.14,0.19,
        1.89,0.03},
       {7.97,1.40,3.55,3.79,16.89,1.02,1.00,0.75, //franska: frekvens för A-Z
        7.08,0.38,0.04,5.51,2.82,8.11,5.19,2.78,
        1.01,6.69,8.35,7.22,6.09,1.35,0.02,0.54,
        0.30,0.15},
       {9.50,1.11,1.53,5.30,8.94,1.74,3.57,3.94,  //svenska: frekvens för A-Z
        3.98,0.89,3.26,4.93,3.41,8.46,5.01,1.77,
        0.00,6.73,5.56,9.20,1.94,2.42,0.00,0.05,
        0.45,0.00},
       {5.12,1.95,3.57,5.07,16.87,1.35,3.00,5.79, //tyska: frekvens för A-Z
        8.63,0.19,1.14,3.68,3.12,10.64,1.74,0.42
,        0.01,6.30,6.99,5.19,3.92,0.77,1.79,0.01,
        0.69,1.24}};

int main()
{
  cout << "      Eng" << "       Fra" << "       Sve" << "      Tys" << endl;

  for(int i=0; i<ANTAL_BOKSTAVER; i++)
  {
    for(int j=0; j<ANTAL_SPRAK; j++)
    {
      cout << "      " << FREKV[j][i];
    }

    cout << endl;
  }

  return 0;
}