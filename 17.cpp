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
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
 int checker(int arr[3][3], int target)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == target)
                return true;
                    
        }
    }
    return false;
}
void findtarget(int arr[3][3], int target)
{
    if (checker(arr, target))
        cout << "\nYes : The number is there";
    else
        cout << "\nNo : The number is NOT found";
}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int target;
    int scalar[3][3] = { {7,0,0,}, {0,7,0}, {0,0,7} };
    int arr[3][3];

    cout << "\nThe following are random 3x3 matrix \n";
    generatearray(arr);
    printarray(arr);

    cout << "\nenter target number : ";
    cin >> target;
    findtarget(arr, target);
    return 0;
}