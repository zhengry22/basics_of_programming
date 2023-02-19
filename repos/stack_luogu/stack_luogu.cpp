#include<iostream>
using namespace std;

int result[20][20];

int main()
{
	int n;
	int sum=0;
	cin >> n;
	for (int i = 0; i < n+1; i++)
	{
		result[i][0] = 0;
		result[i][i] = 1;
	}
	for (int i = 2; i < n+1; i++)
	{
		for (int j = 1; j < i; j++)
		{
			for (int k = j - 1; k < i; k++) {
				result[i][j] += result[i - 1][k];
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		sum += result[n][i];
	}
	cout << sum;
	return 0;
}