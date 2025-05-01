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
            arr[i][j] = RandomNumber(0, 10);
        }
    }
}

void printarray(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout <<  setw(3) << arr[i][j];
        }
        cout << endl;
    }
}
 bool isnumberinmatrix(int number, int arr2[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (number == arr2[i][j])
                return true;
        }
    }
    return false;
}
 void Checker(int arr[3][3], int arr2[3][3])
 {
     for (int i = 0; i < 3; i++)
     {
         for (int j = 0; j < 3; j++)
         {
             if (isnumberinmatrix(arr[i][j], arr2))
             {
                 cout << arr[i][j] << " ";
             }
         }
     }
 }
 
//void findtarget(int arr[3][3], int target)
//{
//    if (checker(arr, target))
//        cout << "\nYes : The number is there";
//    else
//        cout << "\nNo : The number is NOT found";
//}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int target;
    int scalar[3][3] = { {7,0,0,}, {0,7,0}, {0,0,7} };
    int arr[3][3], arr2[3][3];

    cout << "\nMatrix1 \n";
    generatearray(arr);
    printarray(arr);

    cout << "\nMatrix2 \n";
    generatearray(arr2);
    printarray(arr2);

    cout << "The repeated numbers are : ";
    Checker(arr, arr2);
    return 0;
}