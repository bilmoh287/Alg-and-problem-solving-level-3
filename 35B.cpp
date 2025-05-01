#include <iostream>
#include <string>
using namespace std;

string takestring()
{
	string s;
	cout << "enter your string? \n";
	getline(cin, s);
	return s;
}

void words(string s)
{
	string delim = " ";
	int pos = 0;
	string sword;
	while ((pos = s.find(delim)) != std::string::npos)
	{
		sword = s.substr(0, pos);
		if (sword != "")
		{
			cout << sword << endl;
		}
		s.erase(0, pos + delim.length());
	}
	if (s != "")
	{
		cout << s << endl;
	}
}
void print(string s)
{

}
int main()
{
	string s = takestring();
	words(s);
	
	return 0;
}