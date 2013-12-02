// File name : .../ex06.cc

#include <iostream.h>
#include <math.h>

const int maxRow = 25;    // 25 rader text i diagrammet
const int maxCol = 80;    // 80 tecken bred skärm.

//              Deklaration av funktioner

void PrintScreen( char Screen[maxCol][maxRow] );
void InitScreen( char Screen[maxCol][maxRow], char c );
void FrameScreen( char Screen[maxCol][maxRow] );
void MakeSinus( char Screen[maxCol][maxRow] );

int main() {
  char AScreen[maxCol][maxRow];   // Our screen buffer
  InitScreen( AScreen, ' ' );
  FrameScreen( AScreen );
  MakeSinus( AScreen );
  PrintScreen( AScreen );
  return 0;
}

//         Härefter kommer definitionerna av funktionerna
//         Av platsbrist i manuset hoppar vi över dem
//         Programmet i sin helhet kan studeras, se filnamnet.
//*************************************************************
