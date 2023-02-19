#include<iostream>
#include<string.h>
using namespace std;

int n, sum[1001], stone[1000], stone_g[1000][1000];

int max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

int min(int a, int b)
{
	if (a >= b)
		return b;
	else
		return a;
}

int stone_gather(int st, int ed)
{
	int sum2=0, min_price = 100000000;
	if (st == ed)
		return 0;
	else
	{
		sum2 = sum[ed + 1] - sum[st];
		if (stone_g[st][ed] >= 0)
			return stone_g[st][ed];
		else
		{
			for (int i = st + 1; i <= ed; i++)
			{
				stone_g[st][i - 1] = stone_gather(st, i - 1);
				stone_g[i][ed] = stone_gather(i, ed);
				min_price = min(min_price, sum2 + stone_g[st][i - 1] + stone_g[i][ed]);
			}
			return min_price;
		}
	}
}

int main()
{
	int answer;
	memset(stone_g, -1, sizeof(int) * 1000000);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> stone[i];
	//sum
	sum[0] = 0;
	for (int i = 1; i < 1001; i++)
	{
		sum[i] = sum[i - 1] + stone[i - 1];
	}
	answer = stone_gather(0, n - 1);
	cout << answer<<endl;
	//print every single status
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << stone_g[i][j]<<" ";
		}
		cout << endl;
	}
	return 0;
}

