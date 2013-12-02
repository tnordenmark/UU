#include <iostream>
using namespace std;

int main()
{
const int sz = 5;   //1
double arr[sz];    //2

cout << "Ge fem flyttal" << endl;   //3
for ( int i = 0; i <sz; i++ )              //4 
{                                                
  cin >> arr[i];                             //5
}

double sum = 0;                          //6
for ( int i = 0; i <=sz; i++ )             //7
{
  sum += arr[i];                            //8
}
cout << "Summan av dina tal är " << sum << endl;   //9
}