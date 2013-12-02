#include <iostream>
#include <string>
using namespace std;

void ersatt( string& str, const string& nyckel, const string& av);

int main() {
  string strang;
  string ord;

  cout << "Skriv in lite text: ";
  getline(cin, strang);
  cout << "Skriv in ett ord att leta i texten: ";
  cin >> ord;

  ersatt( strang, ord, "["+ord+"]");

  cout << strang << endl;
  return 0;
}

void ersatt( string& str, const string& nyckel, const string& av)
{
  string::size_type pos = str.find(nyckel);
  while (pos != string::npos)
    {
      str.replace(pos, nyckel.length(), av);
      pos = str.find(nyckel, pos+av.length()); // börja leta efter ersättningen
    }
}

