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
            arr[i][j] = RandomNumber(0, 9);
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
int sumoftarget(int arr[3][3], int target)
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
                if (arr[i][j] == target)
                    sum++;
        }
    }
    return sum;
}
void findtargetnumber(int arr[3][3], int target)
{
    cout << "\nThe numbber " << target << " is repeated " << sumoftarget(arr, target) << " times\n";
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

    cout << "\nTenter number u want to count : ";
    cin >> target;

    findtargetnumber(arr, target);
    return 0;
}