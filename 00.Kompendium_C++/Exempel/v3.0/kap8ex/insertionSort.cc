// Filnamn: .../insertionSort.cc
// Instickssortering

void insSort( int data[], int n ) {
     for (int i=1; i<n; i++) {
            // Element på plats i skall infogas bland
            // elementen på platserna 0, 1, ... i-1
         int temp = data[i];
            // Flytta undan tills rätt plats funnen
         for ( int j = i; j>0 && k < data[j-1]; j-- )
             data[j] = data[j-1];
         data[j] = temp;
     }
}
