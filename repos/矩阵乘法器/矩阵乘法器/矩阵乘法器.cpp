#include<iostream>
using namespace std;

int main()
{
	float a[10][10], b[10][10],c[10][10];
	int r,s,p,q;
	cout << "enter the row and column of matrix 1" << endl;
	cin >> r >> s;
	cout << "enter the row and column of matrix 2" << endl;
	cin >> p >> q;
	if (s != p||(r>10)+(s>10)+(p>10)+(q>10)>=1)
	{
		cout << "error";
	}
	else
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < s; j++)
			{
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < p; i++)
		{
			for (int j = 0; j < q; j++)
			{
				cin >> b[i][j];
			}
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < q; j++)//先确定要计算的每一个矩阵的元素在什么位置
			{
				c[i][j] = 0;
				for (int l = 0; l < s; l++)
				{
					c[i][j] = c[i][j] + ((a[i][l]) * (b[l][j]));
				}
			}
		}
		for (int i = 0; i < r; i++)
		{
			cout << endl;
			for (int j = 0; j < q; j++)
			{
				cout << c[i][j]<<' ';
			}
		}
	}
	return 0;
}

