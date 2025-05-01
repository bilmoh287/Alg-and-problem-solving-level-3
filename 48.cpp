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

void printclient(etClientdata client)
{
	cout << "| " << left << setw(15) << client.ANumber;
	cout << "| " << left << setw(10) << client.Pincode;
	cout << "| " << left << setw(40) << client.Name;
	cout << "| " << left << setw(12) << client.phone;
	cout << "| " << left << setw(12) << client.Accbalance;

}
void printallclientdatadata(vector<etClientdata> vclientdata)
{
	cout << "\n\t\t\t\tClient List (" << vclientdata.size() << ") Client(s)." << endl;
	cout << "_____________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout <<"\n_______________________________________________________";
	cout << "________________________________________\n" << endl;

	for (etClientdata client : vclientdata)
	{
		printclient(client);
		cout << endl;
	}

}
int main()
{
	vector<etClientdata> vclientdata = takedatafromfile();
	printallclientdatadata(vclientdata);

	return 0;
}