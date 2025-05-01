#include <iostream>
#include <string>
#include <vector>
using namespace std;

string takestring()
{
	string s;
	cout << "enter your string? \n";
	getline(cin, s);
	return s;
}
char invertchar(char s)
{
	return isupper(s) ? (char)tolower(s) : (char)toupper(s);
}
void words(string s, vector <string>& str)
{
	string delim = " ";
	int pos = 0;
	string sword;
	while ((pos = s.find(delim)) != std::string::npos)
	{
		sword = s.substr(0, pos);
		if (sword != "")
		{
			str.push_back(sword);
		}
		s.erase(0, pos + delim.length());
	}
	if (s != "")
	{
		str.push_back(s);
	}
}
string replaceword(vector <string> str, string replace)
{
	string vword = "";
	for (string &item : str)
	{
		if (item == "Jordan")
		{
			item = replace;
		}
		vword += item + " ";
	}
	return vword.substr(0, vword.length() - 1);
}

int main()
{
	string s = "welcome to Jordan , Jordan is a nice country";
	string replacable = "USA";
	vector <string> vString;
	cout << s << endl;

	words(s, vString);
	cout << "\nstring after replace : \n";
	cout << replaceword(vString, replacable);
	return 0;
}