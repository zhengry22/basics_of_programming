#include<iostream>
using namespace std;

long long seq[100001] = { 0 }, ms[100000] = { 0 };
int n;

long long max(long a, long b)
{
	if (a >= b)
		return a;
	else
		return b;
}

int select_max(int ed, int st)//ed=n or n-1
{
	if ((st == ed - 2) || (st == ed - 1))
		return seq[st];
	else if (st == ed - 3)
		return seq[st] + seq[st + 2];
	else
	{
		if (ms[st] > 0)
			return ms[st];
		else
		{
			ms[st + 2] = select_max(ed,st + 2);
			ms[st + 3] = select_max(ed,st + 3);
			return max(ms[st + 2], ms[st + 3]) + seq[st];
		}
	}
}

int main()
{
	long long s0=0, s1, s2;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> seq[i];
	}
	s1 = select_max(n, 1);
	s2 = select_max(n, 2);
	memset(ms, 0, sizeof(int) * 100000);
	s0 = select_max(n - 1,0);
	cout << max(max(s0, s1), s2);
	return 0;
}