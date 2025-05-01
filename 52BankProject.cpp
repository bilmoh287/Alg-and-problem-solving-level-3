#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
const string ClientsFileName = "clients.txt";
struct etClientdata
{
	string ANumber;
	string Name;
	string phone;
	string Pincode;
	double Accbalance;
	bool markaccount = false;
};
enum etchoosetask { show = 1, Add = 2, Delete = 3, Update = 4, Find = 5, Transaction = 6};
enum etchoosetransactiontask {deposit = 1, withdraw = 2, showbalances = 3};
int Menu()
{
	system("cls");
	int n = 0;
	cout << "=====================================================";
	cout << "\n\t\tMain Menu Screen\n";
	cout << "=====================================================";

	cout << "\n\t[1] Show Cleints List.";
	cout << "\n\t[2] Add New Client.";
	cout << "\n\t[3] Delete Cleint.";
	cout << "\n\t[4] Update Client Info.";
	cout << "\n\t[5] Find Client.";
	cout << "\n\t[6] Transaction.";
	cout << "\n\t[7] Exit.";
	cout << "\n=====================================================";

	cout << "\nChoose what you want to do? [1 to 6]? ";
	cin >> n;
	return n;
}
vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord;

	while ((pos = S1.find(Delim)) != string::npos)
	{
		sWord = S1.substr(0, pos);
		if (!sWord.empty())
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (!S1.empty())
	{
		vString.push_back(S1);
	}
	return vString;
}
etClientdata ConvertLineToRecord(string line, string delim = "#//#")
{
	etClientdata client;
	vector<string> vclientdata = SplitString(line, delim);

	if (vclientdata.size() >= 5)
	{
		client.ANumber = vclientdata[0];
		client.Pincode = vclientdata[1];
		client.Name = vclientdata[2];
		client.phone = vclientdata[3];
		client.Accbalance = stod(vclientdata[4]);
	}
	return client;
}
vector<etClientdata> LoadClientsDataFromFile(string filename = "clients.txt")
{
	vector<etClientdata> vclientdata;
	fstream MyFile(filename, ios::in);
	if (MyFile.is_open())
	{
		string line;
		while (getline(MyFile, line))
		{
			etClientdata client = ConvertLineToRecord(line);
			vclientdata.push_back(client);
		}
		MyFile.close();
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
void printclient(etClientdata client)
{
	cout << "| " << left << setw(15) << client.ANumber;
	cout << "| " << left << setw(10) << client.Pincode;
	cout << "| " << left << setw(30) << client.Name;
	cout << "| " << left << setw(12) << client.phone;
	cout << "| " << left << setw(12) << client.Accbalance;
}
void PrintClientCard(etClientdata client)
{
	cout << "---------------------------------------------------";
	cout << "\n Account Number : " << client.ANumber;
	cout << "\n PIN Code       : " << client.Pincode;
	cout << "\n Name           : " << client.Name;
	cout << "\n Phone          : " << client.phone;
	cout << "\n Account Balance: " << client.Accbalance;
	cout << "\n---------------------------------------------------\n";

}
void ShowList()
{
	vector<etClientdata> vclientdata = LoadClientsDataFromFile();
	cout << "\n\t\t\tCleint List (" << vclientdata.size() << ") Clinet(s)" << endl;
	cout << "_____________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(30) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Account Balance";
	cout << "\n_____________________________________________________";
	cout << "_________________________________________\n" << endl;

	for (etClientdata client : vclientdata)
	{
		printclient(client);
		cout << endl;
	}
	cout << "\n\n_____________________________________________________";
	cout << "_________________________________________" << endl;
	cout << "\n\nPrint any ket to return to Menu....";
	system("pause>0");
}
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
bool FindClientByAccountNumber(string accnumber, vector<etClientdata> vclientdata, etClientdata& client)
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
string ConvertRecordToLine(etClientdata client, string delim = "#//#")
{
	string line = "";
	line += client.ANumber + delim;
	line += client.Pincode + delim;
	line += client.Name + delim;
	line += client.phone + delim;
	line += to_string(client.Accbalance);

	return line;
}
void SaveClientsDataToFile (string filename, vector<etClientdata> vclientdata)
{
	fstream MyFile;
	MyFile.open(filename, ios::out);
	if (MyFile.is_open())
	{
		string line;
		for (etClientdata c : vclientdata)
		{
			if (!c.markaccount)
			{
				line = ConvertRecordToLine(c);
				MyFile << line << endl;
			}
		}
	}
	MyFile.close();
}
bool AccountExists(string accnumber, vector<etClientdata>& vclientdata)
{
	for (const etClientdata& c : vclientdata)
	{
		if (c.ANumber == accnumber)
		{
			return true; // Account exists
		}
	}
	return false;
}
void AddClientData()
{
	vector<etClientdata> vclientdata = LoadClientsDataFromFile();
	etClientdata client;
	string accnumber;
	char ans = 'y';

	do
	{
		system("cls");

		cout << "=====================================================";
		cout << "\n\t\tAdd New Client\n";
		cout << "=====================================================";

		do
		{
			cout << "\nEnter Account Number ? ";
			cin >> accnumber;

			if (AccountExists(accnumber, vclientdata))
			{
				cout << "Client with [" << accnumber << "] already exists! Try another account number.\n";
			}

		} while (AccountExists(accnumber, vclientdata));

		client = takeclientdata(accnumber);
		vclientdata.push_back(client);
		SaveClientsDataToFile(ClientsFileName, vclientdata);

		cout << "Client Added Successfully! Do you want to add more clients? (y/n): ";
		cin >> ans;

	} while (ans == 'y' || ans == 'Y');

	system("pause");
}
bool MarkClientForDeleteByAccountNumber(string accnumber, vector<etClientdata>& vclientdata)
{
	for (etClientdata& c : vclientdata)
	{
		if (c.ANumber == accnumber)
		{
			c.markaccount = true;
			return true;
		}
	}
	return false;
}
bool DeleteClientByAccountNumber(string AccountNumber, vector<etClientdata> &vClients)
{
	etClientdata Client;
	char Answer = 'n';
	if (FindClientByAccountNumber(AccountNumber, vClients,Client))
	{
		PrintClientCard(Client);
		cout << "\n\nAre you sure you want delete this client? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber,
				vClients);
			SaveClientsDataToFile(ClientsFileName, vClients);
			//Refresh Clients
			vClients = LoadClientsDataFromFile(ClientsFileName);
			cout << "\n\nClient Deleted Successfully.";
			system("pause");
			return true;
		}
		else
		{
			cout << "\Delete canceled. Returning to menu...";
			system("pause>0");
			return false;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		cout << "Press any key to return ro menu...";
		system("pause>0");
		return false;
	}
}
string takeaccnumber()
{
	string str;
	cout << "Please enter account number: ";
	cin >> str;
	return str;
}
bool UpdateClientDataByAccountNumber(string accnumber, vector<etClientdata>& vclientdata)
{
	etClientdata client;
	char ans = 'n';

	if (FindClientByAccountNumber(accnumber, vclientdata, client))
	{
		printdata(client);
		cout << "\n\nAre you sure you want to update this acccount Y/N? ";
		cin >> ans;

		if (ans == 'Y' || ans == 'y')
		{
			system("cls");
			for (etClientdata& c : vclientdata)
				//MarkClientForDeleteByAccount(accnumber, vclientdata);
				if (c.ANumber == accnumber)
				{
					c = takeclientdata(accnumber);
					break;
				}
			//UpdateClientByAccountNumber(vclientdata);
			SaveClientsDataToFile(ClientsFileName, vclientdata);

			cout << "\n\nClient Data updated successfully";
			system("pause");
			return true;
		}
		else
		{
			cout << "\nUpdate canceled. Returning to menu...";
			system("pause");
			return false;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << accnumber << ") is Not Found!";
		system("pause");
		return false;
	}
}
void FindClientByAccountNumber2(string accnumber, vector<etClientdata> vclientdata)
{
	for (etClientdata c : vclientdata)
	{
		if (FindClientByAccountNumber(accnumber, vclientdata, c))
		{
			cout << "\nThis are the client details\n";
			PrintClientCard(c);
			cout << "\n\nEnter any key to go back to menu. . .";
			system("pause>0");
			break;
		}
		else
		{
			cout << "\nClient with account [" << accnumber << "] is not found.";
			cout << "\n\nEnter any key to go back to menu. . .";
			system("pause>0");
			break;
		}
	}
}
void DepositByAccountNumber(string accnumber, vector<etClientdata>& vclientdata)
{
	int n = 0, temp = 0;
	char ans;
	etClientdata client;
	while (!FindClientByAccountNumber(accnumber, vclientdata, client))
	{
		cout << " Client with [" << accnumber << "] does not exist.";
		accnumber = takeaccnumber();
	}
	cout << "\n\nThe following are the client details\n";
	PrintClientCard(client);
	cout << "\n\nPlease enter deposit amount? ";
	cin >> n;
	cout << "\n\nAre you sure you want to perform this operation Y/N? ";
	cin >> ans;
	if (ans == 'y' || ans == 'Y')
	{
		for (etClientdata& c : vclientdata)
		{
			if (c.ANumber == accnumber)
			{
				c.Accbalance += n;
				SaveClientsDataToFile(ClientsFileName, vclientdata);
				cout << "\nAccount deposit done succesfully!, New balance is : " << c.Accbalance;
				break;
			}
		}
		cout << "\n\nEnter any key to back to Transaction Menu. . .";
		system("pause>0");
	}
	else
	{
		cout << "\n\nEnter any key to back to Transaction Menu. . .";
		system("pause>0");
	}
}
void WithdrawByAccountNumber(string accnumber, vector<etClientdata>& vclientdata)
{
	int n = 0, temp = 0;
	char ans;
	etClientdata client;
	while (!FindClientByAccountNumber(accnumber, vclientdata, client))
	{
		cout << " Client with [" << accnumber << "] does not exist.";
		accnumber = takeaccnumber();
	}
	cout << "\n\nThe following are the client details\n";
	PrintClientCard(client);
	cout << "\n\nPlease enter withdraw amount? ";
	cin >> n;
	while (n > client.Accbalance)
	{
		cout << "\nAmount Exceeds the balance, you can withdraw up to : " << client.Accbalance << endl;
		cout << "Please enter another amount? ";
		cin >> n;
	}
	cout << "\n\nAre you sure you want to perform this operation Y/N? ";
	cin >> ans;
	if (ans == 'y' || ans == 'Y')
	{
		for (etClientdata& c : vclientdata)
		{
			if (c.ANumber == accnumber)
			{
				c.Accbalance -= n;
				SaveClientsDataToFile(ClientsFileName, vclientdata);
				cout << "\nAccount deposit done succesfully!, New balance is : " << c.Accbalance;
				break;
			}
		}
		cout << "\n\nEnter any key to back to Transaction Menu. . .";
		system("pause>0");
	}
	else
	{
		cout << "\n\nEnter any key to back to Transaction Menu. . .";
		system("pause>0");
	}
}
void printclientbalances(etClientdata client)
{
	cout << "| " << left << setw(15) << client.ANumber;
	cout << "| " << left << setw(30) << client.Name;
	cout << "| " << left << setw(12) << client.Accbalance;
}
void ShowBalances()
{
	int sum = 0;
	vector<etClientdata> vclientdata = LoadClientsDataFromFile();
	cout << "\n\t\t\tCleint List (" << vclientdata.size() << ") Clinet(s)" << endl;
	cout << "_____________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(30) << "Client Name";
	cout << "| " << left << setw(12) << "Account Balance";
	cout << "\n_____________________________________________________";
	cout << "_________________________________________\n" << endl;

	for (etClientdata client : vclientdata)
	{
		printclientbalances(client);
		cout << endl;
		sum += client.Accbalance;
	}
	cout << "\n\n_____________________________________________________";
	cout << "_________________________________________" << endl;
	cout << "\n\t\t\t\t\t\tTotal Balances = ";
	cout << sum;
	cout << "\n\nPrint any ket to return to Menu....";
	system("pause>0");
}
void DeleteClient()
{
	string accnumber = takeaccnumber();
	vector<etClientdata> vclientdata = LoadClientsDataFromFile();
	DeleteClientByAccountNumber(accnumber, vclientdata);
}
void UpdateHeader()
{
	cout << "=====================================================";
	cout << "\n\t\tUpdate Client Data\n";
	cout << "=====================================================\n";
	string accnumber = takeaccnumber();
	vector<etClientdata> vclientdata = LoadClientsDataFromFile();
	UpdateClientDataByAccountNumber(accnumber, vclientdata);
}
void FindClient()
{
	cout << "=====================================================";
	cout << "\n\t\Find Client Scree\n";
	cout << "=====================================================\n";
	string accnumber = takeaccnumber();
	vector<etClientdata> vclientdata = LoadClientsDataFromFile();
	FindClientByAccountNumber2(accnumber, vclientdata);
}
int TransactionMenu()
{
	system("cls");
	int n = 0;
	cout << "=====================================================";
	cout << "\n\t\tTransaction Menu Screen\n";
	cout << "=====================================================";

	cout << "\n\t[1] Deposit.";
	cout << "\n\t[2] Withdraw.";
	cout << "\n\t[3] Total Balances.";
	cout << "\n\t[4] Main Menu.";

	cout << "\n=====================================================";

	cout << "\nChoose what you want to do? [1 to 4]? ";
	cin >> n;
	return n;
}
void exit()
{
	cout << "-----------------------------------------------------";
	cout << "\n\t\Program Ends :- )\n";
	cout << "-----------------------------------------------------";

}
void Deposit()
{
	cout << "\n____________________________________________________\n";
	cout << "\t\tDeposit Screen\n";
	cout << "____________________________________________________\n\n";
	string accnumber = takeaccnumber();
	vector<etClientdata> vclientdata = LoadClientsDataFromFile();
	DepositByAccountNumber(accnumber, vclientdata);

}
void Withdraw()
{
	cout << "\n____________________________________________________\n";
	cout << "\t\tWithdraw Screen\n";
	cout << "____________________________________________________\n\n";
	string accnumber = takeaccnumber();
	vector<etClientdata> vclientdata = LoadClientsDataFromFile();
	WithdrawByAccountNumber(accnumber, vclientdata);
}
void ChooseTask(int n)
{
	etchoosetask choice;
	choice = etchoosetask(n);
	switch ((choice))
	{
	case etchoosetask::show:
		system("cls");
		ShowList();
		break;
	case etchoosetask::Add:
		system("cls");
		AddClientData();
		break;
	case etchoosetask::Delete:
		system("cls");
		DeleteClient();
		break;
	case etchoosetask::Update:
		system("cls");
		UpdateHeader();
		break;
	case etchoosetask::Find:
		system("cls");
		FindClient();
		break;
	case etchoosetask::Transaction:
	{
		system("cls");
		while (true)
		{
			int transactionChoice = TransactionMenu();

			if (transactionChoice == 4) // 
			{
				break; 
			}
			switch (transactionChoice)
			{
			case deposit:
				system("cls");
				Deposit();
				break;
			case withdraw:
				system("cls");
				Withdraw();
				break;
			case showbalances:
				system("cls");
				ShowBalances();
				break;
			default:
				cout << "Invalid choice, please try again.";
				system("pause");
			}
		}
		break; 
	}
	default:
		cout << "Invalid choice, please try again.";
		system("pause");
	}
}
int main()
{
	while (true)
	{
		int n = Menu();
		if (n == 7) // Exit condition
		{
			system("cls");
			exit();
			break;
		}
		ChooseTask(n);
	}
	return 0;
}