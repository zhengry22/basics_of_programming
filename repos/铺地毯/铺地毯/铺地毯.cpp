#include<iostream>
using namespace std;

int n;
int* a, * b, *g, * k;
int x, y;
int m = 0;

int main()
{
	//先输入数据
	cin >> n;
	a = new(int[n]);
	b = new(int[n]);
	g = new(int[n]);
	k = new(int[n]);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i] >> g[i] >> k[i];
	}
	cin >> x >> y;
	//再从第n张地毯一张张往下数
	for (int i = n - 1; i >= 0; i--)
	{
		if (x >= a[i] && x <= (a[i] + g[i]) && y >= b[i] && y <= (b[i] + k[i]))
		{
			m = 1;
			cout << i + 1;
			break;
		}
	}
	if (m == 0)
	{
		cout << -1;
	}
	delete a;
	delete b;
	delete g;
	delete k;
	return 0;
}