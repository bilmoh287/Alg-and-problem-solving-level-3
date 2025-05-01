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
int from_1_to_10()
{
    static int i = 0;
    i++;
    return i;
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
int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int arr[3][3];
    generatearray(arr);
    printarray(arr);

    return 0;
}