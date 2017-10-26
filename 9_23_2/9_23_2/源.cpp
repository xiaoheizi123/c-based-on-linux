//添加函数gcd与lcm。分别求两个正整数的最大公约数与最小公倍数
#include <iostream>

using namespace std;

int gcd(int a,int b);
//int lcm(int a, int b);

int main()
{
	int c, v;
	cin >> c >> v;
	int d = gcd(c, v);
	cout << d << endl;
	system("pause");
	return 0;

}

//求最大公约数
int gcd(int a, int b)
{
	int w[10]; int s = 0;
	int m[20]; int p = 0; int q = 0;
	int  n[20];
	for (int i = 2; i <= a; i++)
	{
		if (a%i == 0)
		{m[p++] = i;
		//cout << m[p] << endl;
	}
	for (int j = 2; j <= b; j++)
	{
		if (b%j == 0)
			n[q++] = j;
	}
	for (int j = 0; j<(p>q ? p : q); j++)
	{
		for (int i= 0; i<(p>q ? q :p); i++)
		{
			if (n[i] == m[j])
			{
				w[s++] = m[j];
				cout << w[s++] << " ";
			}	
		}

		
	}
	int sum = 1;
	for (int i = 0; i < s; i++)
	{
		sum = sum*w[i];
	}
	return sum;
}