#include <iostream>
#include <string>
using namespace std;

string takestring()
{
    string s;
    cout << "Enter your string? \n";
    getline(cin, s);
    return s;
}

string trimrleft(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            return s.substr(i);
        }
    }
    return ""; // If all spaces, return an empty string
}

string trimright(string s)
{
    int i = s.length() - 1;
    while (i >= 0 && s[i] == ' ')
    {
        i--;
    }
    return s.substr(0, i + 1);
}

int main()
{
    string s = "    Bilal Mohammed    "   ;
    string leftTrimmed = trimrleft(s);
    string rightTrimmed = trimright(s);
    string fullyTrimmed = trimright(trimrleft(s)); // Corrected: Apply both left and right trimming

    cout << "string      = [" << s << "]" << endl;

    cout << "Trim left   = [" << leftTrimmed << "]" << endl;
    cout << "Trim right  = [" << rightTrimmed << "]" << endl;
    cout << "Trim        = [" << fullyTrimmed << "]" << endl;

    return 0;
}
