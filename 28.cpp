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
char invertchar(char s)
{
	return isupper(s) ? (char)tolower(s) : (char)toupper(s);
}
string inverstring(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		s[i] = invertchar(s[i]);
	}
	return s;
}

int main()
{
	string s = takestring();
	s = inverstring(s);
	cout << "\nafter inverting : \n";
	cout << s;

	return 0;
}