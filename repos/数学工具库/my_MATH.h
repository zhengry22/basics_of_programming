#pragma once
#include<iostream>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<cstdlib>
#include<time.h>
using namespace std;

template<typename T> void my_swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

void sieve(long long n);

bool isPrime(long long x);

long long my_gcd(long long a, long long b);

long long my_lcm(long long a, long long b);

void genseeds();

void genrandnumber(int minnum, int maxnum, int num, int numperline = 10);

template<typename T>
T fast_power(T base, int expo)//快速幂：base的expo次方
{
	if (expo == 0)
		return T(1);
	else {
		if (expo % 2 == 0) {
			base = base * base, expo /= 2;
			return fast_power(base, expo);
		}
		else {
			T base_tmp = base;
			T result = fast_power(base, expo - 1) * base_tmp;
			return result;
		}
	}
}


class science {//科学计数法，base是底，expo是10的指数
private:
	long long base; //
	int exp;
public:
	science operator* (const science a)
	{
		science result;
		result.base = a.base * base;
		result.exp = a.exp + exp;
		while (result.base >= 1000000) {
			result.base /= 10;
			result.exp++;
		}
		return result;
	}

	science(const long long base, const int exp = 0) : base(base), exp(exp) {}

	science() : base(1), exp(0) {}

	void show()
	{
		cout << base << ' ' << exp << endl;
	}
};

void prime_division(long long n);

