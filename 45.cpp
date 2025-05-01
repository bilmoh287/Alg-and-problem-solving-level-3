#include <string>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;
struct etClientdata
{
	string ANumber;
	string Name;
	string phone;
	int Pincode;
	float Accbalance;
};
void takeclientdata(vector<etClientdata> &vclientdata)
{
	etClientdata clientdata;
	cout << "Please Enter Client Data \n";

	cout << "\nEnter Account Numer : ";
	cin >> clientdata.ANumber;

	cout << "\nEnter PinCode ? ";
	cin >> clientdata.Pincode;
	cin.ignore();

	cout << "\nEnter Name ? ";
	getline(cin, clientdata.Name);

	cout << "\nEnter Phone ? ";
	getline(cin, clientdata.phone);

	cout << "\nEnter Account Balance ? ";
	cin >> clientdata.Accbalance;

	vclientdata.push_back(clientdata);
}
string clientDataToString(etClientdata client, string delim)
{
	stringstream ss;
	ss << client.ANumber << delim
		<< client.Name << delim
		<< client.phone << delim
		<< client.Pincode << delim
		<< client.Accbalance;
	return ss.str();
}

string printline(vector<etClientdata> vclientdata, string delim)
{
	string line = "";
	for (int i = 0; i < vclientdata.size(); i++)
	{
		line += clientDataToString(vclientdata[i], delim) ;
	}
	return line;
}

int main()
{
	vector<etClientdata> vclintdata{};
	string delim = "#//#";
	takeclientdata(vclintdata);

	cout << "\n\nCinet data for saving is : ";
	cout << "\n" << printline(vclintdata, delim);

	return 0;

}