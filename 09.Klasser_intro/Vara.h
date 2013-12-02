#ifndef __Vara__ 
#define __Vara__

// Klassdeklaration för klassen Vara.
// Lite utökad med nya metoder, t.ex. med
// metoder SammaVara och MindreAen
// Filnamn: Vara.h

#include <iostream>
#include <string>
using namespace std;

class Vara
{
private:
    string Namn;
    double Pris;
    int    Antal;

public:
    void LaesIn();                      //Läs från tangentbord.
    void TillLager(int AntalNya);       //Nya till lagret.
    void Saelja(int AntalSaelj);        //Sälj vara.
    void ProcentPris(double Faktor);    //Sätt nytt pris.
    void SkrivUt();                     //Skriv info om vara.
};

#endif
