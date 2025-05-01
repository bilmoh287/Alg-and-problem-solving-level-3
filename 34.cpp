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

bool IsVowel(char Ch1)
{
	Ch1 = tolower(Ch1);
	return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
}

void printvowels(string s)
{
	cout << "\nVowels in string are : ";

	for (int i = 0; i < s.length(); i++)
	{
		if(IsVowel(s[i]))
			cout << s[i] << " ";
	}
}
int main()
{
	string s = takestring();
	printvowels(s);
	
	return 0;
}