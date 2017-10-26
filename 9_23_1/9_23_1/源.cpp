//编写函数IsPrime，判断某个大于2的正整数是否为素数
#include <iostream>


using namespace std;
int getInteger();
bool IsPrime();


bool main()
{
	
	return  IsPrime();
}
bool IsPrime()
{
	int n =getInteger();
	for (int i = 2; i < n; i++)
	{
		if (n%i == 0)
		{
			return 2==3;
		}
		else
			return 2==2;
	}
}

int getInteger()
{
	int m;
	cout << "please enter en integer to be judged:";
	cin >> m;
	if (m < 2)
	{
		return -1;
	}
	else
		return m;
}