#include<iostream>
using namespace std;
int main()
{
	int a[10],n;
	cin >> n;//n<=10
	if (n > 10)
	{
		cout << "n is too big" << endl;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			a[i] = i*i;
		}
		int x = (1 << n) - 1;
		int k = 1;
		for (int i = 0; i <= x; i++)
		{
			int q = i;
			for (int j = 1; j <= n; j++)
			{
				if ((q & 1) == 1)
				{
					cout << a[j - 1]<<' ';
				}
				q = q >> 1;
			}
			cout << endl;
		}
	}
	return 0;
}