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
	string Pincode;
	double Accbalance;
};
etClientdata takeclientdata()
{
	etClientdata clientdata;
	cout << "Please Enter Client Data \n";

	cout << "\nEnter Account Numer : ";
	cin >> clientdata.ANumber;

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
string convertrecordtoline(etClientdata client, string delim)
{
	string line = "";
	line += client.ANumber + delim;
	line += client.Pincode + delim;
	line += client.Name + delim;
	line += client.phone + delim;
	line += to_string(client.Accbalance);

	return line;
}


int main()
{
	etClientdata client;
	client = takeclientdata();

;	string delim = "#//#";

	cout << "\n\nCinet data for saving is : ";
	cout << "\n" << convertrecordtoline(client, delim);

	return 0;

}