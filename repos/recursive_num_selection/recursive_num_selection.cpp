#include<iostream>
#include<cstring>
using namespace std;

int result[201][7][201];

int max(int a, int b)
{
	return a > b ? a : b;
}

int divide(int n, int k, int p)//p<=n
{
	int sum=0;
	if (result[n][k][p] != -1)
		return result[n][k][p];
	if (n==0&&k==0&&p==0)
		return 1;
	if (k == 0||n==0||p==0)
		return 0;
	else {
		for (int i = 0; i <= min(p, n - p); i++)
		{
			 result[n-p][k-1][i] = divide(n - p, k - 1, i);
			 sum += result[n - p][k - 1][i];
		}
		return sum;
	}


}

int main()
{
	memset(result, -1, sizeof(int) * 201 * 201 * 7);
	int n, k,answer=0;
	cin >> n >> k;
	for (int i = 0; i <= n; i++)
	{
		answer+=divide(n, k, i);
	}
	cout << answer;
	return 0;
}