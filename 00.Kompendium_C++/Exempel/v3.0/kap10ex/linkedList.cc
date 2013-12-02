// Filnamn : .../linkedList.cc
#include <iostream>
using namespace std;

class listElement {
public:
  listElement();
  listElement(int newKey, listElement *follower);
  ~listElement();
  void printList();
protected:
  int key;
  listElement *next;
};

listElement::listElement() {
  key = 0;
  next = 0;    // Null-pekaren
}


listElement::listElement(int newKey, listElement *follower) {
  key = newKey;
  next = follower;    // Null-pekaren
}

listElement::~listElement() {
  if (next) delete next;
}

void listElement::printList() {
  cout << key;
  if (next)
   (*next).printList(); // recursive call to print the rest
}

int main() {
  listElement *first = 0;   // Null pointer initially
  cout <<"Give positive integers. Terminate with zero" << endl;
  int number;
  cin >> number;
  while (number > 0) {
    first = new listElement(number,first);
    cin >> number;
        }
  (*first).printList();
}
