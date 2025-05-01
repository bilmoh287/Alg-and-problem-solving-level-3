#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
string takestring()
{
	string s;
	cout << "enter your string? \n";
	getline(cin, s);
	return s;
}
char takechar()
{
	char c;
	cout << "\nenter a character? \n";
	cin >> c;
	return c;
}
char invertchar(char s)
{
	return isupper(s) ? (char)tolower(s) : (char)toupper(s);
}
int counter(string s, char c, bool matchcase = true)
{
	int counter = 0;
	for (char &letter : s)
	{
		if (matchcase)
		{
			if(c == letter)
				counter++;
		}
		else
		{
			if (tolower(c) == tolower(letter))
				counter++;
		}
	}
	return counter;
}

int main()
{
	string s = takestring();
	char c = takechar();


	cout << "\nletter '" << c << "' count = " << counter(s, c) << endl;
	cout << "\nletter '" << c << "' or '" << invertchar(c) <<  "' count = "  << counter(s, c, false) << endl;


	return 0;
}