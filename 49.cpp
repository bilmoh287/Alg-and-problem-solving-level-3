#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
struct etClientdata
{
	string ANumber;
	string Name;
	string phone;
	string Pincode;
	double Accbalance;
};
vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord; // define a string variable
	// use find() function to get the position of the delimiters
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.
	}
	return vString;
}

etClientdata ConvertLineToRecord(string line, string delim = "#//#")
{
	etClientdata client;
	vector<string> vclientdata;

	vclientdata = SplitString(line, delim);

	client.ANumber = vclientdata[0];
	client.Pincode = vclientdata[1];
	client.Name = vclientdata[2];
	client.phone = vclientdata[3];
	client.Accbalance = stod(vclientdata[4]);

	return client;
}

vector<etClientdata> takedatafromfile(string filename = "clients.txt")
{
	vector<etClientdata> vclientdata;
	fstream MyFile;
	MyFile.open(filename, ios::in);
	if (MyFile.is_open())
	{
		etClientdata client;
		string line;
		while (getline(MyFile, line))
		{
			client = ConvertLineToRecord(line);
			vclientdata.push_back(client);
			
		}
	}
	return vclientdata;
}
void printdata(etClientdata client)
{
	cout << "\n Account Numer  : " << client.ANumber;
	cout << "\n PINcode        : " << client.Pincode;
	cout << "\n Name           : " << client.Name;
	cout << "\n Phone          : " << client.phone;
	cout << "\n Account Balance: " << client.Accbalance;
}

string takeaccnumber()
{
	string str = "";
	cout << "pleas enter account number? ";
	cin >> str;
	return str;
}
bool checkaccnumber(vector<etClientdata> vclientdata, string accnumber)
{
	for (etClientdata client : vclientdata)
	{
		if (client.ANumber == accnumber)
		{
			return true;
		}
	}
	return false;
}
void printclientdata(vector<etClientdata> vclientdata, string accnumber)
{
	if (checkaccnumber(vclientdata, accnumber))
	{
		for (etClientdata client : vclientdata)
		{
			if(client.ANumber == accnumber)
				printdata(client);
		}
	}
	else
	{
		cout << "\nAccount doest not exist\n";
	}
}
int main()
{
	vector<etClientdata> vclientdata = takedatafromfile();
	string str = takeaccnumber();
	printclientdata(vclientdata, str);
	return 0;
}