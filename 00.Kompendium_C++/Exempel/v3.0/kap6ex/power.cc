// Filnamn: .../power.cc

double power( double x, int n ) {
  double  p;
  
  for ( p = 1.0; n > 0; n-- )
    p = p*x;
  return p;
}
