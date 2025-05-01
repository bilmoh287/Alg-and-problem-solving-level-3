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
bool matchingmatrix(int arr[3][3], int arr2[3][3])
{
    bool n = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] != arr2[i][j]) {
                n = 0;
                return n;
            }
        }
    }
    return n;
}
void equalitychecker(int arr1[3][3], int arr2[3][3])
{
    cout << endl;
    if (matchingmatrix(arr1,arr2))
        cout << "They are Equal\n";
    else
        cout << "The are NOT Equal";
}
int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int arr[3][3], arr2[3][3];
    cout << "Matrix1\n";
    generatearray(arr);
    printarray(arr);
    cout << "Matrix1\n";
    generatearray(arr2);
    printarray(arr2);
    equalitychecker(arr, arr2);

    return 0;
}