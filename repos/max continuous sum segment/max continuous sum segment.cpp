#include<iostream>
using namespace std;

int n;
int seq[50000];
int record[50000];
bool rec[50000]={0};

int max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

int sum_max(int st)
{
	int a;
	if (st == n - 1)
		return seq[n - 1];
	else
	{	//more space for less time
		if (rec[st])
			return record[st];
		else 
		{
			record[st + 1] = sum_max(st + 1);
			rec[st + 1] = 1;
			return max(record[st + 1] + seq[st], seq[st]);
		}
	}	
}

int answer()
{
	int maximum = seq[n - 1];
	for (int i = 0; i < n-1; i++)
	{
		if (seq[i] <= 0)
			continue;
		maximum = max(sum_max(i), maximum);
	}
	return maximum;
}

int main()
{
	int ans;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> seq[i];
	ans = answer();
	cout << ans;
	return 0;
}