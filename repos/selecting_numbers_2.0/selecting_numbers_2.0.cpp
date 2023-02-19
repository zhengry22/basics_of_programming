#include<iostream>
using namespace std;

long long datastore[100000], numbers[100000], datastore2[100000];

long long max(long long a, long long b) {
	return a > b ? a : b;
}



int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> numbers[i];
	}
	if (n <= 3) {
		long long m = 0;
		for (int i = 1; i <= n; i++) {
			m = numbers[i] >= m ? numbers[i] : m;
		}
		cout << m;
		return 0;
	}
	datastore[1] = numbers[1], datastore[2] = numbers[2]; datastore[3] = numbers[1] + numbers[3];
	for (int i = 4; i <= n - 1; i++) {
		datastore[i] = numbers[i] + max(datastore[i-2], datastore[i - 3]);
	}
	datastore2[2] = numbers[2], datastore2[3] = numbers[3]; datastore2[4] = numbers[2] + numbers[4];
	for (int i = 5; i <= n; i++) {
		datastore2[i] = numbers[i] + max(datastore2[i - 2], datastore2[i - 3]);
	}
	datastore[n] = datastore2[n];
	long long maximum = 0;
	for (int i = 1; i <= n; i++) {
		maximum = maximum > datastore[i] ? maximum : datastore[i];
	}
	cout << maximum;
	return 0;
	
}//long long!!! long long!!! long long!!!