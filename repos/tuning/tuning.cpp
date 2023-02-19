#include<iostream>
using namespace std;

int n, beginning, maxvol, * change;
int vol_rec[1001][51];

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int max_vol(int begin, int level)//level 0 is at the root, while level n is at the leaves
{
	int tmp1, tmp2;
	if ((begin < 0) || (begin > maxvol))
		return -1;
	else//we assume that the value of begin is valid
	{
		if ((level == n))
		{
			return begin;
		}
		else
		{
			if (vol_rec[begin][level] != 0)
				return vol_rec[begin][level];
			else
			{
				if (begin - change[level] >= 0)
				{
					vol_rec[begin - change[level]][level + 1] = tmp1 = max_vol(begin - change[level], level + 1);
				}
				else
				{
					tmp1 = -1;
				}
				if (begin + change[level] <= maxvol)
				{
					vol_rec[begin + change[level]][level + 1] = tmp2 = max_vol(begin + change[level], level + 1);
				}
				else
				{
					tmp2 = -1;
				}
				return max(tmp1, tmp2);
			}
		}
	}
}

int main()
{
	int answer;
	cin >> n >> beginning >> maxvol;
	change = new int[n];
	for (int i = 0; i < n; i++)
		cin >> change[i];

	answer = max_vol(beginning, 0);
	cout << answer;
	return 0;
}