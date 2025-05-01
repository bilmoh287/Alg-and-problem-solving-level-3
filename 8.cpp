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
void profuctofarrays(int arr1[3][3], int arr2[3][3], int product[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            product[i][j] = arr1[i][j] * arr2[i][j];
        }
        cout << endl;
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
int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int arr[3][3], arr2[3][3], productarr3[3][3];
    cout << "Matrix1 \n";
    generatearray(arr);
    printarray(arr);
    cout << "Matrix2 \n";
    generatearray(arr2);
    printarray(arr2);
    cout << "Product Result\n";
    profuctofarrays(arr, arr2, productarr3);
    printarray(productarr3);

    return 0;
}