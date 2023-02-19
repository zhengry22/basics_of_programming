#include<iostream>
using namespace std;

int sign(int a)
{
	if (a % 2 == 0)
		return 1;
	else
		return -1;
}

int det(int** a, int n)//row,col ��������ֱ��ʾ��������Щ�У�����Ҫ������������
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
			//���Ȱ�Ҫ������Ӿ�����mtx�����ļ����ļ��з���row��col��
			int place = 0, place2 = 0;
			//�ȷ���,��ÿһ��ѭ���ﶼ����Ҫ���еı���ó���
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
			//�ٷ��У��бȽϺ�Ū
			for (int j = 1; j < n; j++)
			{
				col2[place2] = j;
				place2++;
			}
			//�Ӿ���������,����mtx2��
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
	//����mtx�����ά���������������
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mtx[i][j];
		}
	}
	//�ٵ���det������������
	int a;
	a = det(mtx, n);
	cout << a;
	return 0;
}