#include<iostream>
using namespace std;

int actvt[50010];
int sum[50010];
int sundays[50000];
int n, k, saturday, sunday;

int minimum(int a, int b)
{
	if (a <= b)
		return a;
	else
		return b;
}

int sat_sunday_actvt()
{
	int sun_current, s;
	saturday = n - 2 * k, sunday = n - k, s=sum[n-2*k]+sum[n-k];
	sun_current = sunday;
	for (int i = n - 2 * k - 1; i >= 0; i--)
	{
		if (sum[i] <= sum[i + 1])
		//the smallest should be either i, k+1 or i, sun_current
		{
			if (sum[i] + sum[k + i] <= sum[i] + sum[sun_current])
			{
				sun_current = k + i;
				if (sum[i] + sum[k + i] <= s)
				{
					s = sum[i] + sum[k + i];
					saturday = i, sunday = sun_current;
				}
			}
			else
			{
				if (sum[i] + sum[sun_current] <= s)
				{
					s = sum[i] + sum[sun_current];
					saturday = i, sunday = sun_current;
				}
			}
		}
		//else the smallest should be either i+1, sun_current or i, k+i
		else
		{
			if (sum[i] + sum[k + i] <= sum[i + 1] + sum[sun_current])
			{
				if (sum[i] + sum[k + i] <= s)
				{
					s = sum[i] + sum[k + i];
					saturday = i, sunday = k + i;
				}		
			}
			else
			{
				if (sum[i + 1] + sum[sun_current] <= s)
				{
					s = sum[i + 1] + sum[sun_current];
					saturday = i + 1, sunday = sun_current;
				}
			}

			if (sum[i] + sum[k + i] <= sum[i] + sum[sun_current])
			{
				sun_current = k + i;
			}
		}
	}
	return 0;
}

int main()
{
	
	cin >> n >> k;
	int s = 0;
	for (int i = 0; i < n; i++)
		cin >> actvt[i];
	for (int i = 0; i < k; i++)
	{
		s=s+actvt[i];
	}
	sum[0] = s;
	for (int i = 1; i <= n - k; i++)
	{
		s = s + actvt[k - 1 + i] - actvt[i - 1];
		sum[i] = s;
	}
	sat_sunday_actvt();
	
	cout << saturday+1 << ' ' << sunday+1;
	return 0;
}

