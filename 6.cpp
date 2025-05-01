#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int from_1_to_10()
{
    static int i = 0;
    i++;
    return i;
}
void generatearray(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = from_1_to_10();
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
int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int arr[3][3];
    generatearray(arr);
    cout << "The following are a 3x3 randdom matrix \n";
    printarray(arr);

    return 0;
}