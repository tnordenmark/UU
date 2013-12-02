#include <fstream>  // för ofstream
using namespace std;
int main()
{
    ofstream fout( "message.dat" );
    int antalStudenter = 40;
    int antalReserver = 250;
    
    fout << "Välkommen till kursen Datorer och programmering" << endl;
    fout << "Du är en av " << antalStudenter << " antagna" << endl;
    fout << "Du måste anmäla om du vill" << endl;
    fout << "ha kvar din plats, vi har " << endl;
    fout << antalReserver << " personer till som " << endl;
    fout << "också vill gå kursen!" << endl;
    
    return 0;
}
