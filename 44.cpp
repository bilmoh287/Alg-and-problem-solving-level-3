#include <string>
#include <iostream>
#include <vector>
using namespace std;

string removepunc(string s)
{
	string s1 = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (!ispunct(s[i]))
		{
			s1 += s[i];
		}
	}
	return s1;
}
int main()
{
	string S1 = "Welco.me to Jordan , Jordan is a ?nice country";
	cout << "\nOriginal String:\n" << S1;

	cout << "\n\nAfter Removing punc: ";
	cout << "\n" << removepunc(S1);

	return 0;

}