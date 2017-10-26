//编写函数Sort,对包含n个元素的整数数组a，按从小到大的顺序排序
#include <iostream>

using namespace std;

void Sort(int a[], unsigned int n);

int main()
{
	int num = 6;
	int b[6];
	for (int i = 0; i < 6; i++)
	{
		cin >> b[i];
	}
	Sort(b, 6);
	for (int i = 0; i < 6; i++)
	{
		cout << b[i] << endl;;
	}
	system("pause");
	return 0;
}

//void Sort(int a[],unsigned int n)
//{
//	for (int j = 0; j < int(n / 2); j++)
//	{
//		int t;
//		t = a[j];
//		a[j] = a[n - j - 1];
//		a[n - j - 1] = t;
//	}
//
//}
void Sort(int a[], unsigned int n)
{
	for (int j = 0; j < n; j++)
	{
		for (int m = j + 1; m < n; m++)
		{
			if (a[j]>a[m])
			{
				int t = a[j];
				a[j] = a[m];
				a[m] = t;
			}

		}
		
	}

}