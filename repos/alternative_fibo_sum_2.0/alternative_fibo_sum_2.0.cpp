#include<iostream>
using namespace std;
#define mod 1000000007



int main() {
	long long n, small=1, big=1, sum=1;
	cin >> n;
	if (n == 1) { cout << 1; return 0; }
	for (int i = 2; i <= n; i++) {
		if (sum%mod <= big%mod) {
			sum += big;
		}
		else {
			sum -= big;
		}
		long long tmp = big;
		big += small;
		small = tmp;
		small = small % mod;
		big = big % mod;
		sum = sum % mod;
	}
	cout << sum;
	return 0;
}