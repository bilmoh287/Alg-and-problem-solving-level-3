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
	string str = "";
	cout << "\nYOur string words are : \n\n";

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ')
		{
			str += s[i];
		}

		if ((s[i] == ' ' && !str.empty()) || (i == s.length() - 1 && !str.empty()))
		{
			cout<< str << endl;
			str = "";
		}

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