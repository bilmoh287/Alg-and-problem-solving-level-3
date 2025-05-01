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

void counter(string s, int &capital, int &small)
{
	for (char &c : s)
	{
		if (isupper(c))
			capital++;
		else if (islower(c))
			small++;
	}
}

int main()
{
	string s = takestring();
	int capital = 0, small = 0;
	 
	counter(s, capital, small);

	cout << "\nString length: " << s.length() << endl;
	cout << "Capital letters: " << capital << endl;
	cout << "Small letters: " << small << endl;

	return 0;
}