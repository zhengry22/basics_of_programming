#include<iostream>
#include<cmath>
using namespace std;

long long isprime[50000001];
long long primes[50000001];

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

bool isPrime(long long x) {//�ж�n�ǲ�������
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

bool ispalin(long long x) {
	long long store = x;
	long long tmp=0;
	while (x != 0) {
		tmp = (tmp * 10) + (x % 10);
		x /= 10;
	}
	if (tmp == store)return true;
	else return false;
}

int main() {
	long long a, b;
	cin >> a >> b;
	if (a % 2 == 0) {
		for (long long i = a + 1; i <= b; i+=2) {
			if (ispalin(i)) {
				if (isPrime(i))cout << i << endl;
			}
		}
	}
	else {
		for (long long i = a; i <= b; i+=2) {
			if (ispalin(i)) {
				if (isPrime(i))cout << i << endl;
			}
		}
	}
	return 0;
}