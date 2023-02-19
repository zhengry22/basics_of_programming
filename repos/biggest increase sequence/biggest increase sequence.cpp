#include<iostream>
using namespace std;

int n,seq[1000],msl[1000]={0},greatest_length;

int max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

int max_sub_length()
{
	greatest_length =msl[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--)
	{
		int flag = 0;
		for (int j = i + 1; j <= n - 1; j++)
		{
			if (seq[i] < seq[j])
			{
				flag = 1;
				msl[i] = max(msl[j] + 1, msl[i]);
			}
			if (flag == 0)
				msl[i] = 1;
		}
		greatest_length = max(msl[i], greatest_length);
	}
	return 0;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> seq[i];
	}
	max_sub_length();
	cout<< greatest_length;
	return 0;
}