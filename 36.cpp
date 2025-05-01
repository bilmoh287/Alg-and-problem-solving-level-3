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

int words(string s)
{
	int counter = 0;
	string delim = " ";
	int pos = 0;
	string sword;
	while ((pos = s.find(delim)) != std::string::npos)
	{
		sword = s.substr(0, pos);
		if (sword != "")
		{
			counter++;
		}
		s.erase(0, pos + delim.length());
	}
	if (s != "")
	{
		counter++;
	}
	return counter;
}
void print(string s)
{

}
int main()
{
	string s = takestring();
	cout<< "Number of word in string : " << words(s);
	
	return 0;
}