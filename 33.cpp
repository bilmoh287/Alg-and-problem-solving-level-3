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

bool IsVowel(char Ch1)
{
	Ch1 = tolower(Ch1);
	return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
}
int counter(string s)
{
	int counter = 0;
	for (char& c : s)
	{
		if(IsVowel(c))
			counter++;
	}
	return counter;
}
int main()
{
	string s = takestring();

	cout << "\nNumber of Vowels are " << counter(s);
	return 0;
}