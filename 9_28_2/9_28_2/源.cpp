//返回1~52之间的随机数
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void randomize();
int createIntNumber(int low, int high);

int main()
{
	int res;
	res = createIntNumber(1, 52);
	cout <<"the rand number is:"<< res << endl;
	system("pause");
	return res;


}

void randomize()
{
	srand((int)time(0));
}

int createIntNumber(int low, int high)
{
	if (low > high)
	{
		cout << "the number is wrong";
		exit(1);
	}
	//double d = (double)rand() / ((double)RAND_MAX - 1.0);
	double d = (double)rand() / 100.0;
	cout << "d的值" << (double)rand() << endl;
	cout << "小项的值" << (int)(d*(high - low + 1))<<endl;
	int t = low + (int)(d*(high - low + 1));
	return t;
}