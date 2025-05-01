#include <string>
#include <iostream>
#include <vector>
using namespace std;

void extractdata(string s, vector<string>& vclient, string delim)
{
	int pos = 0;
	string sword;
	while ((pos = s.find(delim)) != std::string::npos)
	{
		sword = s.substr(0, pos);
		if (sword != "")
		{
			vclient.push_back(sword);
		}
		s.erase(0, pos + delim.length());
	}
	if (s != "")
	{
		vclient.push_back(s);
	}
}


void printdata(vector<string> vclient)
{
	cout << "\n Account Numer : " << vclient[0];
	cout << "\n PINcode       : " << vclient[1];
	cout << "\n Name          : " << vclient[2];
	cout << "\n Phone         : " << vclient[3];
	cout << "\nAccount Balance: " << vclient[4];
}

int main()
{
	string line = "A1556#//#2772#//#Bilal Mohammed#//#0917109951#//#50000";
	vector<string> vclient {};
;	string delim = "#//#";

	cout << "Line Record is : \n";
	cout << line;

	extractdata(line, vclient, delim);
	cout << "\n\nRecord after Extraction is : ";
	printdata(vclient);

	return 0;

}