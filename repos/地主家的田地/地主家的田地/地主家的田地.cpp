#include<iostream>
using namespace std;

int a[101][101],aa[101][101];

int max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

int sum(int a, int b,int e[101][101])
{
	int x = 0;
	for (int i = 0; i <= a; i++)
	{
		for (int j = 0; j <= b; j++)
		{
			x = x + e[i][j];
		}
	}
	aa[a][b] = x;
	return x;
}


int main()
{
	int n,m;
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			getchar();
		}
	}
	int x, y;
	y = a[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

			for (int k = i; k < n; k++)
			{
				for (int l = j; l < m; l++)
				{
					if (i == 0 && j == 0)
					{
						x=aa[k][l] = sum(k, l, a);
					}
					else if (i == 0 && j != 0)
					{
						x = aa[k][l] - aa[k][j - 1];
					}
					else if (i != 0 && j == 0)
					{
						x = aa[k][l] - aa[i - 1][l];
					}
					else if (i != 0 && j != 0)
					{
						x = aa[k][l] - aa[k][j - 1] - aa[i - 1][l] + aa[i - 1][j - 1];
					}
					y = max(x, y);
				}
			}
		}
	}
	cout << y << endl;
	return 0;
}
/*
			int x, y;
			x = 0;
			y = a[i][j];*/
			/*
								x = sum(i, j, k, l, a);
								y = max(x,y);*/