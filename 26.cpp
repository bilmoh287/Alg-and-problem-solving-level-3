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
string lowercaseofthestring(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		s[i] = tolower(s[i]);
	}
	return s;
}
string upperacaseofstring(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		s[i] = toupper(s[i]);
	}
	return s;
}
void printstring(string s)
{
	cout << s;
}
int main()
{
	string s = takestring();
	string s1 = upperacaseofstring(s);
	cout << "\nUpper case of the string : \n";
	cout << s1 << endl;

	string s2 = lowercaseofthestring(s);
	cout << "\nLower case of the string : \n";
	cout << s2 << endl;



	system("pause>0");
}