#include<iostream>
using namespace std;

int sign(int a)
{
	if (a % 2 == 0)
		return 1;
	else
		return -1;
}

int det(int** a, int n)//row,col 两个数组分别表示的是有哪些行，列是要参与矩阵运算的
{
	int row2[6], col2[6];
	int sum = 0;
	if (n == 1)
		return **a;
	else
	{
		for (int i = 0; i < n; i++)
		{
			int** mtx2;
			mtx2 = new int* [6];
			for (int j = 0; j < 6; j++)
				mtx2[j] = new int[6];
			//首先把要计算的子矩阵在mtx中是哪几行哪几列放入row，col里
			int place = 0, place2 = 0;
			//先放行,在每一次循环里都把需要的行的标号拿出来
			for (int j = 0; j < n; j++)
			{
				if (j == i)
					continue;
				else
				{
					row2[place] = i;
					place++;
				}
			}
			//再放列，列比较好弄
			for (int j = 1; j < n; j++)
			{
				col2[place2] = j;
				place2++;
			}
			//从矩阵中拿数,放入mtx2中
			for (int j = 0; j < n - 1; j++)
			{
				for (int k = 0; k < n - 1; k++)
				{
					mtx2[j][k] = a[row2[j]][col2[k]];
				}
			}
			sum = sum + sign(i) * (a[i][0]) * det(mtx2, n - 1);
		}
	}
	return sum;
}

int main()
{
	int** mtx;
	mtx = new int* [6];
	for (int i = 0; i < 6; i++)
		mtx[i] = new int[6];
	int n;
	cin >> n;
	//先向mtx这个二维数组里放入矩阵的数
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mtx[i][j];
		}
	}
	//再调用det函数进行运算
	int a;
	a = det(mtx, n);
	cout << a;
	return 0;
}