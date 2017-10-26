//�������8��10~99֮�������������stdlib���qsort���������������

#include <iostream>
#include <time.h>
#include <stdlib.h>


#include "arrmanip.h"

//#define NUMBER_OF_ELEMENTS 8


using namespace std;


int DoCompareObject(const void* e1, const void*e2);

void GetRandomNumSeed()
{
	srand(time(0));
}

int GetRandomInteger(int small, int big)
{
	//int j =small+(int)((big-small+1)*( rand() / (RAND_MAX + 1)));
	int j = small + rand() % (big - small + 1);
	return j;

}

int main()
{
	int i, k[8];
	for (i = 0; i < 8; i++)
	{
		k[i] = GetRandomInteger(10, 99);
	}
	cout << "the arr is:";
	PrintIntegers(k, 8);
	qsort(k,8,sizeof(int),DoCompareObject);  //����ָ�������Ϊ��ʽ������
	cout << "the sorted arr is:";
	PrintIntegers(k, 8);
	system("pause");
	return 0;
}

int DoCompareObject(const void* e1, const void*e2)
{
	return CompareInteger(*(const int*)e1, *(const int *)e2);     //�����Ӧ����ʱ�Ĳ�����int x, int y)
}