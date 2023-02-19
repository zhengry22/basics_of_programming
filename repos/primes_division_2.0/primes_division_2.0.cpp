#include<iostream>
#include<cmath>
using namespace std;

long long isprime[50000001];
long long primes[50000001];
long long primes_divide[1001];

long long sieve(long long n) {//筛法，筛出n以内的素数，注意1是非素数，0是素数,和上面开的isprime，primes搭配使用
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

bool isPrime(long long x) {//判断n是不是素数
	int sign = true;
	if (x == 1 ||
		(x % 2 == 0 && x != 2)) sign = false;
	for (long long i = 3; i <= sqrt(x); i += 2) {
		if (x % i == 0) {
			sign = false;
			break;
		}
	}
	return sign;
}

//void prime_division(long long n) {
//	long long sign = sieve(n);
//	for (int i = 0; i < sign; i++) {
//		while (n % primes[i] == 0) {
//			n /= primes[i];
//			primes_divide.push_back(primes[i]);
//		}
//	}
//}

int main() {
	long long n; 
	cin >> n;
	long long tmp = n;
	long long place = sieve(sqrt(n)); long long flag = 0;
	for (int i = 0; i < place; i++) {
		while (tmp % primes[i] == 0) {
			tmp /= primes[i];
			primes_divide[flag] = primes[i]; flag++;
		}
	}
	if (tmp != 1) { primes_divide[flag] = tmp; flag++; } int sign = 0;
	for (int i = 0; i < flag-1; i++) {
		if (primes_divide[i] == primes_divide[i + 1])
		{
			sign = 1;
			cout << 'B' << endl; break;
		}
	}
	if (sign == 0)cout << 'A' << endl;
	for (int i = 0; i < flag; i++) {
		cout << primes_divide[i] << endl;
	}

}