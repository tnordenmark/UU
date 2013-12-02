// Filnamn : .../ex05.cc

#include <iostream>
#include <fstream>
#include "book.h"
#include "library.h"
using namespace std;

int main() {
  const string bibFileName="books.dat";
  library MyLib;
  InitLib( MyLib );
  ifstream inFile( bibFileName.c_str() );
  
  if ( inFile.good() ) {
    cout << "Reading data from old file " << endl;
    inFile.read( (char*) &MyLib, sizeof(MyLib) );
  }
  else {
    cout << "No data to read from old file" << endl;
  }

  inFile.close();

  int num;
  cout << "How many books do you want to enter : ";
  cin >> num;
  cin.get();

  for (int i=1; i<=num; i++) 
    inFile.read( (char*) &MyLib, sizeof(MyLib) );

  AddBookToLib( MyLib );
  PrintAllBooks( MyLib );

  ofstream outFile( bibFileName.c_str() );
  outFile.write( (char*) &MyLib, sizeof(MyLib) );
  outFile.close();

  return 0;
}
