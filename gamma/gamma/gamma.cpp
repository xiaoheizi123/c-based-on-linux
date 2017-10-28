#include<iostream>
#include<opencv2\opencv.hpp>
#include<math.h>
#include<vector>

using namespace std;
using namespace cv;

#define PI 3.14159265

void main(){
	Mat image2 = imread("D://��Ƭ//֣��.jpg");
	//gamma��ɫУ�������ʺ����۹۲��ͼƬ
	double gamma = 2.2;
	imshow("ԭͼ��", image2);
	cout << image2.rows << " " << image2.cols << endl;

	for (int i = 0; i < image2.rows; i++)
	{
		uchar *r = image2.ptr<uchar>(i);
		{
			for (int j = 0; j < image2.cols*3; j++){
				//r[j] = pow((r[j] + 0.5) / 256, (double)(1.0 / gamma));
				r[j] = (pow((r[j] + 0.5) / 256, (double)(1.0 / gamma))) * 256 - 0.5;

			}
		}

	}
	imshow("gammaУ��", image2);
    //��ɫ��һ��
	for (int i = 0; i < image2.rows; i++)
	{
		for (int j = 0; j < image2.cols; j++)
		{
			image2.at<Vec3b>(i, j)[0] = 100*image2.at<Vec3b>(i, j)[0]/(image2.at<Vec3b>(i, j)[0] + image2.at<Vec3b>(i, j)[1] + image2.at<Vec3b>(i, j)[2]);
			image2.at<Vec3b>(i, j)[1] = 100*image2.at<Vec3b>(i, j)[1]/(image2.at<Vec3b>(i, j)[0] + image2.at<Vec3b>(i, j)[1] + image2.at<Vec3b>(i, j)[2]);
			image2.at<Vec3b>(i, j)[2] = 100*image2.at<Vec3b>(i, j)[2]/(image2.at<Vec3b>(i, j)[0] + image2.at<Vec3b>(i, j)[1] + image2.at<Vec3b>(i, j)[2]);

		}
	}
	imshow("��һ��ͼ��",image2);
	//�ݶȼ���   �� ͼ����󵼾���ˮƽ���ߴ�ֱ����������������֮��Ĳ�ֵ
	Mat tempimg;
	image2.copyTo(tempimg);
	for (int i = 0; i < image2.rows; i++)
	{
		uchar *pr = image2.ptr<uchar>(i);
		for (int j = 0; j < image2.cols-1; j++)
		{
			image2.at<Vec3b>(i, j)[0] = image2.at<Vec3b>(i, j + 1)[0] - image2.at<Vec3b>(i, j)[0];
			image2.at<Vec3b>(i, j)[1] = image2.at<Vec3b>(i, j + 1)[1] - image2.at<Vec3b>(i, j)[1];
			image2.at<Vec3b>(i, j)[2] = image2.at<Vec3b>(i, j + 1)[2] - image2.at<Vec3b>(i, j)[2];
			if (j == image2.cols)
			{
				image2.at<Vec3b>(i, j)[0] = 0;
				image2.at<Vec3b>(i, j)[1] = 0;
				image2.at<Vec3b>(i, j)[2] = 0;
			}
		}
		imshow("x�����ݶ�", image2);
	}
	for (int i = 0; i < tempimg.rows-1; i++)
	{
		uchar *p = tempimg.ptr<uchar>(i);
		for (int j = 0; j < tempimg.cols; j++)
		{
			tempimg.at<Vec3b>(i, j)[0] = tempimg.at<Vec3b>(i+1, j)[0] - tempimg.at<Vec3b>(i, j)[0];
			tempimg.at<Vec3b>(i, j)[1] = tempimg.at<Vec3b>(i+1, j)[1] - tempimg.at<Vec3b>(i, j)[1];
			tempimg.at<Vec3b>(i, j)[2] = tempimg.at<Vec3b>(i+1, j)[2] - tempimg.at<Vec3b>(i, j)[2];
			if (i == tempimg.rows)
			{
				tempimg.at<Vec3b>(i, j)[0] = 0;
				tempimg.at<Vec3b>(i, j)[1] = 0;
				tempimg.at<Vec3b>(i, j)[2] = 0;
			}
		}
		
		imshow("y�����ݶ�", tempimg);
	}
	double direction;
	vector<vector<double>> save(240);
	vector<double> value(9);
	int m = 0;
    //�ں�x,y������ݶ�ֵ�ͷ��Σ�Ȼ�����ͳ��
	for (int i = 0; i < tempimg.rows; i++)
	{

		uchar *p = tempimg.ptr<uchar>(i);
		uchar *pr = image2.ptr<uchar>(i);
		save[i].resize(180);
		for (int j = 0; j < tempimg.cols - 1; j++)
		{
			tempimg.at<Vec3b>(i, j)[0] = sqrt(pow(image2.at<Vec3b>(i, j)[0], 2) + pow(tempimg.at<Vec3b>(i, j)[0], 2));
			tempimg.at<Vec3b>(i, j)[1] = sqrt(pow(image2.at<Vec3b>(i, j)[1], 2) + pow(tempimg.at<Vec3b>(i, j)[1], 2));
			tempimg.at<Vec3b>(i, j)[2] = sqrt(pow(image2.at<Vec3b>(i, j)[2], 2) + pow(tempimg.at<Vec3b>(i, j)[2], 2));

			direction = atan2f(p[j], pr[j]) * 180 / PI;
			save[i][j] = direction;

		}
		cout << direction << " ";
		imshow("�����ݶ�", image2);
	}

		for (int i = 0; i < 8; i++)
		{
			uchar *p = tempimg.ptr<uchar>(i);
			for (int j = 0; j < 8; j = j + 8)
			{
				if ((int)save[i][j] >= 0 && save[i][j]< 20) 
				{
																	value[0] = value[0]+ p[j] * (save[i][j] / 20);
																	value[1] = value[1]+ p[j] * ((20 - save[i][j]) / 20);
				}
			    if  (save[i][j] >= 20 && save[i][j] <40)
				{
																   if (save[i][j] < 30)
																   {
																	   value[1] = value[1] + p[j] * ((save[i][j] - 20) / 20);
																	   value[0] = value[0] + p[j] * (1 - (save[i][j] - 20) / 20);
																   }
																   if (save[i][j] >= 30)
																   {
																	   value[1] = value[1] + p[j] * ((40 - save[i][j]) / 20);
																	   value[2] = value[2] + p[j] * (1 - (40 - save[i][j]) / 20);
																   }
				}
				if (save[i][j] >= 40 && save[i][j] <60) 
				{
																	if (save[i][j] < 50)
																	{
																		value[2] = value[2] + p[j] * ((save[i][j] - 20) / 20);
																		value[1] = value[1] + p[j] * (1 - (save[i][j] - 20) / 20);
																	}
																	if (save[i][j] >= 50)
																	{
																		value[2] = value[2] + p[j] * ((60 - save[i][j]) / 20);
																		value[3] = value[3] + p[j] * (1 - (60 - save[i][j]) / 20);
																	}
				}
				if (save[i][j] >= 60 && save[i][j] <80)
				{
																	if (save[i][j] < 70)
																	{
																		value[3] = value[3] + p[j] * ((save[i][j] - 20) / 20);
																		value[2] = value[2] + p[j] * (1 - (save[i][j] - 20) / 20);
																	}
																	if (save[i][j] >= 70)
																	{
																		value[3] = value[3] + p[j] * ((80 - save[i][j]) / 20);
																		value[4] = value[4] + p[j] * (1 - (80 - save[i][j]) / 20);
																	}
				}

				if (save[i][j] >= 80 && save[i][j] <100)
				{
																	if (save[i][j] < 90)
																	{
																		value[4] = value[4] + p[j] * ((save[i][j] - 20) / 20);
																		value[3] = value[3] + p[j] * (1 - (save[i][j] - 20) / 20);
																	}
																	if (save[i][j] >= 90)
																	{
																		value[4] = value[4] + p[j] * ((100 - save[i][j]) / 20);
																		value[5] = value[5] + p[j] * (1 - (100 - save[i][j]) / 20);
																	}
				}
				if (save[i][j] >= 100 && save[i][j] <120)
				{
																	if (save[i][j] < 110)
																	{
																		value[5] = value[5] + p[j] * ((save[i][j] - 20) / 20);
																		value[4] = value[4] + p[j] * (1 - (save[i][j] - 20) / 20);
																	}
																	if (save[i][j] >= 50)
																	{
																		value[5] = value[5] + p[j] * ((120 - save[i][j]) / 20);
																		value[6] = value[6] + p[j] * (1 - (120 - save[i][j]) / 20);
																	}
				}
				if (save[i][j] >= 120 && save[i][j] <140)
				{
																	if (save[i][j] < 130)
																	{
																		value[6] = value[6] + p[j] * ((save[i][j] - 20) / 20);
																		value[5] = value[5] + p[j] * (1 - (save[i][j] - 20) / 20);
																	}
																	if (save[i][j] >= 130)
																	{
																		value[6] = value[6] + p[j] * ((140 - save[i][j]) / 20);
																		value[7] = value[7] + p[j] * (1 - (140 - save[i][j]) / 20);
																	}
				}

				if (save[i][j] >= 140 && save[i][j] <160)
				{
																	if (save[i][j] < 150)
																	{
																		value[7] = value[7] + p[j] * ((save[i][j] - 20) / 20);
																		value[6] = value[6] + p[j] * (1 - (save[i][j] - 20) / 20);
																	}
																	if (save[i][j] >= 150)
																	{
																		value[7] = value[7] + p[j] * ((160 - save[i][j]) / 20);
																		value[8] = value[8] + p[j] * (1 - (160 - save[i][j]) / 20);
																	}
				}
				if (save[i][j] >= 160 && save[i][j] <180)
				{
																	if (save[i][j] < 170)
																	{
																		value[8] = value[8] + p[j] * ((save[i][j] - 20) / 20);
																		value[7] = value[7] + p[j] * (1 - (save[i][j] - 20) / 20);
																	}
																	if (save[i][j] >= 170)
																	{
																		value[8] = value[8] + p[j] * ((180 - save[i][j]) / 20);
																		value[0] = value[0] + p[j] * (1 - (180 - save[i][j]) / 20);
																	}
				}
				
				
				cout << "�Ÿ������Ӧ��Ȩ��ֵ" <<" " << value[0] << " " << value[1] << " " << value[2] << " " << value[3] << " " << value[4] << " " << value[5] << " " << value[6] << " " << value[7] << " " << value[8] << endl;
			}
		}
	waitKey(30000);

}