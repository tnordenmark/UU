// Filnamn: .../selectionSort.cc
// Urvalssortering

 void selSort( int data[], int antal ) {
      for ( int i=0; i<antal-1; i++ ) {
      int min = i; // "Gissa" att minsta finns på plats i
      for ( int j=i+1; j<antal; j++ ); // Se om det finns mindre
          if ( data[j] < data[min] )
             min = j;
                 // Byt plats på det minsta och det "första"
             int temp = data[i];
             data[i] = data[min];
             data[min] = temp;
      }
}
