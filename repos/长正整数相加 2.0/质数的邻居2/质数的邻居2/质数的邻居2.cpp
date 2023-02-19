#include<iostream>
using namespace std;

int t, r;
int* n;
bool* isprime;

int main()
{
	cin >> t >> r;
	n = new(int[t]);
	
	for (int i = 0; i < t; i++)
	{
		cin >> n[i];
	}
	
	
	for (int i = 0; i < t; i++)
	{
		int flag = 0;
		isprime = new(bool[2 * r + 1]);
		for (int j = 0; j < (2 * r + 1); j++)
		{
			isprime[j] = 1;
		}
		if (n[i] > r)
		{
			for (int j = -r; j <= r; j++)
			{
				for (int k = 2; k * k <= n[i] + j; k++)
				{
					if ((n[i] + j) % k == 0)
					{
						isprime[j + r] = 0;
						break;
					}
				}
			}
			for (int j = -r; j <= r; j++)
			{
				if (isprime[r + j] && j != 0)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				cout << 'F' << endl;
			}
			if (flag == 1)
			{
				cout << 'T' << endl;
			}
			delete isprime;
		}
		else
		{
			for (int j = 2; j <= n[i]+r; j++)
			{
				for (int k = 2; k * k <= n[i] + j; k++)
				{
					if ((n[i] + j) % k == 0)
					{
						isprime[j + r] = 0;
						break;
					}
				}
			}
			for (int j = -r; j <= r; j++)
			{
				if (isprime[r + j] && j != 0)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				cout << 'F' << endl;
			}
			if (flag == 1)
			{
				cout << 'T' << endl;
			}
			delete isprime;
		}
	}
	return 0;
}