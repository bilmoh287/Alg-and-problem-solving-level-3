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
int sumofmatrix(int arr[3][3])
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}
int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int arr[3][3];
    cout << "The following are random 3x3 matrix \n";
    generatearray(arr);
    printarray(arr);
    cout << "The sum of the matrix is : ";
    cout << sumofmatrix(arr);

    return 0;
}