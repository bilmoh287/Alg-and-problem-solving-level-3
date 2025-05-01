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
string reverseword(vector<string> s)
{
	string str = "";
	//for (int i = s.size()-1; i >= 0 ; i--)
	//{
	//	str += s[i] + " ";
	//}
	vector<string>::iterator itr = s.end();
	while (itr != s.begin())
	{
		--itr;
		str += *itr + " ";
	}
	return str.substr(0, str.length() - 1); // remove last element
}

int main()
{
	string s = takestring();
	vector <string> vString;

	words(s, vString);
	cout << "\nstring after reverse word : \n";
	cout << reverseword(vString);
	return 0;
}