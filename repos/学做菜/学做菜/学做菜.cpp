#include<iostream>
using namespace std;

int a, b, c, d;
int x[5];

int main()
{
	cin >> a >> b >> c >> d;
	for (int i = 1;; i++)
	{
		if (a >= 2 && b >= 1 && d >= 2)
		{
			a = a - 2;
			b = b - 1;
			d = d - 2;
			x[0]++;
		}
		else
		{
			break;
		}
	}
	for (int i = 1;; i++)
	{
		if (a >= 1 && b >= 1 && d >= 1&&c>=1)
		{
			a--;
			b--;
			c--;
			d--;
			x[1]++;
		}
		else
		{
			break;
		}
	}
	for (int i = 1;; i++)
	{
		if (c>=2 && d >= 1)
		{
			c = c - 2;
			d--;
			x[2]++;
		}
		else
		{
			break;
		}
	}
	for (int i = 1;; i++)
	{
		if (b>=3)
		{
			b = b - 3;
			x[3]++;
		}
		else
		{
			break;
		}
	}
	for (int i = 1;; i++)
	{
		if (a>=1&&d>=1)
		{
			a--;
			d--;
			x[4]++;
		}
		else
		{
			break;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		cout << x[i] << endl;
	}
	return 0;
}