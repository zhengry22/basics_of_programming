#include<iostream>
#include<cmath>
using namespace std;

int p[100000];

bool palin(int a)
{
	int m=0;
	int b = a;
	for (int i = 1;;i++)
	{
		if (a == 0)
		{
			break;
		}
		m = (10 * m) + (a % 10);
		a = a / 10;
	}
	if (b == m)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int a, b;
	cin >> a;
	getchar();
	cin >> b;
	if (a > b)
	{
		cout << "error";
	}
	else
	{
		int k = 0;
		if (a % 2 == 0)
		{
			a = a + 1;
		}
		for (int i = a; i <= b; i=i+2)
		{
			if (palin(i) == 1)
			{
				p[k] = i;
				k++;
			}
		}
		for (int i = 0; i < k; i++)
		{
			int l = 0;
			for (int j = 2; j <= sqrt(p[i]); j++)
			{
				if ((p[i] % j) == 0)
				{
					l = 1;
					break;
				}
			}
			if (l == 0)
			{
				cout << p[i] << endl;
			}
		}
	}
	return 0;
}