#include<iostream>
using namespace std;

int num[100000];

int divide(int max_num, int n)//
{
	int sum2 = 0, seg = 0;//, maximum = 0, flag = 0;
	for (int i = 0; i < n; i++)
	{
		if ((sum2 + num[i]) <= max_num)
		{
			sum2 = sum2 + num[i];
			if (i == n - 1)
			{
				seg++;
				//max_min2 = maximum;
				return seg;
			}
		}
		else
		{
			seg++;
			//maximum = max(maximum, sum2);
			sum2 = num[i];
			if (i == n - 1)
			{
				seg++;
				//max_min2 = maximum;
				return seg;
			}
		}
	}
}

int main()
{
	int n,m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	cin >> m;
	int a = divide(m, n);
	cout << a;
}