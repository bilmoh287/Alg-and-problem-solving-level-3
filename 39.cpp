#include <iostream>
#include <string>
#include <vector>
using namespace std;

string takestring()
{
    string s;
    cout << "Enter your string? \n";
    getline(cin, s);
    return s;
}
string joinstring(vector<string> join, string delim)
{
    string str = "";
    for (int i = 0; i < join.size(); i++)
    {
        str += join[i];
        if (i != join.size()-1)
            str += delim;
    }
    //return str.substr(0, str.length() - delim.length());
    return str;
}

int main()
{
    vector<string> join = { "Bilal", "Mohammed", "Abafita" };
    cout << "The string is = " << joinstring(join, " ^ ");
    return 0;
}
