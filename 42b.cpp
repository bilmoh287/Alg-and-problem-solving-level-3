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


string replaceword(string s, string tobereplaced, string replaceto)
{
	short pos = s.find(tobereplaced);  // Find the first occurrence of "tobereplaced"

	while (pos != std::string::npos)   // Loop while the word is found in the string
	{
		s = s.replace(pos, tobereplaced.length(), replaceto);  // Replace it with "replaceto"
		pos = s.find(tobereplaced);    // Find the next occurrence of "tobereplaced"
	}
	return s;  // Return the modified string
}


int main()
{
	string s = "welcome to Jordan , Jordan is a nice country";
	string replacableto = "USA";
	string tobereplaced = "Jordan";
	cout << s << endl;

	cout << "\nstring after replace : \n";
	cout << replaceword(s, tobereplaced, replacableto);
	return 0;
}