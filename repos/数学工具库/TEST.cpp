#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<numeric>
#include<cstdlib>
#include<time.h>
#include"my_MATH.h"
using namespace std;

extern vector<int> primes_divide;
extern long long isprime[50000001];
extern long long primes[50000001];

void test_my_gcd() {
	genseeds();
	for (int i = 1; i <= 100000; i++) {
		int tmp1 = 1 + rand() % 2000, tmp2 = 1 + rand() % 2000, tmp3;
		if (gcd(tmp1, tmp2) != (tmp3 = my_gcd(tmp1, tmp2))) {
			cout << "error" << ' ' << tmp1 << ' ' << tmp2 << endl;
		}
		else {
			cout << tmp1 << ' ' << tmp2 << ' ' << tmp3 << endl;
		}
	}
}



void test_fast_power() {
	cout<<fast_power((long long)3, 37)<<endl;
	cout << fast_power(1.5, 2)<<endl;
	science sc_test(250, 8);
	fast_power(sc_test, 10).show();
}

void test_prime_division() {
	for (int i = 2; i <= 1000; i++) {
		prime_division(i);
		for (auto e : primes_divide) {
			cout << e << ' ';
		}
		cout << endl;
		primes_divide.clear();
	}
	cout << "over";
}

int main() {
	//test_my_gcd();
	//test_fast_power();
	test_prime_division();

	return 0;
}