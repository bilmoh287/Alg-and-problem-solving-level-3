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
void AdddatatoFile(string line, string filename)
{
	fstream client;
	client.open(filename, ios::out | ios::app);
	if (client.is_open())
	{
		client << line << endl;
	}
	client.close();
}
void AddNewClient()
{
	etClientdata client;
	client = takeclientdata();

	AdddatatoFile(convertrecordtoline(client), "Clients.txt");
}
void AddClient()
{
	char AddMore = 'Y';
	do
	{
		system("cls");
		cout << "Adding New Client:\n\n";
		AddNewClient();
		cout << "\nClient Added Successfully, do you want to add more clients ? Y / N ? ";
		cin >> AddMore;
	} while (toupper(AddMore) == 'Y');
}
int main()
{
	AddClient();	
	return 0;
}