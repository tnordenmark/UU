//  Filnamn: .../grade.cc

#include <iostream>
using namespave std;

int main() {
  int grade;

  cout << "Give me your latest grade : ";
  cin >> grade;

  switch ( grade ) {
    case 1 :
      cout << " Too much beer?" << endl;
      break;
    case 2 :
      cout << " Better luck next time" << endl;
      break;
    case 3 :
      cout << " No extra work done" << endl;
      break;
    case 4 :
      cout << " One or two hours too much studied?" << endl;
      break;
    case 5 :
      cout << " You are a too ambitious, ease up!" << endl;
      break;
    default :
      cout << " Unknown grade!!" << endl;
      break;
  }
  return 0;
}
