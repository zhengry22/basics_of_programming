#include<iostream>
using namespace std;

long long n,seq[100001]={0}, seq2[100001]={0}, ms[100000]={0}, ms2[100000]={0};
long long max(long a, long b)
{
	if (a >= b)
		return a;
	else
		return b;
}

//iterative 
long long max_sum(long long* seq, long long* ms, int place)//the largest sum staring from seq[place]
{
	ms[n - 1] = seq[n - 1];
	ms[n - 2] = seq[n - 2];
	for (int i = n - 3; i >= place; i--)
	{
		ms[i] = max(ms[i + 2], ms[i + 3]) + seq[i];
	}	
	return ms[place];
}

int main()
{
	long long s0, s1, s2;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> seq[i];
		seq2[i] = seq[i];
	}
	seq2[n - 1] = 0;
	s0 = max_sum(seq2, ms2, 0);
	s1 = max_sum(seq, ms, 1);
	cout << max(max(s0, s1), ms[2]);
	return 0;
}