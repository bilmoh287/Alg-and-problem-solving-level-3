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
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}
void printarray(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << setw(3) << arr[i][j] << "   ";
        }
        cout << endl;
    }
}
int sumrows(int arr[3][3], int row)
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += arr[row][i];
    }
    return sum;
}
void fillArray(int arr[3][3], int arr2[])
{
    for (int i = 0; i < 3; i++)
    {
        arr2[i] = sumrows(arr, i);
    }
}
void printArray2(int arr2[])
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Row " << i + 1 << " Sum = " << arr2[i] << endl;
    }
}

//void printsum(int arr[3][3])
//{
//    for (int i = 0; i < 3; i++)
//    {
//        cout << "Row " << i + 1 << " Sum = " << sumrows(arr, i) << endl;
//    }
//}
int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int arr[3][3];
    int arr2[3];
    generatearray(arr);
    cout << "The following are a 3x3 randdom matrix \n";
    printarray(arr);
    cout << "The following are the sum of each Row in the matrix \n";
    fillArray(arr, arr2);
    printArray2(arr2);


    return 0;
}