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
            arr[i][j] = RandomNumber(0,10);
        }
    }
}
void middlerow(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
       cout << setw(2) << setfill('0') << arr[1][i] << " ";
    cout << endl;
}
void middlcol(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
        cout << setw(2) << setfill('0') << arr[i][1] << " ";
}

void printarray(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%0*d ", 2, arr[i][j]);
        }
        cout << endl;
    }
}
int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int arr[3][3];
    cout << "The following are random 3x3 matrix \n";
    generatearray(arr);
    printarray(arr);
    cout << "middle row of the matrix \n";
    middlerow(arr);
    cout << "middle col of the matrix \n";
    middlcol(arr);

    return 0;
}