#include <iostream>
using namespace std;
void PrintFibonacciUsingrecursion(short Number, int Prev2, int Prev1)
{
	int FebNumber = 0;
	if (Number > 0) {

		FebNumber = Prev1 + Prev2;
		cout << FebNumber << " ";
		Prev2 = Prev1;
		Prev1 = FebNumber;
		PrintFibonacciUsingrecursion(Number-1, Prev2, Prev1);

	}
}
int main()
{
	PrintFibonacciUsingrecursion(10,0,1);
	system("pause>0");
}