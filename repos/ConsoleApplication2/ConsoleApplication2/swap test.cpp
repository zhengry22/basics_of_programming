#include<iostream>
using namespace std;
int main()
{
	int m, n, k;
	cin >> n;
	//判断n的大小是否超过10000
	if (n > 10000)
	{
		cout << "n is too big!" << endl;
	}
	/*用等差数列求和公式进行判断：如果n能表示成两个及以上相邻正整数的和，则
	n=m*(m+k)/2,一共k+1个数，开始是m，结束是m+k*/
	
	else
	{
		for (k = n - 1; k >= 1; k--)
		{
			if ((2 * n) % (k + 1) == 0 && ((2 * n) / (k + 1) - k)%2==0)
			{
				m = (2 * n / (k + 1) - k) / 2;
				if (m > 0)
				{
					cout << m << ' ' << m + k << endl;
				}
			}
		}
	}
	return 0;
}