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
string firstletters(string s)
{
	string res = "";
	res += s[0];
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ') 
		{
			res += (s[i + 1]);
		}
	}
	return res;
}
void printstring(string s)
{
	cout << "\nFirst letter of the string : \n";
	for (int i = 0; i < s.length(); i++)
	{
		cout << s[i] << endl;
	}
}
int main()
{
	printstring(firstletters(takestring()));

	system("pause>0");
}

// #include <iostream>
// #include <string>
// #include <iomanip>
// using namespace std;
// string takestring()
// {
// 	string s;
// 	cout << "enter ur string? \n";
// 	getline(cin, s);
// 	return s;
// }
// string firstletters(string s)
// {
// 	bool isFirst = true;
// 	string res = "";
// 	for (int i = 0; i < s.length(); i++)
// 	{
// 		if (s[i] != ' ' && isFirst) 
// 		{
// 			res += (s[i]);
// 		}
// 		isFirst = (s[i] == ' ' ? true : false);
// 	}
// 	return res;
// }
// void printstring(string s)
// {
// 	cout << "\nFirst letter of the string : \n";
// 	for (int i = 0; i < s.length(); i++)
// 	{
// 		cout << s[i] << endl;
// 	}
// }
// int main()
// {
// 	printstring(firstletters(takestring()));

// 	system("pause>0");
// }