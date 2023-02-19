#include<iostream>
using namespace std;

long long t, r;
int* n;
bool isprime[11000010];
int prime[600000];
int number=0;

/*int max(int a[], int b)
{
	int m=a[0];
	for (int i = 0; i < b-1; i++)
	{
		if (a[i + 1] >= m)
		{
			m = a[i + 1];
		}
	}
	return m;
}
*/
int main()
{
	cin >> t >> r;
	n = new(int[t]);

	for (int i = 0; i < t; i++)
	{
		cin >> n[i];
	}
	isprime[0] = false;
	isprime[1] = false;
	for (int i = 2; i <= 11000000; i++)
	{
		isprime[i] = true;
	}
	//用素数筛找出从1-max(n,t)+r的所有素数
	for (int i = 2; i<=11000000; i++)
	{
		if (isprime[i])
		{
			prime[++number] = i;
		}
		for (int j = 1; j <= number&&i*prime[j]<= 11000000; j++)
		{
			if ((i*prime[j]) > 11000000)
			{
				break;
			}
			isprime[i*prime[j]] = false;
			if (i % prime[j] == 0)
			{
				break;
			}
		}
		
	}
	//现在，所有1-max(n,t)+r的素数都被找出来了，表现为对应编号的isprime是true，其中isprime[1]=true
	for (int i = 0; i < t; i++)
	{
		int flag = 0;
		int low=0,high=number-1;
		if(n[i] > r)
		{
			while (low<=high)
			{
				int middle = (low + high) / 2;
				if ((n[i] - r) <= prime[middle] && prime[middle] <= (n[i] + r) && prime[middle] != n[i])
				{
					flag = 1;
					break;
				}
				else if (prime[middle] == n[i])
				{
					if((prime[middle+1]-prime[middle])<=r|| (prime[middle] - prime[middle-1]) <= r)
					{
						flag = 1;
					}
					break;
				}
				else if (prime[middle] > (n[i] + r))
				{
					high = middle-1;
				}
				else if (prime[middle] < (n[i] - r))
				{
					low = middle+1;
				}
			}
			if (flag == 0)
			{
				cout << 'F' << endl;
			}
			else if (flag == 1)
			{
				cout << 'T' << endl;
			}
		}
		else
		{
			cout << 'T' << endl;
		}
	}
	return 0;
}
