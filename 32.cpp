#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

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
bool IsVowel(char Ch1)
{
	Ch1 = tolower(Ch1);
	return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
}
int main()
{
	char c = takechar();


	if(IsVowel(c))
		cout << "YES : Letter " << c << " is a vowel";
	else
		cout << "NO : Letter " << c << " is NOT a vowel";
	return 0;
}