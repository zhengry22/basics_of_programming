#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

long long result[1001][1001];
bool prime_sign[1001];
vector<long long> primes;//all the primes smaller than n
vector<long long> prime_below(1001);

long long min(long long a, long long b)
{
	return a > b ? b : a;
}

void isprime(int n)//在primes中列出所有比n小的素数，在prime_below中列出不大于n的素数有几个
{
	if (n <= 2)
		return;
	else {
		for (int i = 3; i <= n; i++) {
			int flag = 0;
			for (int j = 0; j < primes.size(); j++) {
				if (i % primes[j] == 0) {
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				primes.push_back(i);
				prime_sign[i] = true;
			}
				

			prime_below[i] = primes.size();
		}
	}
}

long long recursive_prime(int n, int k)
{
	long long sum = 0;
	if (n == 1||(n!=0&&k==0))
		return 0;
	else if (n == 0)
		return 1;
	else
	{
		if (result[n][k] != -1)
			return result[n][k];
		else
		{
			for (int i = 0; i <= (n / primes[k - 1]); i++)
			{
				result[n - i * primes[k - 1]][k-1]=recursive_prime(n - i * primes[k - 1], k - 1);
				sum += result[n - i * primes[k - 1]][k - 1];
			}
			result[n][k] = sum;
			return result[n][k];//prime_sign[n]&&k==prime_below[n] ? sum + 1 : sum;//考虑的是n=第k个素数的情况，如果没有取到第k个（最大的）素数，则不存在这个问题
		}

	}

}

int main()
{
	long long answer,sum = 0;
	memset(result, -1, sizeof(long long) * 1001 * 1001);
	int n;
	cin >> n;
	primes.push_back(2); prime_sign[2] = true;
	prime_below[0] = prime_below[1] = 0; prime_below[2] = 1;
	isprime(n);
	answer=recursive_prime(n, prime_below[n]);
	cout << answer;
	return 0;
}