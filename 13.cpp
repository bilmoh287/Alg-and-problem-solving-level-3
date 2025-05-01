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
            printf("%0*d ", 2, arr[i][j]);
        }
        cout << endl;
    }
}
bool identitychecker(int arr[3][3], int identity[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] != identity[i][j])
                return false;
        }
    }
    return true;
}
void printres(int arr[3][3], int identity[3][3]) 
{
    if (identitychecker(arr, identity))
        cout << "Yes : it is identity matrix\n";
    else
        cout << "No : it is NOT identity matrix";
}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int identityarr[3][3] = { {1,0,0,}, {0,1,0}, {0,0,1} };
    int arr[3][3];
    cout << "The following are random 3x3 matrix \n";
    generatearray(arr);
    printarray(arr);
    printres(arr, identityarr);
    return 0;
}