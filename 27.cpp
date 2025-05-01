#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
char takestring()
{
	char s;
	cout << "enter ur Char? \n";
	cin >> s;
	return s;
}
char invertchar(char s)
{
	return isupper(s) ? (char)tolower(s) : (char)toupper(s);
}

void printstring(string s)
{
	cout << s;
}
int main()
{
	char s = takestring();
	s = invertchar(s);
	cout << "\after inverting : \n";
	cout << s;

	return 0;
}