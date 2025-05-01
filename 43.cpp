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

string LowerAllString(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}
	return S1;
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

string replaceword(vector <string> str, string replaceto, string tobereplaced, bool matchcase = true)
{
	string vword = "";

	for (string& item : str)
	{
		if (matchcase)
		{
			if (item == tobereplaced)
			{
				item = replaceto;
			}
			vword += item + " ";
		}
		else
		{
			if (LowerAllString(item) == LowerAllString(tobereplaced))
			{
				item = replaceto;
			}
			vword += item + " ";
		}
	}
	return vword.substr(0, vword.length() - 1);
}


int main()
{
	string s = "welcome to Jordan , Jordan is a nice country";
	string replaceto = "USA";
	string tobereplaced = "jordan";
	vector <string> vString;

	cout << "\nOrigina string : \n";
	cout << s << endl;

	words(s, vString);
	cout << "\nReplace with match case : \n";
	cout << replaceword(vString, replaceto, tobereplaced);

	cout << "\n\nReplace with dont match case : \n";
	cout << replaceword(vString, replaceto, tobereplaced, false);
	return 0;
}