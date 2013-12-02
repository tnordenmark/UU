// Filnamn: .../binSearch.cc
// Binär sökning

int binSearch( int data[], int antal, int key ) {
    int first = 0, last = antal - 1;
    while ( first <= last ) {
       int mid = (first + last)/2;
       if ( data[mid] == key ) 
          return mid;
       else if ( key < data[mid] )
          last = mid - 1;
       else
          first = mid + 1;
     }
     return -1;
}
