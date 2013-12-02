#include <iostream>
using namespace std;

const int MAX = 10;

int binsok(const double arr[], double nyckel, int  antal);

int main()
{
  double nyckel = 5;
  int antal = MAX;
  double arr[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int talindex = binsok(arr, nyckel, antal);
  
  if (talindex==-1)
    cout << nyckel << " finns ej" << endl;
  else 
    cout << nyckel << " finns på plats " << talindex
    << " i arrayen." << endl;

  return 0;
}

int binsok(const double arr[], double nyckel, int  antal)
{
  int index = -1, mitt;
  int vanster = 0, hoger = antal-1;
  bool hittat = false; // hypotesen är "ej hittat"

  // så länge som ...
  while ( vanster <= hoger && !hittat )
    {
      mitt = (vanster + hoger)/2;  // beräkna mitten i del-arrayen

      // Detta är bara en testutskrift för att få se vad som händer
      cout << "index, vänster, mitt, höger: "
	   << index << " " << vanster 
	   << " " << mitt << " " << hoger << endl;

      if ( arr[mitt] == nyckel )  // Nyckeln hittad
        { 
          hittat = true;
          index = mitt;
        }
      else if ( arr[mitt] > nyckel ) // är nyckeln till vänster om mitten?
        hoger = mitt-1;    // Ja
      else       
        vanster = mitt+1;  // Nej
    } // slut while
  
  return index; // Returnera platsen, eller -1 om inte hittad.
}