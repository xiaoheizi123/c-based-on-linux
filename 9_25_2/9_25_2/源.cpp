//分别使用循环和递归两种策略求二项式系数C(n,k)。其中，n为自然数，k为不大于n的非负整数。
#include <iostream>
#include <core\core.hpp>

using namespace std;
using namespace cv;

int main()
{
   //不懂题目的意思
	Mat A = Mat::ones(2, 3, CV_8UC1);
	Mat B = Mat::ones(2, 3, CV_8UC1);

	A.at<uchar>(0, 0) = 1;
	A.at<uchar>(0, 1) = 2;
	A.at<uchar>(0, 2) = 3;
	A.at<uchar>(1, 0) = 4;
	A.at<uchar>(1, 1) = 5;
	A.at<uchar>(1, 2) = 6;

	B.at<uchar>(0, 0) = 1;
	B.at<uchar>(0, 1) = 2;
	B.at<uchar>(0, 2) = 3;
	B.at<uchar>(1, 0) = 4;
	B.at<uchar>(1, 1) = 5;
	B.at<uchar>(1, 2) = 6;

	double AB = A.dot(B);

	cout << "A=\n" << A << endl << endl;
	cout << "B=\n" << B << endl << endl;
	cout << "double类型的AB=\n" << AB << endl << endl;

	system("pause");

}