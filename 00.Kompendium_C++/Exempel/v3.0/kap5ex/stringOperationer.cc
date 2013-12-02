// Filnamn: .../stringOperationer.cc
// Exempel på operationer i typen string
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s = "mississippi";
  string t;

  s.append("missourie");
  cout << "s: " << s << endl;

  int pos1, pos2, pos3;
  pos1 = s.find("miss");
  pos2 = s.find("miss", pos1+1 );
  pos3 = s.find("miss", pos2+1 );
  cout << "\"miss\" finns i positionerna: " << pos1 
       << ", " << pos2 << " och " << pos3 << endl;

  s.replace(0, 1, "M");
  s.replace(pos2, 1, "M");
  s.insert(pos2,"-");   // Skjut in ett bindestreck

  cout << s << endl;

  int len = s.length();
  int pos = s.find("-");
  cout << "pos, len: " << pos << ", " << len << endl;
  t = s.substr(pos+1, len-pos-1);
  cout << t << endl;
  return 0;
}
