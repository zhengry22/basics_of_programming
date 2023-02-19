#include<iostream>
using namespace std;

int main()
{
	int l, r, n;
	n = 0;
	cin >> l;
	cin >> r;
	if (l < 1 || r>10000 || l > r)
	{
		cout << "input is invalid";
	}
	else
	{
		for (int i = l; i <= r; i++)
		{
			int k = i;
			for (int j = 1; j <= 5; j++)
			{
				if (k % 10 == 2)
				{
					n = n + 1;
				}
				k = k / 10;
				if (k == 0)
				{
					break;
				}
			}
				
		}
		cout << n << endl;
	}
	return 0;
}