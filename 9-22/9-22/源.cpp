#include <iostream>
#include <iomanip>

using namespace std;

typedef enum {monday,tuesday,wednesday,thursday,friday,saturday,sunday}weekday;

int main()
{ 
	int date;
	const weekday data_1 = friday;
	weekday week_day;
	cout << " please enter a num between 1~31" << endl;
	cin >> date;
	if (date<1 && date>31)
	{
		cout << "error" << endl;
		return 1;
	}
	else
		week_day = (weekday)((date - 1 + (int)data_1)%7);  //(weekday)这里是进行类型转换

	cout << week_day << endl;
	system("pause");
	return 0;

}