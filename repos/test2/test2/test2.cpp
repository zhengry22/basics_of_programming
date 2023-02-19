#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<numeric>
#include<cstdlib>
#include<time.h>
using namespace std;

long long isprime[50000001];
long long primes[50000001];
vector<int> primes_divide;

long long sieve(long long n) {//ɸ����ɸ��n���ڵ�������ע��1�Ƿ�������0������,�����濪��isprime��primes����ʹ��
	long long flag = 0;
	isprime[1] = 1;
	for (int i = 2; i * i <= n; i++) {
		if (isprime[i] == 0) {
			for (int j = i * i; j <= n; j += i) {
				isprime[j] = 1;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (isprime[i] == 0) {
			primes[flag] = i;
			flag++;
		}
	}
	return flag;
}

void prime_division(long long n) {
	long long sign = sieve(n);
	for (int i = 0; i < sign; i++) {
		while (n % primes[i] == 0) {
			n /= primes[i];
			primes_divide.push_back(primes[i]);
		}
	}
	memset(primes, 0, sizeof(int) * n+1);
}

int main() {
	
	return 0;
}