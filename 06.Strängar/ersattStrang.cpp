#include <iostream>
#include <string>
using namespace std;

void ersatt(string &str, const string &nyckel, const string &av)
{
    string::size_type pos = str.find(nyckel);
    while(pos != string::npos)
    {
        str.replace(pos, nyckel.length(), av);
        pos = str.find(nyckel, pos+av.length()); // Börja leta efter ersättningen
    }
}

int main()
{
    string str = "quietly, the quarrelsome queen quit the quiet headquarters.";
    ersatt(str, "qu", "kw");
    cout << str << endl;
}
