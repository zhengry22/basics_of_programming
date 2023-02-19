#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a,b[50000];
	char x = 'A';
	cin >> a;
	if (a < 2 || a>2000000000)
	{
		cout << "error";
	}
	else
	{
		
		//先把所有可能超过两个的素数筛出来，自优化
		b[0] = 2;
		int k = 1,m=0;
		for (int i = 3; (i*i)<=a; i++)
		{
			int l = 0;
			for (int j = 0; j <= k - 1; j++)
			{
				if (i % b[j] == 0)
				{
					l = 1;
					break;
				}
			}
			if (l == 0)
			{
				b[k] = i;
				k++;
			}
		}
		//先判断A/B型
		for (int i=0;i<k; i++)
		{
			if (a % (b[i]*b[i]) == 0)
			{
				x = 'B';
				break;
			}
		}
		cout << x << endl;
		
		//再进行最后的cout
		int p=0,t=a;
		for (int i = 1;; i++)
		{
			
			if (a % b[p] == 0)
			{
				a = a / b[p];
				cout << b[p] << endl;
			}
			else
			{
				p++;
			}
			if (a==1)
			{
				break;
			}
			else if (p == k && a > 1)
			{
				cout << a << endl;
				break;
			}

		}
	}
	return 0;
}
