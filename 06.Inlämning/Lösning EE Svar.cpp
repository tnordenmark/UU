#include <fstream>
#include <iostream>
#include <string>
using namespace std;
 
const int MAX_KOMPISAR = 20 ;
const int MAX_TRANSAKTIONER = 50 ;
 
class Transaktion
 
{
private:
  string datum ;                    
  string typ ;                       
  string namn ;                      
  double belopp ;                    
  int ant_kompisar ;                 
  string kompisar [MAX_KOMPISAR] ;   
public:
  Transaktion() ;                    
  ~Transaktion() ;                 
  string haemta_namn () ;            
  double haemta_belopp () ;          
  int haemta_ant_kompisar () ;     
  bool finnsKompis ( string namnet ) ; 
  bool laesEnTrans ( istream &is ) ;   
  void skrivEnTrans ( ostream &os ) ;  
};
 
class TransaktionsLista
{
private:
  Transaktion trans[MAX_TRANSAKTIONER] ;  
  int antalTrans ;                        
public:
  TransaktionsLista () ;                  
  ~TransaktionsLista () ;                 
  //void laesin ( istream &is ) ;           
  void skrivut ( ostream &os ) ;          
  void laeggTill ( Transaktion &t ) ;     
  double totalkostnad ( int belopp ) ;    
  double liggerUteMed ( string namnet ) ; 
  double aerSkyldig ( string namnet ) ;   
  //Personlista FixaPersoner () ;
};
// ==================================================================
 
int main()
{
  Transaktion t ;           
  TransaktionsLista tl ;       
  int val = -1;                
  string namnet ;              
//  RX: int belopp ;                  
  int belopp = 0;                  
  
  const int MAX = 20  ;         
  Transaktion kvitto[MAX] ;      
  int antal = 0 ;               
 
  ifstream is( "file.txt" ) ;      
  ofstream os ( "newfile.txt" ) ; 
  
  while ( t.laesEnTrans ( is ) )  
  {
    tl.laeggTill( t ) ;
    kvitto[antal] = t ;
    antal++;
  }
  
  is.close();  
  
  while ( val!=0 )
  {
    cout << "Starting with opening a file." << endl ;
    cout << "Select from the menu below:" << endl ;
    cout << "0) Close. All transactions will be saved to file." << endl ;
    cout << "1) Read a transaction from the keyboard." << endl ;
    cout << "2) Write info on all transactions." << endl ;
    cout << "3) Calculate the total cost." << endl ;
    cout << "4) How much does a certain person owe?" << endl ;
    cout << "5) How much has a certain person paid for?" << endl ;
    cout << "6) Make a list of all persons: what they have paid themselves"
                " and what the owe others!" << endl ;
    cin >> val ;
    
    if ( val == 1 )   
    {
      bool x = t.laesEnTrans ( cin ) ;
      kvitto[antal] = t ;
      antal++ ;
    }
    else if ( val == 2 )   
    {
      for ( int ii=0; ii<antal; ii++ )  
        kvitto[ii].skrivEnTrans( cout ) ; 
      for ( int ii=0; ii<antal; ii++ )   
        kvitto[ii].skrivEnTrans( os ) ;
    }
    else if( val == 3 )    
    {
      cout << "The total cost is " << tl.totalkostnad( belopp )<< endl; 
    }
    else if ( val == 4 )
    {
      cout << "Give the name" << endl ;
      cin >> namnet ;   
    }
    else if ( val == 5 )
    {
      cout << "Give the name" << endl ;
      cin >> namnet ;
    }
  }
  os.close(); 
  
  return 0 ;
}
// ==================================================================
 
TransaktionsLista::TransaktionsLista ()
{
  antalTrans = 0 ;
}
// ------------------------------------------------------------------
TransaktionsLista::~TransaktionsLista ()
{
}
// ------------------------------------------------------------------
//void TransaktionsLista::laesin ( istream &is )
 
 
// ------------------------------------------------------------------
void TransaktionsLista::skrivut ( ostream &os )
 
{
  for (int i = 0; i < antalTrans; i++) 
  {
    trans[i].skrivEnTrans( os );
  }
}
// ------------------------------------------------------------------
void TransaktionsLista::laeggTill ( Transaktion &t )
 
{
  trans[antalTrans] = t ;
	antalTrans++;
}
// ------------------------------------------------------------------
double TransaktionsLista::totalkostnad ( int belopp )
 
{
  double utgifter = 0.0 ;
 
  for (int i = 0; i < antalTrans; i++)
    utgifter += trans[i].haemta_belopp() ;
 
  return utgifter ;
}
// ------------------------------------------------------------------
double TransaktionsLista::liggerUteMed ( string namnet ) 
// Here I need some help
{
  double betalat = 0.0 ;
  
  for (int i = 0; i < antalTrans; i++)
    {
// RX:   if (namnet == trans[i].haemta_namn)
      if (namnet == trans[i].haemta_namn())
      betalat += trans[i].haemta_belopp() ;
    }
  
  return betalat ;
}
// ------------------------------------------------------------------
double TransaktionsLista::aerSkyldig ( string namnet )
// Here I need some help
{
  double skyldig = 0.0;
 
  for (int i = 0; i < antalTrans; i++) 
    {
// RX:   if ( namnet == t.finnsKompis(namnet) )
      if ( trans[i].finnsKompis(namnet) )
        skyldig += trans[i].haemta_belopp() ;
    }
  return skyldig ;
}
// ------------------------------------------------------------------
/*PersonLista FixaPersoner ()
// Ska skapa och returnera ett objekt av typen PersonLista...
{
 
} */
// ==================================================================
 
Transaktion::Transaktion ()
{
  datum = "" ;
  typ = "" ;
  namn = "" ;
  belopp = 0.0 ;
  ant_kompisar = 0 ;
  {
    for ( int i = 0; i < ant_kompisar; i++ )
      kompisar[i] ;
  }
}
// ------------------------------------------------------------------
Transaktion::~Transaktion ()
{
}
// ------------------------------------------------------------------
string Transaktion::haemta_namn ()
{
  return namn ;
}
// ------------------------------------------------------------------
double Transaktion::haemta_belopp ()
{
  return belopp ;
}
// ------------------------------------------------------------------
int Transaktion::haemta_ant_kompisar ()
{
  return ant_kompisar ;
}
// ------------------------------------------------------------------
bool Transaktion::finnsKompis ( string namnet )
 
{
  for ( int i = 0; i < ant_kompisar; i++ )
    {
      if ( namnet == kompisar[i] ) return true ; 
    }
  return false ;
}
// ------------------------------------------------------------------
bool Transaktion::laesEnTrans ( istream &is )
{   
  is >> datum >> typ >> namn >> belopp >> ant_kompisar ;
 
  string temp ;
  for ( int i = 0; i < ant_kompisar; i++ )
   {
     is >> temp;
     if ( is.eof() ) return false;
     kompisar[i] = (temp);     
   }
  return !is.eof();
}
// ------------------------------------------------------------------
void Transaktion::skrivEnTrans ( ostream &os )
{
  os << datum << "\t" << typ << "\t" << namn << "\t" << belopp
      << "\t" << ant_kompisar ;
 
  for ( int i = 0; i < ant_kompisar; i++ )
    {
      os << "\t" << kompisar[i] ;
    }
  os << endl ;
}