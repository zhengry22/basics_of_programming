#include<iostream>
using namespace std;

int main()
{
	int n, *stock,buy=-1,sell=-1,sum=0;
	cin >> n;
	stock = new int[n];
	for (int i = 0; i < n; i++)
		cin >> stock[i];
	for (int i = 0; i < n; i++)
	{
		if (i == 0 && (stock[i] < stock[i + 1]))
		{
			buy = stock[i];
			continue;
		}
		else if ((i == n - 1) && (stock[i] > stock[i - 1]))
		{
			sell = stock[i];
		}
		else if((i>=1)&&(i<n-1))
		{
			//buy at the bottom
			if ((stock[i - 1] > stock[i]) && (stock[i + 1] > stock[i]))
				buy = stock[i];
			else if ((stock[i - 1] < stock[i]) && (stock[i + 1] < stock[i]))
				sell = stock[i];
		}
		if ((buy != -1) && (sell != -1))
		{
			sum = sum + (sell - buy);
			sell = buy = -1;
		}
	}
	cout << sum;
	return 0;
}