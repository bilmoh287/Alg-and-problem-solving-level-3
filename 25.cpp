#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
string takestring()
{
	string s;
	cout << "enter ur string? \n";
	getline(cin, s);
	return s;
}
string lowerfirstletters(string s)
{
	bool isFirst = true;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ' && isFirst) 
		{
			s[i] = tolower(s[i]);
		}
		isFirst = (s[i] == ' ' ? true : false);
	}
	return s;
}
void printstring(string s)
{
	cout << "\nFirst letter of the string : \n";
	cout << s;
}
int main()
{
	printstring(lowerfirstletters(takestring()));

	system("pause>0");
}