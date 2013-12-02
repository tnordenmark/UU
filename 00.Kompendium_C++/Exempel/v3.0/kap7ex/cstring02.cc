// Filnamn: .../cstring02.cc
// Exempel på strängar

#include <iostream.h>
#include <string.h>    // headerfil för stränghantering

int main() {
  char s1[20] = "Rickard";
  char s2[20] = " Filippa";
  char s3[20] = ".";
  
  cout << "Size of s1 : " << sizeof(s1) << endl;       
  cout << "Lenght of s1 : " << strlen(s1) << endl;  // strlen
  cout << "Lenght of s2 : " << strlen(s2) << endl;                  
  
  strcat( s1,s2 );                          // strcat
  cout << "Result of strcat : " << s1 << endl ;
  
  strcpy( s3,"Rickard Enander" );           // strcpy
  cout << "Comparing : " << s1 << " and " << s3 << endl;  
  
  cout << "Result : " << strcmp( s1,s3 ) << endl;        // strcmp
  cout << "Result (3) : " << strncmp( s1,s3,3 ) << endl; // strncmp
  cout << "Result (9) : " << strncmp( s1,s3,9 ) << endl;  
  return 0;
}
