#include <iostream>
#include <iomanip>

using namespace std;
#include "arrmanip.h"

void PrintIntegers(int k[], unsigned int n)
{
	unsigned int i;
	for (i = 0; i < n; i++)
		cout << setw(3) << k[i];
	cout << endl;
}

int CompareInteger(int x, int y)
{
	if (x>y)
		return 1;
	else if (x == y)
		return 0;
	else
		return -1;
}