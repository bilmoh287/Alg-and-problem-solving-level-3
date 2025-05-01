#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int RandomNumber(int From, int To)
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
void generatearray(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = RandomNumber(0, 100);
        }
    }
}

void printarray(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout <<  setw(3) << arr[i][j] << "  ";
        }
        cout << endl;
    }
}
bool checker(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (arr[i][0] != arr[i][2])
            return false;
    }
    return true;
}
void checkpalindrom(int arr[3][3])
{
    if (checker(arr))
        cout << "\n Matrix is Palindrom\n";
    else
        cout << "\nMatrix is NOT Palindrom\n";
}
 

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int target;
    int palindrom[3][3] = { {0,0,0,}, {0,7,0}, {7,0,7} };
    int arr[3][3];


    cout << "\nMatrix1 \n";
    generatearray(arr);
    printarray(palindrom);

    checkpalindrom(palindrom);

    return 0;
}