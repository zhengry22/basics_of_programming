#include<iostream>
using namespace std;

long long inputs[10001];
long long isprime[15000000];
long long primes[11000000]; 
long long size_p = 0;	long long t, radius;

long long max(long long a, long long b) {
	return a > b ? a : b;
}

bool in_left(long long a, long long input) {
	if (a >= max(1, input - radius) && a <= input - 1)return true;
	else return false;
}

bool in_right(long long a, long long input) {
	if (a >= input + 1 && a <= input + radius)return true;
	else return false;
}

bool search_left(long long* num, long long l, long long r, long long input)
{
	while ((l < r) && (!in_left(num[l],input)) && (!in_left(num[r], input)))
	{
		long long mid = (l + r) / 2;
		if (input - 1 < num[mid])
		{
			r = mid;
		}
		else if (input - radius > num[mid])
		{
			l = mid + 1;
		}
		else return true;
	}
	if (in_left(num[l], input))
		return true;
	if (in_left(num[r], input))
		return true;
	if (l == r)
		return false;
}


bool search_right(long long* num, long long l, long long r, long long input) 
{
	while ((l < r) && (!in_right(num[l], input)) && (!in_right(num[r], input)))
	{
		long long mid = (l + r) / 2;
		if (input + radius < num[mid])
		{
			r = mid;
		}
		else if (input + 1 > num[mid])
		{
			l = mid + 1;
		}
		else return true;
	}
	if (in_right(num[l], input))
		return true;
	if (in_right(num[r], input))
		return true;
	if (l == r)
		return false;
}

void sieve(long long n) {//筛法，筛出n以内的素数，注意1是非素数，0是素数
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
			primes[size_p] = i;
			size_p++;
		}
	}
}

int main() {
	cin >> t >> radius;
	for (int i = 1; i <= t; i++) {
		cin >> inputs[i];
	}
	long long maxx = 0;
	for (int j = 1; j <= t; j++) {
		maxx = maxx > inputs[j] ? maxx : inputs[j];
	}
	sieve(maxx + radius);
	for (int i = 1; i <= t; i++) {
		if ((search_left(primes, 0, size_p - 1, inputs[i]))||(search_right(primes, 0, size_p - 1, inputs[i]))) { cout << 'T' << endl; }
		else { cout << 'F' << endl; }
	}
	return 0;
}