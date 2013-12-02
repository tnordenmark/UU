// File name: .../dance.cc

#include <iostream>

enum dance {
  WALTZ, FOXTROT, QUICKSTEP, TANGO, LINDY
};

int main() {
  dance first=WALTZ, next=QUICKSTEP, Favourite=TANGO;
  
  // Calculate next dance ...
  next = TANGO;
  
  if (next==Favourite)
    cout << "Dags för " << next << endl;
}
