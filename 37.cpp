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

void words(string s, vector <string> &str)
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
void print(vector<string> s)
{
	for (string &words : s)
	{
		cout << words;
		cout << endl;
	}
}

int main()
{
	string s = takestring();
	vector <string> tokens;

	words(s, tokens);
	cout << "token : " << tokens.size() << endl;
	print(tokens);
	
	return 0;
}