//将某个大于1的自然数n分解为其素因子的乘积，如6=2*3，7=7，8=2*2*2
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
	int m;
	int p[10]; int s = 0;
	cout << "please enter the number:";
	cin >> m ;
	for (int i = 2; i < m/2; )
	{
		bool flag = true;
		while (flag)
		{
			flag = false;

			if (m%i == 0)
			{
				p[s++] = i;
				m = m / i;
				cout << "m的值" << m << " ";
				if (m / i == 0)
					flag = true;
			
			}
		}
		
		cout << "calm down, girl" << endl;
		if (i == 2)
			i = i + 1;
		else
		{
			i = i + 2;
		}
		cout << "s的值：" << s << endl;

	}
	p[s++] = m;
	for (int j = 0; j < s; j++)
	{
		cout << p[j] <<" "<< endl;
	}
	system("pause");
	return 0;


}