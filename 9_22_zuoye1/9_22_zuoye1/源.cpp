#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int n, m;
	cout << "the row numbers" << endl;
	cin >> n;
	cout << "the space width" << endl;
	cin >> m;
	for (int i = 0; i <n ; i++)
	{
		cout << setw(n - i);
		for (int j = 1; j <= (2 * i + 1); j++)
		{
			cout << "*";
		}
		cout << setw(m);
		for (int b = 2 * (n - i); b>1; b--)
		{
			cout << "*";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}