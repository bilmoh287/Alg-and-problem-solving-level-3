#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
const string ClientsFileName = "Clients.txt";

struct etClientdata
{
	string ANumber;
	string Name;
	string phone;
	string Pincode;
	double Accbalance;
	bool markaccount = false;
};
etClientdata takeclientdata(string accnumber)
{
	etClientdata clientdata;
	cout << "\nPlease Enter Client Data \n";

	clientdata.ANumber = accnumber;

	cout << "Enter PinCode ? ";
	cin >> clientdata.Pincode;
	cin.ignore();

	cout << "Enter Name ? ";
	getline(cin, clientdata.Name);

	cout << "Enter Phone ? ";
	getline(cin, clientdata.phone);

	cout << "Enter Account Balance ? ";
	cin >> clientdata.Accbalance;

	return clientdata;

}
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

string convertrecordtoline(etClientdata client, string delim = "#//#")
{
	string line = "";
	line += client.ANumber + delim;
	line += client.Pincode + delim;
	line += client.Name + delim;
	line += client.phone + delim;
	line += to_string(client.Accbalance);

	return line;
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
	cout << "\nThis are the forllowing client data ";
	cout << "\n\nAccount Numer  : " << client.ANumber;
	cout << "\nPINcode        : " << client.Pincode;
	cout << "\nName           : " << client.Name;
	cout << "\nPhone          : " << client.phone;
	cout << "\nAccount Balance: " << client.Accbalance;
}

string takeaccnumber()
{
	string str = "";
	cout << "pleas enter account number? ";
	cin >> str;
	return str;
}
bool flindclientbyaccnumber(string accnumber, vector<etClientdata> vclientdata, etClientdata& client)
{
	for (etClientdata c : vclientdata)
	{
		if (c.ANumber == accnumber)
		{
			client = c;
			return true;
		}
	}
	return false;
}

//bool MarkClientForDeleteByAccount(string accnumber, vector<etClientdata>& vclientdata)
//{
//	for (etClientdata& c : vclientdata)
//	{
//		if (c.ANumber == accnumber)
//		{
//			c.markaccount = true;
//			return true;
//		}
//	}
//	return false;
//}

void SaveClientDataToFile(string filename, vector<etClientdata> vclientdata)
{
	fstream MyFile;
	MyFile.open(filename, ios::out);

	string line;
	if (MyFile.is_open())
	{
		for (etClientdata c : vclientdata)
		{
			if (!c.markaccount)
			{
				line = convertrecordtoline(c);
				MyFile << line << endl;
			}
		}
	}
	MyFile.close();
}

 /*void UpdateClientByAccountNumber(vector<etClientdata> &vclientdata)
{
	etClientdata updatedclientdata;
	for (etClientdata& c : vclientdata)
	{
		if (c.markaccount)
		{
			updatedclientdata = takeclientdata(c);
			c = updatedclientdata;
		}
	}
}*/
bool UpdateDataByAccountNumber(string accnumber, vector<etClientdata>& vclientdata)
{
	etClientdata client;
	char ans = 'n';

	if (flindclientbyaccnumber(accnumber, vclientdata, client))
	{
		printdata(client);
		cout << "\n\nAre you sure you want to delete this acccount Y/N? ";
		cin >> ans;

		if (ans == 'Y' || ans == 'y')
		{
			for (etClientdata& c : vclientdata)
				//MarkClientForDeleteByAccount(accnumber, vclientdata);
				if (c.ANumber == accnumber)
				{
					c = takeclientdata(accnumber);
					break;
				}
			//UpdateClientByAccountNumber(vclientdata);
			SaveClientDataToFile(ClientsFileName, vclientdata);

			cout << "\n\nClient Data updated successfully";
			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << accnumber << ") is Not Found!";
		return false;
	}
}
int main()
{
	vector<etClientdata> vclientdata = takedatafromfile();
	string accnumber = takeaccnumber();

	UpdateDataByAccountNumber(accnumber, vclientdata);
	return 0;
}