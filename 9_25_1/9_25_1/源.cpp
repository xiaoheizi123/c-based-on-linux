//��ĳ������1����Ȼ��n�ֽ�Ϊ�������ӵĳ˻�����6=2*3��7=7��8=2*2*2
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
				cout << "m��ֵ" << m << " ";
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
		cout << "s��ֵ��" << s << endl;

	}
	p[s++] = m;
	for (int j = 0; j < s; j++)
	{
		cout << p[j] <<" "<< endl;
	}
	system("pause");
	return 0;


}