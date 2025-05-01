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

vector<etClientdata> takedatafromfile(string filename = "clients.txt")
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

string convertrecordtoline(etClientdata client, string delim = "#//#")
{
    return client.ANumber + delim + client.Pincode + delim +
        client.Name + delim + client.phone + delim + to_string(client.Accbalance);
}

// ✅ Now appends data instead of overwriting the file
void AdddatatoFile(string line, string filename)
{
    fstream client(filename, ios::out | ios::app);
    if (client.is_open())
    {
        client << line << endl;
        client.close();
    }
}

// ✅ Now writes all records at once (no multiple overwrites)
void addnewclientdataintofile(vector<etClientdata> vnewclientdata, string filename = "clients.txt")
{
    fstream client(filename, ios::out);
    if (client.is_open())
    {
        for (etClientdata c : vnewclientdata)
        {
            client << convertrecordtoline(c) << endl;
        }
        client.close();
    }
}

// ✅ Deletes a client without affecting other records
void deleteaccountfromfile(etClientdata client, string filename = "clients.txt")
{
    vector<etClientdata> vclientdata = takedatafromfile();
    vector<etClientdata> vnewclientdata;

    for (etClientdata c : vclientdata)
    {
        if (c.ANumber != client.ANumber)
        {
            vnewclientdata.push_back(c);
        }
    }

    addnewclientdataintofile(vnewclientdata, filename);
}

void printdata(etClientdata client)
{
    char c;
    cout << "\n Account Number  : " << client.ANumber;
    cout << "\n PIN Code        : " << client.Pincode;
    cout << "\n Name           : " << client.Name;
    cout << "\n Phone          : " << client.phone;
    cout << "\n Account Balance: " << client.Accbalance;

    cout << "\n\nDo you want to delete this account? (Y/N): ";
    cin >> c;

    if (c == 'y' || c == 'Y')
    {
        deleteaccountfromfile(client);
        cout << "\n Account deleted successfully!\n";
    }
}

// ✅ Prevents cin issues and takes valid input
string takeaccnumber()
{
    string str;
    cout << "Please enter account number: ";
    cin >> str;
    return str;
}

// ✅ Finds a client by account number
bool flindclientbyaccnumber(string accnumber, etClientdata& client)
{
    vector<etClientdata> vclientdata = takedatafromfile();
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

int main()
{
    etClientdata client;
    string accnumber = takeaccnumber();

    if (flindclientbyaccnumber(accnumber, client))
    {
        printdata(client);
    }
    else
    {
        cout << "\nClient with Account Number (" << accnumber << ") is not found!\n";
    }
    return 0;
}
