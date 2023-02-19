#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

long long result[1001][1001];
vector<long long> primes;//all the primes smaller than n
vector<long long> prime_below(1001);

long long min(long long a, long long b)
{
	return a > b ? b : a;
}

void isprime(int n)
{
	if (n <= 2)
		return;
	else {
		for (int i = 3; i <= n; i++){
			int flag = 0;
			for (int j = 0; j < primes.size(); j++){
				if (i % primes[j] == 0){
					flag = 1;
					break;
				}
			}
			if (flag == 0)
				primes.push_back(i);

			prime_below[i] = primes.size();
		}
	}
}


int main()
{
	long long sum = 0;
	memset(result, 0, sizeof(int) * 1001 * 1001);
	int n;
	cin >> n;
	primes.push_back(2);
	prime_below[0] = prime_below[1] = 0; prime_below[2] = 1;
	isprime(n);
	for (int i = 2; i <= n; i++)//each prime number
	{
		for (int j = 1; j <= prime_below[i]; j++)//how many primes below each one
		{
			if (i == primes[j - 1])
				result[i][j] = 1;
			else {
				for (int k = 1; k <= min(prime_below[i - primes[j-1]],prime_below[primes[j-1]]); k++)//选的数应当是比最大的素数要小，同时也要小于取出的素数
				{
					result[i][j] += result[i - primes[j-1]][k];
				}
			}
		}
	}
	for (int i = 1; i <= prime_below[n]; i++)
	{
		sum += result[n][i];
	}
	cout << sum;
	return 0;
}
//如果发现没过的点用的时间比较长，表明数据规模较大，可能是由于数据类型的原因，尝试把数据类型从int换成long long