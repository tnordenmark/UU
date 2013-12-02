// Filnamn: .../linSearch.cc
// Linjär sökning i array

int linSearch( int data[], int antal, int key ) {
  // Om key finns med i data returneras dess index, annars -1
    for ( int i=0; i<antal; i++ )
        if ( data[i]==key ) return i;
    return -1;
}
