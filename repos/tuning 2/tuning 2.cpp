#include<iostream>
using namespace std;

int n, beginning, maxvol, * change;
bool vol_rec[51][1001];

int main()
{
	cin >> n >> beginning >> maxvol;
	change = new int[n];
	for (int i = 0; i < n; i++)
		cin >> change[i];

	vol_rec[0][beginning] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= 1000; j++)
		{
			if (vol_rec[i][j] != 0)
			{
				if (j - change[i] >= 0)
				{
					vol_rec[i + 1][j - change[i]] = 1;
				}
				if (j + change[i] <= maxvol)
				{
					vol_rec[i + 1][j + change[i]] = 1;
				}
			}
		}
	}
	int flag = 0;
	for (int i = maxvol; i >= 0; i--)
	{
		if (vol_rec[n][i] != 0)
		{
			flag = 1;
			cout << i;
			break;
		}
	}
	if (flag == 0)
		cout << -1;

	return 0;
}